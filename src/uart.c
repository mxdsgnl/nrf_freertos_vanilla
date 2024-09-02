#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdarg.h>

#include "nrf_delay.h"
#include "uart.h"
#include <string.h>

void fast_print_16(char *s, uint16_t v) {
    const char *hex = "0123456789abcdef";
    s[0] = hex[ (v >> 12) & 0xf ];
    s[1] = hex[ (v >> 8)  & 0xf ];
    s[2] = hex[ (v >> 4)  & 0xf ];
    s[3] = hex[ (v >> 0)  & 0xf ];
}

void fast_print_32(char *s, uint32_t v) {
    fast_print_16( &s[0], (v>>16)&0xffff );
    fast_print_16( &s[4], v&0xffff );
}

static volatile bool uart_tx_empty = true;

bool uart_is_busy(void) {
    return !uart_tx_empty;
}

static void uart_put_blocking(uint8_t b) {
    for (int i=0; i<1000/*1ms*/; i++) {
        uint32_t err_code = app_uart_put( b );
        if ( err_code == NRF_SUCCESS ) {
            return;
        } else {
            // fifo must be full, keep trying
            nrf_delay_us( 1 );
        }
    }
    // timeout!
}

void uart_put_uint8(uint8_t b) {
    uart_tx_empty = false;
    uart_put_blocking( b );
}

void uart_put_uint16(uint16_t i) {
	uart_tx_empty = false;
    uint8_t b = i & 0xff;
    uart_put_blocking( b );
    b = i >> 8;
    uart_put_blocking( b );
}

void _uart_put_string(char *s) {
    for (int i=0; i<strlen(s); i++) {
        uart_tx_empty = false;
        uint8_t b = s[i];
        uart_put_blocking( b );
    }
}

void uart_put_string(char *s) {
    _uart_put_string( "LA" ); // header id
    _uart_put_string( s ); // message
}

void DebugPrint(char *str, ...) {
	va_list va;
	va_start(va, str);
	vprintf(str, va);
	va_end(va);
}

/*
 * @brief	Send uart data packet, for use with python application
 *
 * @param[in]	type	packet type, la_packet_type_t
 * @param[in]	len		length of data in bytes
 * @param[in]	p_data	pointer to data buffer
 */
void send_la_packet(uint8_t type, uint16_t len, uint8_t *p_data) {
    _uart_put_string( "LA" ); // header id
    uart_put_uint8( type );
    uart_put_uint16( len  ); // length in bytes
    for ( int i=0; i<len; i++ ) {
        uart_put_uint8( p_data[i] );
    }
}

void uart_event_handle(app_uart_evt_t * p_event)
{
      switch (p_event->evt_type) {
        case APP_UART_COMMUNICATION_ERROR:
            app_uart_flush(); // clear the error
            break;

        case APP_UART_FIFO_ERROR:
            app_uart_flush(); // clear the error
            break;

        case APP_UART_DATA_READY:
            break;

        case APP_UART_TX_EMPTY:
            uart_tx_empty = true;
            break;

        default:
            break;
    }
}



void uart_init(app_uart_comm_params_t *p_dev) {
    uint32_t err_code;

    // there are two uart drivers supplied by nordic.
    // one has a software fifo (in addition to the hardware fifo)
    // generally they're interchangable but also require a change to the makefile
    // libraries/uart/app_uart.c, fifo/app_fifo.c, app_uart_fifo.c
    APP_UART_FIFO_INIT(p_dev, 1024, 1024, uart_event_handle, APP_IRQ_PRIORITY_HIGHEST, err_code);
    // APP_UART_INIT(&comm_params,
    //                  uart_event_handle,
    //                  APP_IRQ_PRIORITY_HIGHEST/*APP_IRQ_PRIORITY_LOWEST*/,
    //                  err_code);

    APP_ERROR_CHECK(err_code);
}


//const char *dickeString(int n) {
//    switch( n ) {
//        case dicke_rf1: return "rf1";
//        case dicke_rf2: return "rf2";
//        case dicke_rf3: return "rf3";
//        case dicke_rf4: return "rf4";
//        case dicke_50:  return " 50";
//        default: return "?";
//    }
//}


