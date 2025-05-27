#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/* Base address for RCC */
#define RCC_BASE_ADDRESS    (0x40023800UL)

/* RCC Register Definitions */
#define RCC_CR              (*((volatile u32 *)(RCC_BASE_ADDRESS + 0x00)))
#define RCC_PLLCFGR         (*((volatile u32 *)(RCC_BASE_ADDRESS + 0x04)))
#define RCC_CFGR            (*((volatile u32 *)(RCC_BASE_ADDRESS + 0x08)))
#define RCC_CIR             (*((volatile u32 *)(RCC_BASE_ADDRESS + 0x0C)))
#define RCC_AHB1RSTR        (*((volatile u32 *)(RCC_BASE_ADDRESS + 0x10)))
#define RCC_AHB2RSTR        (*((volatile u32 *)(RCC_BASE_ADDRESS + 0x14)))
#define RCC_APB1RSTR        (*((volatile u32 *)(RCC_BASE_ADDRESS + 0x20)))
#define RCC_APB2RSTR        (*((volatile u32 *)(RCC_BASE_ADDRESS + 0x24)))
#define RCC_AHB1ENR         (*((volatile u32 *)(RCC_BASE_ADDRESS + 0x30)))
#define RCC_AHB2ENR         (*((volatile u32 *)(RCC_BASE_ADDRESS + 0x34)))
#define RCC_APB1ENR         (*((volatile u32 *)(RCC_BASE_ADDRESS + 0x40)))
#define RCC_APB2ENR         (*((volatile u32 *)(RCC_BASE_ADDRESS + 0x44)))
#define RCC_AHB1LPENR       (*((volatile u32 *)(RCC_BASE_ADDRESS + 0x50)))
#define RCC_AHB2LPENR       (*((volatile u32 *)(RCC_BASE_ADDRESS + 0x54)))
#define RCC_APB1LPENR       (*((volatile u32 *)(RCC_BASE_ADDRESS + 0x60)))
#define RCC_APB2LPENR       (*((volatile u32 *)(RCC_BASE_ADDRESS + 0x64)))
#define RCC_BDCR            (*((volatile u32 *)(RCC_BASE_ADDRESS + 0x70)))
#define RCC_CSR             (*((volatile u32 *)(RCC_BASE_ADDRESS + 0x74)))
#define RCC_SSCGR           (*((volatile u32 *)(RCC_BASE_ADDRESS + 0x80)))
#define RCC_PLLI2SCFGR      (*((volatile u32 *)(RCC_BASE_ADDRESS + 0x84)))
#define RCC_DCKCFGR         (*((volatile u32 *)(RCC_BASE_ADDRESS + 0x8C)))

/* FLASH Access Control Register */
#define FPEC_ACR           (*((volatile u32 *)(0x40023C00UL)))

/* RCC_CR Register Bit Positions */
#define RCC_CR_PLLI2SRDY_Pos   27
#define RCC_CR_PLLI2SON_Pos    26
#define RCC_CR_PLLRDY_Pos      25
#define RCC_CR_PLLON_Pos       24
#define RCC_CR_CSSON_Pos       19
#define RCC_CR_HSEBYP_Pos      18
#define RCC_CR_HSERDY_Pos      17
#define RCC_CR_HSEON_Pos       16
#define RCC_CR_HSICAL_Pos      8
#define RCC_CR_HSITRIM_Pos     3
#define RCC_CR_HSIRDY_Pos      1
#define RCC_CR_HSION_Pos       0

/* RCC_CFGR Register Bit Positions */
#define RCC_CFGR_SW0_Pos           0
#define RCC_CFGR_SW1_Pos           1

/* PLLCFGR Register Bit Positions */
#define RCC_PLLCFGR_PLLQ3_Pos     27
#define RCC_PLLCFGR_PLLQ2_Pos     26
#define RCC_PLLCFGR_PLLQ1_Pos     25
#define RCC_PLLCFGR_PLLQ0_Pos     24
#define RCC_PLLCFGR_PLLSRC_Pos    22
#define RCC_PLLCFGR_PLLP1_Pos     17
#define RCC_PLLCFGR_PLLP0_Pos     16
#define RCC_PLLCFGR_PLLN_Pos       6
#define RCC_PLLCFGR_PLLM5_Pos      5
#define RCC_PLLCFGR_PLLM4_Pos      4
#define RCC_PLLCFGR_PLLM3_Pos      3
#define RCC_PLLCFGR_PLLM2_Pos      2
#define RCC_PLLCFGR_PLLM1_Pos      1
#define RCC_PLLCFGR_PLLM0_Pos      0

