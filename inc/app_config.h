
#ifndef APP_CONFIG_H_
#define APP_CONFIG_H_

// #ifndef NRFX_UARTE_ENABLED
// #define NRFX_UARTE_ENABLED 1
// #endif
// // <q> NRFX_UARTE0_ENABLED - Enable UARTE0 instance
// #ifndef NRFX_UARTE0_ENABLED
// #define NRFX_UARTE0_ENABLED 1
// #endif

// // <q> NRFX_UARTE1_ENABLED - Enable UARTE1 instance
// #ifndef NRFX_UARTE1_ENABLED
// #define NRFX_UARTE1_ENABLED 1
// #endif

// #ifndef UART_ENABLED
// #define UART_ENABLED 1
// #endif

// #ifndef UART0_ENABLED
// #define UART0_ENABLED 1
// #endif
// // <o> NRFX_UARTE_DEFAULT_CONFIG_HWFC  - Hardware Flow Control

// // <0=> Disabled
// // <1=> Enabled

// #ifndef NRFX_UARTE_DEFAULT_CONFIG_HWFC
// #define NRFX_UARTE_DEFAULT_CONFIG_HWFC 0
// #endif

// // <o> NRFX_UARTE_DEFAULT_CONFIG_PARITY  - Parity

// // <0=> Excluded
// // <14=> Included

// #ifndef NRFX_UARTE_DEFAULT_CONFIG_PARITY
// #define NRFX_UARTE_DEFAULT_CONFIG_PARITY 0
// #endif

// // <o> NRFX_UARTE_DEFAULT_CONFIG_BAUDRATE  - Default Baudrate

// // <323584=> 1200 baud
// // <643072=> 2400 baud
// // <1290240=> 4800 baud
// // <2576384=> 9600 baud
// // <3862528=> 14400 baud
// // <5152768=> 19200 baud
// // <7716864=> 28800 baud
// // <8388608=> 31250 baud
// // <10289152=> 38400 baud
// // <15007744=> 56000 baud
// // <15400960=> 57600 baud
// // <20615168=> 76800 baud
// // <30801920=> 115200 baud
// // <61865984=> 230400 baud
// // <67108864=> 250000 baud
// // <121634816=> 460800 baud
// // <251658240=> 921600 baud
// // <268435456=> 1000000 baud

// #ifndef NRFX_UARTE_DEFAULT_CONFIG_BAUDRATE
// #define NRFX_UARTE_DEFAULT_CONFIG_BAUDRATE 30801920
// #endif

// // <o> NRFX_UARTE_DEFAULT_CONFIG_IRQ_PRIORITY  - Interrupt priority

// // <0=> 0 (highest)
// // <1=> 1
// // <2=> 2
// // <3=> 3
// // <4=> 4
// // <5=> 5
// // <6=> 6
// // <7=> 7

// #ifndef NRFX_UARTE_DEFAULT_CONFIG_IRQ_PRIORITY
// #define NRFX_UARTE_DEFAULT_CONFIG_IRQ_PRIORITY 7
// #endif


// ^^^^^^^^ ORIGINAL UART CONFIG
/*******************************************************************************
 * UART
 ******************************************************************************/
// <e> NRFX_UARTE_ENABLED - nrfx_uarte - UARTE peripheral driver
//==========================================================
#ifndef NRFX_UARTE_ENABLED
#define NRFX_UARTE_ENABLED 1
#endif

// <e> NRFX_UART_ENABLED - nrfx_uart - UART peripheral driver
//==========================================================
#ifndef NRFX_UART_ENABLED
#define NRFX_UART_ENABLED 1
#endif

//==========================================================
// <q> APP_FIFO_ENABLED  - app_fifo - Software FIFO implementation
 

#ifndef APP_FIFO_ENABLED
#define APP_FIFO_ENABLED 1
#endif

// <e> APP_UART_ENABLED - app_uart - UART driver
//==========================================================
#ifndef APP_UART_ENABLED
#define APP_UART_ENABLED 1
#endif
// <o> APP_UART_DRIVER_INSTANCE  - UART instance used
 
// <0=> 0 

#ifndef APP_UART_DRIVER_INSTANCE
#define APP_UART_DRIVER_INSTANCE 0
#endif

// // <e> UART_ENABLED - nrf_drv_uart - UART/UARTE peripheral driver - legacy layer
// // //==========================================================
#ifndef UART_ENABLED
#define UART_ENABLED 1
#endif

