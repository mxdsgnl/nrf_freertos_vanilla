#ifndef INC_BOARD_H_
#define INC_BOARD_H_

#include <stdint.h>
#include <string.h>
#include "sdk_config.h"
#include "nordic_common.h"
#include "nrf.h"
#include "boards.h"
#include "nrf_pwr_mgmt.h"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"
#include "nrf_delay.h"
#include "app_timer.h"
#include "app_button.h"
#include "app_error.h"
#include "nrfx_gpiote.h"
#include "uart.h"
#if defined (UART_PRESENT)
#include "nrf_uart.h"
#endif
#if defined (UARTE_PRESENT)
#include "nrf_uarte.h"
#endif
#include "nrf_drv_uart.h"

// some values come from DBOARD_PCA10056 in the SDK
// rather than hassling with a formal BSP, we just override them

#define LED0                            NRF_GPIO_PIN_MAP(0,13)
#define LED1                            NRF_GPIO_PIN_MAP(0,14)
// #define LED2                            NRF_GPIO_PIN_MAP(0,15)
// #define LED3                            NRF_GPIO_PIN_MAP(0,16)
#define IIC_SCL_PIN                     NRF_GPIO_PIN_MAP(0,0)
#define IIC_SDA_PIN                     NRF_GPIO_PIN_MAP(0,1)
#define PN532_IRQ_PIN                   NRF_GPIO_PIN_MAP(0,2)

#define DEAD_BEEF                       0xDEADBEEF                              /**< Value used as error code on stack dump, can be used to identify stack location on stack unwind. */

#define UART_SUMMARY_LOGGING            ( 0 )
#define UART_STREAM_LOGGING             ( 1 )
#define ADC_DISABLED                    ( 0 )

#define KEEP_RUNNING                    ( 0 )
#define DEBUG_PIN_ENABLED               ( 0 )

void led_on(uint32_t led_idx);
void led_off(uint32_t led_idx);
void led_toggle(uint32_t led_idx);
void led_write(uint8_t led_state);

void board_init();
void debug_pin(int count);


#endif
