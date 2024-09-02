PROJECT_NAME     := freertos_example
TARGETS          := nrf52840_xxaa
OUTPUT_DIRECTORY := _build

ifndef NRF_SDK_ROOT
  SDK_ROOT := C:/nrf/nRF5_SDK_17.1.0_ddde560
else
  SDK_ROOT := ${NRF_SDK_ROOT}
endif
PROJ_DIR := .

GIT_VERSION := $(git log --pretty=format:%h -n 1 .)
GIT_DIRTY := $(git diff-files --quiet --relative . || echo '-dirty')

$(OUTPUT_DIRECTORY)/nrf52840_xxaa.out: \
  LINKER_SCRIPT  := $(PROJ_DIR)/src/freertos_example_linker.ld



SRC_NRF_LOGGING = \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_backend_rtt.c \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_backend_serial.c \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_backend_uart.c \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_default_backends.c \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_frontend.c \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_str_formatter.c

SRC_UART_LOGGING = \
  $(SDK_ROOT)/components/libraries/fifo/app_fifo.c \
  $(SDK_ROOT)/components/libraries/uart/app_uart_fifo.c \
  $(SDK_ROOT)/integration/nrfx/legacy/nrf_drv_uart.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_uart.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_uarte.c

NOSD = \
  $(SDK_ROOT)/components/drivers_nrf/nrf_soc_nosd/nrf_soc.c
  
