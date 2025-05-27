#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

#define AHB_CLK  84000000U
#define APB1_CLK 42000000U
#define APB2_CLK 84000000U

/* Options:
    RCC_CLK_HSI
    RCC_CLK_HSE
    RCC_CLK_PLL
*/
#define RCC_CLOCK_SOURCE RCC_CLK_PLL

/* PLL source options:
    RCC_CLK_HSI
    RCC_CLK_HSE
*/
#define RCC_CLK_PLL_SRC RCC_CLK_HSE

/* AHB Prescaler options */
#define RCC_AHB_PRESCALER RCC_AHB_DIV_1

/* APB1 Prescaler options */
#define RCC_APB1_PRESCALER RCC_APB1_DIV_2

/* APB2 Prescaler options */
#define RCC_APB2_PRESCALER RCC_APB2_DIV_1

/* PLLN: VCO output = VCO input x PLLN (192 – 432) */
#define RCC_PLLN_VALUE 336

/* PLLM: VCO input = HSE / PLLM (2 – 63), HSE assumed 8MHz */
#define RCC_PLLM_VALUE 8

/* PLLP: Main PLL output = VCO / PLLP (2, 4, 6, or 8) */
#define RCC_PLLP_VALUE RCC_PLLP_DIV_4

#endif
