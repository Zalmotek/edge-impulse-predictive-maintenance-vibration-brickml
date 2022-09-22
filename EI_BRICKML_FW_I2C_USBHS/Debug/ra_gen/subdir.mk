################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra_gen/common_data.c \
../ra_gen/hal_data.c \
../ra_gen/main.c \
../ra_gen/main_thread.c \
../ra_gen/pin_data.c \
../ra_gen/sensors_thread.c \
../ra_gen/vector_data.c 

C_DEPS += \
./ra_gen/common_data.d \
./ra_gen/hal_data.d \
./ra_gen/main.d \
./ra_gen/main_thread.d \
./ra_gen/pin_data.d \
./ra_gen/sensors_thread.d \
./ra_gen/vector_data.d 

OBJS += \
./ra_gen/common_data.o \
./ra_gen/hal_data.o \
./ra_gen/main.o \
./ra_gen/main_thread.o \
./ra_gen/pin_data.o \
./ra_gen/sensors_thread.o \
./ra_gen/vector_data.o 

SREC += \
EI_BRICKML_FW_I2C_USBHS.srec 

MAP += \
EI_BRICKML_FW_I2C_USBHS.map 


# Each subdirectory must supply rules for building sources it contributes
ra_gen/%.o: ../ra_gen/%.c
	$(file > $@.in,-mcpu=cortex-m33 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -D_RENESAS_RA_ -DTRACE_ON_SERIAL -DTRACE_ON_USB -D_RA_CORE=CM33 -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra/fsp/inc" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra/fsp/inc/api" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra/fsp/inc/instances" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra/fsp/src/rm_freertos_port" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra/aws/amazon-freertos/freertos_kernel/include" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra_gen" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra_cfg/fsp_cfg/bsp" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra_cfg/fsp_cfg" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra_cfg/aws" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra/fsp/src/r_usb_basic/src/driver/inc" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/audio" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/common" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/common/threads_sync" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/common/trace" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/comms" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/comms/usb" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/led" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/drivers" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/drivers/bno055" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/drivers/hs300x" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

