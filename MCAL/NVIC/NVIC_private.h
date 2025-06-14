/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  NVIC_private.h
  
 *********************************************************************************************************************/
#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../SCB/SCB_interface.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define NVIC_BASE  (0xE000E100UL)
#define NVIC       ((NVIC_Type*)NVIC_BASE)
#define NVIC_PRIO_BITS 4U // Number of priority bits in NVIC for STM32F4xx

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct {
	volatile u32 ISER[8U];
	volatile u32 RESERVED0[24U];
	volatile u32 ICER[8U];
	volatile u32 RESERVED1[24U];
	volatile u32 ISPR[8U];
    volatile u32 RESERVED2[24U];
    volatile u32 ICPR[8U];
    volatile u32 RESERVED3[24U];
    volatile u32 IABR[8U];
    volatile u32 RESERVED4[56U];
    volatile u8 IP[240U];
    volatile u32 RESERVED5[644U];
    volatile u32 STIR;
}NVIC_Type;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif /* NVIC_PRIVATE_H_ */

/**********************************************************************************************************************
 *  END OF FILE: NVIC_private.h
 *********************************************************************************************************************/