# Source files common to all targets
SRC_FILES += \
  $(SDK_ROOT)/modules/nrfx/mdk/gcc_startup_nrf52840.S \
  $(SDK_ROOT)/components/libraries/button/app_button.c \
  $(SDK_ROOT)/components/libraries/util/app_error.c \
  $(SDK_ROOT)/components/libraries/util/app_error_handler_gcc.c \
  $(SDK_ROOT)/components/libraries/util/app_error_weak.c \
  $(SDK_ROOT)/components/libraries/scheduler/app_scheduler.c \
  $(SDK_ROOT)/components/libraries/timer/app_timer_freertos.c \
  $(SDK_ROOT)/components/libraries/util/app_util_platform.c \
  $(SDK_ROOT)/components/libraries/timer/drv_rtc.c \
  $(SDK_ROOT)/components/libraries/hardfault/hardfault_implementation.c \
  $(SDK_ROOT)/components/libraries/util/nrf_assert.c \
  $(SDK_ROOT)/components/libraries/atomic_fifo/nrf_atfifo.c \
  $(SDK_ROOT)/components/libraries/atomic_flags/nrf_atflags.c \
  $(SDK_ROOT)/components/libraries/atomic/nrf_atomic.c \
  $(SDK_ROOT)/components/libraries/balloc/nrf_balloc.c \
  $(NOSD) \
  $(SRC_NRF_LOGGING) \
  $(SRC_UART_LOGGING) \
  $(SDK_ROOT)/external/fprintf/nrf_fprintf.c \
  $(SDK_ROOT)/external/fprintf/nrf_fprintf_format.c \
  $(SDK_ROOT)/components/libraries/pwr_mgmt/nrf_pwr_mgmt.c \
  $(SDK_ROOT)/components/libraries/experimental_section_vars/nrf_section_iter.c \
  $(SDK_ROOT)/components/libraries/strerror/nrf_strerror.c \
  $(SDK_ROOT)/modules/nrfx/mdk/system_nrf52840.c \
  $(SDK_ROOT)/components/boards/boards.c \
  $(SDK_ROOT)/integration/nrfx/legacy/nrf_drv_clock.c \
  $(SDK_ROOT)/modules/nrfx/soc/nrfx_atomic.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_clock.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_gpiote.c \
  $(wildcard $(PROJ_DIR)/src/*.c) \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_timer.c \
  $(SDK_ROOT)/components/libraries/uart/retarget.c \
  $(wildcard $(SDK_ROOT)/external/freertos/source/*.c) \
  $(SDK_ROOT)/external/freertos/source/portable/MemMang/heap_2.c \
  $(SDK_ROOT)/external/freertos/source/portable/Common/mpu_wrappers.c \
  $(SDK_ROOT)/external/freertos/portable/GCC/nrf52/port.c \
  $(SDK_ROOT)/external/freertos/portable/CMSIS/nrf52/port_cmsis.c \
  $(SDK_ROOT)/external/freertos/portable/CMSIS/nrf52/port_cmsis_systick.c

# Include folders common to all targets
INC_FOLDERS += \
  $(SDK_ROOT)/components/drivers_nrf/nrf_soc_nosd \
  $(SDK_ROOT)/components/libraries/fifo \
  $(SDK_ROOT)/components/nfc/ndef/generic/message \
  $(SDK_ROOT)/modules/nrfx/hal \
  $(SDK_ROOT)/components/libraries/bsp \
  $(SDK_ROOT)/components/libraries/uart \
  $(SDK_ROOT)/components/libraries/log \
  $(SDK_ROOT)/components/libraries/gpiote \
  $(SDK_ROOT)/components/libraries/bootloader/ble_dfu \
  $(SDK_ROOT)/components/boards \
  $(SDK_ROOT)/modules/nrfx/drivers/include \
  $(SDK_ROOT)/components/libraries/pwr_mgmt \
  $(SDK_ROOT)/components/toolchain/cmsis/include \
  $(SDK_ROOT)/components/libraries/mpu \
  $(SDK_ROOT)/components/libraries/experimental_section_vars \
  $(SDK_ROOT)/components/libraries/slip \
  $(SDK_ROOT)/components/libraries/delay \
  $(SDK_ROOT)/components/libraries/csense_drv \
  $(SDK_ROOT)/components/libraries/memobj \
  $(SDK_ROOT)/external/fprintf \
  $(SDK_ROOT)/components/libraries/svc \
  $(SDK_ROOT)/components/libraries/atomic \
  $(SDK_ROOT)/components \
  $(SDK_ROOT)/components/libraries/scheduler \
  $(SDK_ROOT)/components/libraries/cli \
  $(SDK_ROOT)/components/libraries/crc16 \
  $(SDK_ROOT)/components/libraries/util \
  $(PROJ_DIR)/inc \
  $(SDK_ROOT)/components/libraries/csense \
  $(SDK_ROOT)/components/libraries/balloc \
  $(SDK_ROOT)/components/libraries/ecc \
  $(SDK_ROOT)/components/libraries/hardfault \
  $(SDK_ROOT)/components/libraries/hci \
  $(SDK_ROOT)/components/libraries/timer \
  $(SDK_ROOT)/integration/nrfx \
  $(SDK_ROOT)/modules/nrfx/mdk \
  $(SDK_ROOT)/components/libraries/strerror \
  $(SDK_ROOT)/components/libraries/crc32 \
  $(SDK_ROOT)/components/libraries/usbd/class/audio \
  $(SDK_ROOT)/components/nfc/t4t_lib \
  $(SDK_ROOT)/components/libraries/mem_manager \
  $(SDK_ROOT)/components/libraries/ringbuf \
  $(SDK_ROOT)/components/libraries/button \
  $(SDK_ROOT)/modules/nrfx \
  $(SDK_ROOT)/integration/nrfx/legacy \
  $(SDK_ROOT)/components/libraries/atomic_fifo \
  $(SDK_ROOT)/components/libraries/fds \
  $(SDK_ROOT)/components/libraries/atomic_flags \
  $(SDK_ROOT)/components/libraries/stack_guard \
  $(SDK_ROOT)/components/libraries/log/src \
  $(SDK_ROOT)/config/nrf52840/config \
  $(SDK_ROOT)/external/freertos/source/include \
  $(SDK_ROOT)/external/freertos/portable/GCC/nrf52 \
  $(SDK_ROOT)/external/freertos/portable/CMSIS/nrf52


# Libraries common to all targets
LIB_FILES += \

# Optimization flags
OPT = -O0 -g3
# Uncomment the line below to enable link time optimization
#OPT += -flto

# C flags common to all targets
CFLAGS += $(OPT)
CFLAGS += -DVERSION=\"$(GIT_VERSION)$(GIT_DIRTY)\"
CFLAGS += -DAPP_TIMER_FREERTOS
# CFLAGS += -DAPP_TIMER_V2_RTC1_ENABLED
CFLAGS += -DBOARD_PCA10056
CFLAGS += -DCONFIG_GPIO_AS_PINRESET
CFLAGS += -DDEBUG
CFLAGS += -DFLOAT_ABI_HARD
CFLAGS += -DNRF52840_XXAA
# CFLAGS += -DNRF_SD_BLE_API_VERSION=7
# CFLAGS += -DS113
# CFLAGS += -DSOFTDEVICE_PRESENT
CFLAGS += -DUSE_APP_CONFIG
CFLAGS += -mcpu=cortex-m4
CFLAGS += -mthumb -mabi=aapcs
CFLAGS += -Wall -Wunused
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
# keep every function in a separate section, this allows linker to discard unused ones
CFLAGS += -ffunction-sections -fdata-sections -fno-strict-aliasing
CFLAGS += -fno-builtin -fshort-enums

# C++ flags common to all targets
CXXFLAGS += $(OPT)
# Assembler flags common to all targets
ASMFLAGS += -g3
ASMFLAGS += -mcpu=cortex-m4
ASMFLAGS += -mthumb -mabi=aapcs
ASMFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
ASMFLAGS += -DAPP_TIMER_FREERTOS
# ASMFLAGS += -DAPP_TIMER_V2_RTC1_ENABLED
ASMFLAGS += -DBOARD_PCA10056
ASMFLAGS += -DCONFIG_GPIO_AS_PINRESET
ASMFLAGS += -DFLOAT_ABI_HARD
ASMFLAGS += -DNRF52840_XXAA
# ASMFLAGS += -DNRF_SD_BLE_API_VERSION=7
# ASMFLAGS += -DS113
# ASMFLAGS += -DSOFTDEVICE_PRESENT
ASMFLAGS += -DUSE_APP_CONFIG

# Linker flags
LDFLAGS += $(OPT)
LDFLAGS += -mthumb -mabi=aapcs -L$(SDK_ROOT)/modules/nrfx/mdk -T$(LINKER_SCRIPT)
LDFLAGS += -mcpu=cortex-m4
LDFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
# let linker dump unused sections
LDFLAGS += -Wl,--gc-sections
# use newlib in nano version
LDFLAGS += --specs=nano.specs
LDFLAGS += -u _printf_float

nrf52840_xxaa: CFLAGS += -D__HEAP_SIZE=0
nrf52840_xxaa: CFLAGS += -D__STACK_SIZE=8192
nrf52840_xxaa: ASMFLAGS += -D__HEAP_SIZE=0
nrf52840_xxaa: ASMFLAGS += -D__STACK_SIZE=8192

# Add standard libraries at the very end of the linker input, after all objects
# that may need symbols provided by these libraries.
LIB_FILES += -lc -lnosys -lm


.PHONY: default help

# Default target - first one defined
default: nrf52840_xxaa

# Print all targets that can be built
help:
	@echo following targets are available:
	@echo		nrf52840_xxaa
	@echo		flash_softdevice
	@echo		sdk_config - starting external tool for editing sdk_config.h
	@echo		flash      - flashing binary

TEMPLATE_PATH := $(SDK_ROOT)/components/toolchain/gcc


include $(TEMPLATE_PATH)/Makefile.common
RM := $(if $(filter Windows%,$(OS)),rmdir /q /s,rm -rf)

$(foreach target, $(TARGETS), $(call define_target, $(target)))

.PHONY: flash flash_softdevice erase version

# Flash the program
flash: default
	@echo Flashing: $(OUTPUT_DIRECTORY)/nrf52840_xxaa.hex
	nrfjprog -f nrf52 --program $(OUTPUT_DIRECTORY)/nrf52840_xxaa.hex --sectorerase
	nrfjprog -f nrf52 --reset

clean:
	@echo Deleting $(OUTPUT_DIRECTORY) Directory
	$(RM) "$(PROJ_DIR)/$(OUTPUT_DIRECTORY)"

version:
	@echo "Hello"
	$(CC) -v

# Flash softdevice
flash_softdevice:
	@echo Flashing: s113_nrf52_7.2.0_softdevice.hex
	nrfjprog -f nrf52 --program $(SDK_ROOT)/components/softdevice/s113/hex/s113_nrf52_7.2.0_softdevice.hex --sectorerase
	nrfjprog -f nrf52 --reset

erase:
	nrfjprog -f nrf52 --eraseall

clang:
	clang $(wildcard $(PROJ_DIR)/src/*.c) -I$(PROJ_DIR)/inc
#	clang $(wildcard $(PROJ_DIR)/src/*.c) $(CFLAGS) $(foreach d, $(INC_FOLDERS), -I$d)


#SDK_CONFIG_FILE := $(PROJ_DIR)/inc/config
SDK_CONFIG_FILE := $(SDK_ROOT)/config/nrf52840/config/sdk_config.h
CMSIS_CONFIG_TOOL := $(SDK_ROOT)/external_tools/cmsisconfig/CMSIS_Configuration_Wizard.jar
sdk_config:
	java -jar $(CMSIS_CONFIG_TOOL) $(SDK_CONFIG_FILE)
