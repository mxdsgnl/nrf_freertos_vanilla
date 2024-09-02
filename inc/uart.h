#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include <stdbool.h>

#include "app_uart.h"

typedef enum {
    dicke_pkt        = 0x00,
    telem_pkt 		 = 0x10,
    surface_pkt      = 0x20,
    log_pkt          = 0x80
} la_packet_type_t;

#define TELEM_VOLTAGE		( 0 )
#define TELEM_CURRENT		( 1 )
#define TELEM_THERMO_CH0	( 2 )
#define TELEM_THERMO_CH1	( 3 )
#define TELEM_THERMO_CH2	( 4 )
#define TELEM_THERMO_CH3	( 5 )

void fast_print_16(char *s, uint16_t v);
void fast_print_32(char *s, uint32_t v);
//static void uart_put_blocking(uint8_t b);
void uart_put_uint8(uint8_t b);
void uart_put_uint16(uint16_t i);void _uart_put_string(char *s);
void uart_put_string(char *s);
void _uart_put_string(char *s);
void DebugPrint(char *str, ...);

void send_la_packet(uint8_t type, uint16_t len, uint8_t *p_data);
bool uart_is_busy(void);
void uart_init(app_uart_comm_params_t *p_dev);

const char *dickeString(int n);

#endif // UART_H_

