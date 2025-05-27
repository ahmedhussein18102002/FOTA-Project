################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/CRC/CRC_program.c 

OBJS += \
./MCAL/CRC/CRC_program.o 

C_DEPS += \
./MCAL/CRC/CRC_program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/CRC/%.o MCAL/CRC/%.su MCAL/CRC/%.cyclo: ../MCAL/CRC/%.c MCAL/CRC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"/media/ahmed/New Volume/STM32_Projects/BootLoader" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-MCAL-2f-CRC

clean-MCAL-2f-CRC:
	-$(RM) ./MCAL/CRC/CRC_program.cyclo ./MCAL/CRC/CRC_program.d ./MCAL/CRC/CRC_program.o ./MCAL/CRC/CRC_program.su

.PHONY: clean-MCAL-2f-CRC