// // // <e> UART0_ENABLED - Enable UART0 instance
// // //==========================================================
#ifndef UART0_ENABLED
#define UART0_ENABLED 1
#endif


#ifndef RETARGET_ENABLED
#define RETARGET_ENABLED 1
#endif


/*******************************************************************************
 * Clocks
 ******************************************************************************/
// <e> NRFX_CLOCK_ENABLED - nrfx_clock - CLOCK peripheral driver
//==========================================================
#ifndef NRFX_CLOCK_ENABLED
#define NRFX_CLOCK_ENABLED 1
#endif

#ifndef CLOCK_CONFIG_LF_SRC
#define CLOCK_CONFIG_LF_SRC 1
#endif

#ifndef NRFX_CLOCK_CONFIG_LF_CAL_ENABLED
#define NRFX_CLOCK_CONFIG_LF_CAL_ENABLED 0
#endif

// <e> NRF_CLOCK_ENABLED - nrf_drv_clock - CLOCK peripheral driver - legacy layer
//==========================================================
#ifndef NRF_CLOCK_ENABLED
#define NRF_CLOCK_ENABLED 1
#endif

// <e> APP_TIMER_ENABLED - app_timer - Application timer functionality
//==========================================================
#ifndef APP_TIMER_ENABLED
#define APP_TIMER_ENABLED 1
#endif



/*******************************************************************************
 * PRS
 ******************************************************************************/

// <e> NRFX_PRS_ENABLED - nrfx_prs - Peripheral Resource Sharing module
//==========================================================
#ifndef NRFX_PRS_ENABLED
#define NRFX_PRS_ENABLED 1
#endif
// <q> NRFX_PRS_BOX_0_ENABLED  - Enables box 0 in the module.


#ifndef NRFX_PRS_BOX_0_ENABLED
#define NRFX_PRS_BOX_0_ENABLED 0
#endif

// <q> NRFX_PRS_BOX_1_ENABLED  - Enables box 1 in the module.


#ifndef NRFX_PRS_BOX_1_ENABLED
#define NRFX_PRS_BOX_1_ENABLED 0
#endif

// <q> NRFX_PRS_BOX_2_ENABLED  - Enables box 2 in the module.


#ifndef NRFX_PRS_BOX_2_ENABLED
#define NRFX_PRS_BOX_2_ENABLED 0
#endif

// <q> NRFX_PRS_BOX_3_ENABLED  - Enables box 3 in the module.


#ifndef NRFX_PRS_BOX_3_ENABLED
#define NRFX_PRS_BOX_3_ENABLED 0
#endif

// <q> NRFX_PRS_BOX_4_ENABLED  - Enables box 4 in the module.


#ifndef NRFX_PRS_BOX_4_ENABLED
#define NRFX_PRS_BOX_4_ENABLED 1
#endif

// <e> NRFX_PRS_CONFIG_LOG_ENABLED - Enables logging in the module.
//==========================================================
#ifndef NRFX_PRS_CONFIG_LOG_ENABLED
#define NRFX_PRS_CONFIG_LOG_ENABLED 0
#endif
// <o> NRFX_PRS_CONFIG_LOG_LEVEL  - Default Severity level

// <0=> Off
// <1=> Error
// <2=> Warning
// <3=> Info
// <4=> Debug

#ifndef NRFX_PRS_CONFIG_LOG_LEVEL
#define NRFX_PRS_CONFIG_LOG_LEVEL 3
#endif

// <o> NRFX_PRS_CONFIG_INFO_COLOR  - ANSI escape code prefix.

// <0=> Default
// <1=> Black
// <2=> Red
// <3=> Green
// <4=> Yellow
// <5=> Blue
// <6=> Magenta
// <7=> Cyan
// <8=> White

#ifndef NRFX_PRS_CONFIG_INFO_COLOR
#define NRFX_PRS_CONFIG_INFO_COLOR 0
#endif

// <o> NRFX_PRS_CONFIG_DEBUG_COLOR  - ANSI escape code prefix.

// <0=> Default
// <1=> Black
// <2=> Red
// <3=> Green
// <4=> Yellow
// <5=> Blue
// <6=> Magenta
// <7=> Cyan
// <8=> White

#ifndef NRFX_PRS_CONFIG_DEBUG_COLOR
#define NRFX_PRS_CONFIG_DEBUG_COLOR 0
#endif


#ifndef UART0_CONFIG_USE_EASY_DMA
#define UART0_CONFIG_USE_EASY_DMA 1
#endif
#endif