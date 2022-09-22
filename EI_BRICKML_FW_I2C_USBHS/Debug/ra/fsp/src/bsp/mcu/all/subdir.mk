################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/fsp/src/bsp/mcu/all/bsp_clocks.c \
../ra/fsp/src/bsp/mcu/all/bsp_common.c \
../ra/fsp/src/bsp/mcu/all/bsp_delay.c \
../ra/fsp/src/bsp/mcu/all/bsp_group_irq.c \
../ra/fsp/src/bsp/mcu/all/bsp_guard.c \
../ra/fsp/src/bsp/mcu/all/bsp_io.c \
../ra/fsp/src/bsp/mcu/all/bsp_irq.c \
../ra/fsp/src/bsp/mcu/all/bsp_register_protection.c \
../ra/fsp/src/bsp/mcu/all/bsp_rom_registers.c \
../ra/fsp/src/bsp/mcu/all/bsp_sbrk.c \
../ra/fsp/src/bsp/mcu/all/bsp_security.c 

C_DEPS += \
./ra/fsp/src/bsp/mcu/all/bsp_clocks.d \
./ra/fsp/src/bsp/mcu/all/bsp_common.d \
./ra/fsp/src/bsp/mcu/all/bsp_delay.d \
./ra/fsp/src/bsp/mcu/all/bsp_group_irq.d \
./ra/fsp/src/bsp/mcu/all/bsp_guard.d \
./ra/fsp/src/bsp/mcu/all/bsp_io.d \
./ra/fsp/src/bsp/mcu/all/bsp_irq.d \
./ra/fsp/src/bsp/mcu/all/bsp_register_protection.d \
./ra/fsp/src/bsp/mcu/all/bsp_rom_registers.d \
./ra/fsp/src/bsp/mcu/all/bsp_sbrk.d \
./ra/fsp/src/bsp/mcu/all/bsp_security.d 

OBJS += \
./ra/fsp/src/bsp/mcu/all/bsp_clocks.o \
./ra/fsp/src/bsp/mcu/all/bsp_common.o \
./ra/fsp/src/bsp/mcu/all/bsp_delay.o \
./ra/fsp/src/bsp/mcu/all/bsp_group_irq.o \
./ra/fsp/src/bsp/mcu/all/bsp_guard.o \
./ra/fsp/src/bsp/mcu/all/bsp_io.o \
./ra/fsp/src/bsp/mcu/all/bsp_irq.o \
./ra/fsp/src/bsp/mcu/all/bsp_register_protection.o \
./ra/fsp/src/bsp/mcu/all/bsp_rom_registers.o \
./ra/fsp/src/bsp/mcu/all/bsp_sbrk.o \
./ra/fsp/src/bsp/mcu/all/bsp_security.o 

SREC += \
EI_BRICKML_FW_I2C_USBHS.srec 

MAP += \
EI_BRICKML_FW_I2C_USBHS.map 


# Each subdirectory must supply rules for building sources it contributes
ra/fsp/src/bsp/mcu/all/%.o: ../ra/fsp/src/bsp/mcu/all/%.c
	$(file > $@.in,-mcpu=cortex-m33 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -D_RENESAS_RA_ -DTRACE_ON_SERIAL -DTRACE_ON_USB -D_RA_CORE=CM33 -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra/fsp/inc" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra/fsp/inc/api" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra/fsp/inc/instances" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra/fsp/src/rm_freertos_port" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra/aws/amazon-freertos/freertos_kernel/include" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra_gen" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra_cfg/fsp_cfg/bsp" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra_cfg/fsp_cfg" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra_cfg/aws" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra/fsp/src/r_usb_basic/src/driver/inc" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/audio" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/common" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/common/threads_sync" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/common/trace" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/comms" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/comms/usb" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/led" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/drivers" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/drivers/bno055" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/drivers/hs300x" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

