################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/GPIO/GPIO_program.c 

OBJS += \
./MCAL/GPIO/GPIO_program.o 

C_DEPS += \
./MCAL/GPIO/GPIO_program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/GPIO/%.o MCAL/GPIO/%.su MCAL/GPIO/%.cyclo: ../MCAL/GPIO/%.c MCAL/GPIO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"/media/ahmed/New Volume/STM32_Projects/BootLoader" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-MCAL-2f-GPIO

clean-MCAL-2f-GPIO:
	-$(RM) ./MCAL/GPIO/GPIO_program.cyclo ./MCAL/GPIO/GPIO_program.d ./MCAL/GPIO/GPIO_program.o ./MCAL/GPIO/GPIO_program.su

.PHONY: clean-MCAL-2f-GPIO