/* AHB Prescaler Options (bits 7:4 in RCC_CFGR) */
#define RCC_AHB_DIV_1     (0x0 << 4)
#define RCC_AHB_DIV_2     (0x8 << 4)
#define RCC_AHB_DIV_4     (0x9 << 4)
#define RCC_AHB_DIV_8     (0xA << 4)
#define RCC_AHB_DIV_16    (0xB << 4)
#define RCC_AHB_DIV_64    (0xC << 4)
#define RCC_AHB_DIV_128   (0xD << 4)
#define RCC_AHB_DIV_256   (0xE << 4)
#define RCC_AHB_DIV_512   (0xF << 4)

/* APB1 Prescaler Options (bits 12:10 in RCC_CFGR) */
#define RCC_APB1_DIV_1     (0x0 << 10)
#define RCC_APB1_DIV_2     (0x4 << 10)
#define RCC_APB1_DIV_4     (0x5 << 10)
#define RCC_APB1_DIV_8     (0x6 << 10)
#define RCC_APB1_DIV_16    (0x7 << 10)

/* APB2 Prescaler Options (bits 15:13 in RCC_CFGR) */
#define RCC_APB2_DIV_1     (0x0 << 13)
#define RCC_APB2_DIV_2     (0x4 << 13)
#define RCC_APB2_DIV_4     (0x5 << 13)
#define RCC_APB2_DIV_8     (0x6 << 13)
#define RCC_APB2_DIV_16    (0x7 << 13)

/* Masks */
#define RCC_AHB_PRESCALER_MASK   (0xF << 4)
#define RCC_APB1_PRESCALER_MASK  (0x7 << 10)
#define RCC_APB2_PRESCALER_MASK  (0x7 << 13)

#define RCC_PLLN_MASK  (0x1FF << 6)
#define RCC_PLLM_MASK  (0x3F << 0)
#define RCC_PLLP_MASK  (0x3 << 16)

/* PLLP Division factors */
#define RCC_PLLP_DIV_2     (0x0 << 16)
#define RCC_PLLP_DIV_4     (0x1 << 16)
#define RCC_PLLP_DIV_6     (0x2 << 16)
#define RCC_PLLP_DIV_8     (0x3 << 16)

/* Peripheral Enable bits in RCC_AHB1ENR (STM32F401RET6) */
#define RCC_AHB1ENR_GPIOAEN  (1 << 0)
#define RCC_AHB1ENR_GPIOBEN  (1 << 1)
#define RCC_AHB1ENR_GPIOCEN  (1 << 2)
#define RCC_AHB1ENR_GPIOEEN  (1 << 4)
#define RCC_AHB1ENR_GPIOHEN  (1 << 7)
#define RCC_AHB1ENR_CRCEN    (1 << 12)
#define RCC_AHB1ENR_DMA1EN   (1 << 21)
#define RCC_AHB1ENR_DMA2EN   (1 << 22)

/* Peripheral Enable bits in RCC_APB1ENR */
#define RCC_APB1ENR_TIM2EN    (1 << 0)
#define RCC_APB1ENR_TIM3EN    (1 << 1)
#define RCC_APB1ENR_TIM4EN    (1 << 2)
#define RCC_APB1ENR_TIM5EN    (1 << 3)
#define RCC_APB1ENR_WWDGEN    (1 << 11)
#define RCC_APB1ENR_SPI2EN    (1 << 14)
#define RCC_APB1ENR_SPI3EN    (1 << 15)
#define RCC_APB1ENR_USART2EN  (1 << 17)
#define RCC_APB1ENR_I2C1EN    (1 << 21)
#define RCC_APB1ENR_I2C2EN    (1 << 22)
#define RCC_APB1ENR_I2C3EN    (1 << 23)
#define RCC_APB1ENR_PWREN     (1 << 28)

/* Peripheral Enable bits in RCC_APB2ENR */
#define RCC_APB2ENR_TIM1EN      (1 << 0)
#define RCC_APB2ENR_USART1EN    (1 << 4)
#define RCC_APB2ENR_USART6EN    (1 << 5)
#define RCC_APB2ENR_ADC1EN      (1 << 8)
#define RCC_APB2ENR_SDIOEN      (1 << 11)
#define RCC_APB2ENR_SPI1EN      (1 << 12)
#define RCC_APB2ENR_SPI4EN      (1 << 13)
#define RCC_APB2ENR_SYSCFGEN    (1 << 14)
#define RCC_APB2ENR_TIM9EN      (1 << 16)
#define RCC_APB2ENR_TIM10EN     (1 << 17)
#define RCC_APB2ENR_TIM11EN     (1 << 18)

#endif /* RCC_PRIVATE_H */
