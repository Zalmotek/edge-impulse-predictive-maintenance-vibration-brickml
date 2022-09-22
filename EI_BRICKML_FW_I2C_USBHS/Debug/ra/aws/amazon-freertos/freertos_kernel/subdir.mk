################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/aws/amazon-freertos/freertos_kernel/event_groups.c \
../ra/aws/amazon-freertos/freertos_kernel/list.c \
../ra/aws/amazon-freertos/freertos_kernel/queue.c \
../ra/aws/amazon-freertos/freertos_kernel/stream_buffer.c \
../ra/aws/amazon-freertos/freertos_kernel/tasks.c \
../ra/aws/amazon-freertos/freertos_kernel/timers.c 

C_DEPS += \
./ra/aws/amazon-freertos/freertos_kernel/event_groups.d \
./ra/aws/amazon-freertos/freertos_kernel/list.d \
./ra/aws/amazon-freertos/freertos_kernel/queue.d \
./ra/aws/amazon-freertos/freertos_kernel/stream_buffer.d \
./ra/aws/amazon-freertos/freertos_kernel/tasks.d \
./ra/aws/amazon-freertos/freertos_kernel/timers.d 

OBJS += \
./ra/aws/amazon-freertos/freertos_kernel/event_groups.o \
./ra/aws/amazon-freertos/freertos_kernel/list.o \
./ra/aws/amazon-freertos/freertos_kernel/queue.o \
./ra/aws/amazon-freertos/freertos_kernel/stream_buffer.o \
./ra/aws/amazon-freertos/freertos_kernel/tasks.o \
./ra/aws/amazon-freertos/freertos_kernel/timers.o 

SREC += \
EI_BRICKML_FW_I2C_USBHS.srec 

MAP += \
EI_BRICKML_FW_I2C_USBHS.map 


# Each subdirectory must supply rules for building sources it contributes
ra/aws/amazon-freertos/freertos_kernel/%.o: ../ra/aws/amazon-freertos/freertos_kernel/%.c
	$(file > $@.in,-mcpu=cortex-m33 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -D_RENESAS_RA_ -DTRACE_ON_SERIAL -DTRACE_ON_USB -D_RA_CORE=CM33 -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra/fsp/inc" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra/fsp/inc/api" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra/fsp/inc/instances" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra/fsp/src/rm_freertos_port" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra/aws/amazon-freertos/freertos_kernel/include" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra_gen" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra_cfg/fsp_cfg/bsp" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra_cfg/fsp_cfg" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra_cfg/aws" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/ra/fsp/src/r_usb_basic/src/driver/inc" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/audio" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/common" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/common/threads_sync" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/common/trace" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/comms" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/comms/usb" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/led" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/drivers" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/drivers/bno055" -I"C:/Users/editing rig/Documents/BRICK_ML/EI_BRICKML_FW_I2C_USBHS/src/drivers/hs300x" -std=c99 -w -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

