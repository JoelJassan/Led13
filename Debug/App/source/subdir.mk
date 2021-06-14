################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/source/app.c \
../App/source/pin.c \
../App/source/timer_sys.c 

OBJS += \
./App/source/app.o \
./App/source/pin.o \
./App/source/timer_sys.o 

C_DEPS += \
./App/source/app.d \
./App/source/pin.d \
./App/source/timer_sys.d 


# Each subdirectory must supply rules for building sources it contributes
App/source/app.o: ../App/source/app.c App/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"E:/Facet/Github/CubeIDE/Led13/App/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"App/source/app.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
App/source/pin.o: ../App/source/pin.c App/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"E:/Facet/Github/CubeIDE/Led13/App/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"App/source/pin.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
App/source/timer_sys.o: ../App/source/timer_sys.c App/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"E:/Facet/Github/CubeIDE/Led13/App/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"App/source/timer_sys.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

