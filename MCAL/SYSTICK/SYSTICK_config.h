/*********************************************
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				MCAL
 ********************************************/
#ifndef SYSTICK_CONFIG_H
#define SYSTICK_CONFIG_H

#define SYSTICK_AHB_CLK 84000000

#define SYSTICK_CLOCK_SOURCE  SYSTICK_AHB_DIV_8

#define SYSTICK_INT_CTRL    SYSTICK_DISABLE

#define SYSTICK_CTRL        SYSTICK_ENABLE

#endif
