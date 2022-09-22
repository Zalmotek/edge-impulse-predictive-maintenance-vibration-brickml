################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/fsp/src/r_usb_basic/src/hw/r_usb_creg_abs.c \
../ra/fsp/src/r_usb_basic/src/hw/r_usb_creg_access.c \
../ra/fsp/src/r_usb_basic/src/hw/r_usb_dma.c \
../ra/fsp/src/r_usb_basic/src/hw/r_usb_hostelectrical.c \
../ra/fsp/src/r_usb_basic/src/hw/r_usb_hreg_abs.c \
../ra/fsp/src/r_usb_basic/src/hw/r_usb_hreg_access.c \
../ra/fsp/src/r_usb_basic/src/hw/r_usb_mcu.c \
../ra/fsp/src/r_usb_basic/src/hw/r_usb_preg_abs.c \
../ra/fsp/src/r_usb_basic/src/hw/r_usb_preg_access.c 

C_DEPS += \
./ra/fsp/src/r_usb_basic/src/hw/r_usb_creg_abs.d \
./ra/fsp/src/r_usb_basic/src/hw/r_usb_creg_access.d \
./ra/fsp/src/r_usb_basic/src/hw/r_usb_dma.d \
./ra/fsp/src/r_usb_basic/src/hw/r_usb_hostelectrical.d \
./ra/fsp/src/r_usb_basic/src/hw/r_usb_hreg_abs.d \
./ra/fsp/src/r_usb_basic/src/hw/r_usb_hreg_access.d \
./ra/fsp/src/r_usb_basic/src/hw/r_usb_mcu.d \
./ra/fsp/src/r_usb_basic/src/hw/r_usb_preg_abs.d \
./ra/fsp/src/r_usb_basic/src/hw/r_usb_preg_access.d 

OBJS += \
./ra/fsp/src/r_usb_basic/src/hw/r_usb_creg_abs.o \
./ra/fsp/src/r_usb_basic/src/hw/r_usb_creg_access.o \
./ra/fsp/src/r_usb_basic/src/hw/r_usb_dma.o \
./ra/fsp/src/r_usb_basic/src/hw/r_usb_hostelectrical.o \
./ra/fsp/src/r_usb_basic/src/hw/r_usb_hreg_abs.o \
./ra/fsp/src/r_usb_basic/src/hw/r_usb_hreg_access.o \
./ra/fsp/src/r_usb_basic/src/hw/r_usb_mcu.o \
./ra/fsp/src/r_usb_basic/src/hw/r_usb_preg_abs.o \
./ra/fsp/src/r_usb_basic/src/hw/r_usb_preg_access.o 

SREC += \
EI_BRICKML_FW_I2C_USBHS.srec 

MAP += \
EI_BRICKML_FW_I2C_USBHS.map 


# Each subdirectory must supply rules for building sources it contributes
ra/fsp/src/r_usb_basic/src/hw/%.o: ../ra/fsp/src/r_usb_basic/src/hw/%.c
	$(file > $@.in,-mcpu=cortex-m33 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -D_RENESAS_RA_ -DTRACE_ON_SERIAL -DTRACE_ON_USB -D_RA_CORE=CM33 -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra/fsp/inc" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra/fsp/inc/api" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra/fsp/inc/instances" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra/fsp/src/rm_freertos_port" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra/aws/amazon-freertos/freertos_kernel/include" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra_gen" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra_cfg/fsp_cfg/bsp" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra_cfg/fsp_cfg" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra_cfg/aws" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra/fsp/src/r_usb_basic/src/driver/inc" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/audio" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/common" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/common/threads_sync" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/common/trace" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/comms" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/comms/usb" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/led" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/drivers" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/drivers/bno055" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/drivers/hs300x" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

