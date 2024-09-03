
#include "board.h"


static void gpio_init(void);


/*******************************************************************************
 * Global Variables
 ******************************************************************************/


// nordic_iic_t nordic_iic0 = {
//     .id = IIC1,
//     .inst_idx = 0,
//     .config = {
//         .scl = IIC_SCL_PIN,
//         .sda = IIC_SDA_PIN,
//         .frequency = NRF_TWIM_FREQ_100K,
//         .interrupt_priority = TWI_DEFAULT_CONFIG_IRQ_PRIORITY - 1,
//         .hold_bus_uninit = 0
//     }
// };

app_uart_comm_params_t nordic_uart = {
	.rx_pin_no = RX_PIN_NUMBER,
	.tx_pin_no = TX_PIN_NUMBER,
	.rts_pin_no = RTS_PIN_NUMBER,
	.cts_pin_no = CTS_PIN_NUMBER,
	.flow_control = APP_UART_FLOW_CONTROL_DISABLED,
	.use_parity = false,
	.baud_rate = NRF_UARTE_BAUDRATE_921600
};



/*****************************************************************************/

/*******************************************************************************
 * Init Functions
 ******************************************************************************/

static void gpio_init(void) {
	nrf_gpio_cfg_output( LED0 );
	nrf_gpio_pin_clear( LED0 );

	nrf_gpio_cfg_output( LED1 );
	nrf_gpio_pin_clear( LED1 );

    // nrf_gpio_cfg_output( LED2 );
    // nrf_gpio_pin_clear( LED2 );

    // nrf_gpio_cfg_output( LED3 );
    // nrf_gpio_pin_clear( LED3 );

    nrf_gpio_cfg_input(PN532_IRQ_PIN, NRF_GPIO_PIN_NOPULL);

}



static void log_init(void) {
    ret_code_t err_code = NRF_LOG_INIT(NULL);
    APP_ERROR_CHECK(err_code);

    NRF_LOG_DEFAULT_BACKENDS_INIT();
}




void led_on(uint32_t led_idx) {
	nrf_gpio_pin_write( led_idx, 1 );

}

void led_off(uint32_t led_idx) {
	nrf_gpio_pin_write( led_idx, 0 );
}

void led_toggle(uint32_t led_idx) {
	 nrf_gpio_pin_toggle(led_idx);
}



void board_init() {
    // Initialize.
	int32_t res = 0;

    log_init();
    gpio_init();

    // nordic_iic_init(&nordic_iic0);

    /*
     * PPI Demo
     * HW timer triggers SPI start and CSn toggling. Only processor intervention
     * is starting a new spi transaction every time the previous transaction finishes
     *
     * In a real application - would enable/disable the timer based on bt connected
     * Forward chunks of samples to the central at regular intervals (50 ms/10 samples/20 bytes)?
     *
     * SPI has the ability to auto increment the rx buffer pointer. Could allocate a bigger buffer
     * 3 * 10 = 30 bytes, and in the spi irq just increment a counter. if the counter reaches full, copy
     * buffer to bt and notify central. Downside - data wouldn't be properly shifted, 3 bytes per xfer
     * instead of 2 Upside - very little processor interaction.
     *
     * Alternatively, irq after each transaction, format the spi data and copy to bigger buffer. When
     * bigger buffer is full, copy buffer to bt stack and notify the central.
     */
    uart_init(&nordic_uart);
    //nordic_timer_start(&nordic_timer0);

}
