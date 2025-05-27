/*
 * FPEC_private.h
 *
 *  Created on: May 27, 2025
 *      Author: ahmed
 */

#ifndef MCAL_FPEC_FPEC_PRIVATE_H_
#define MCAL_FPEC_FPEC_PRIVATE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define FPEC_BASE (0x40023C00)
#define FPEC ((FPEC_t*)FPEC_BASE)

#define FLASH_KEY1  0x45670123
#define FLASH_KEY2  0xCDEF89AB

#define FLASH_LOCK_BIT_POS 31

#define FLASH_PROGRAMMING_ACTIVE_BIT_POS 0
#define FLASH_BSY_FLAG_BIT_POS 16

#define FLASH_SER_BIT_POS 1
#define FLASH_STRT_BIT_POS 16




/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef struct {
	volatile u32 FLASH_ACR;
	volatile u32 FLASH_KEYR;
	volatile u32 FLASH_OPTKEYR;
	volatile u32 FLASH_SR;
	volatile u32 FLASH_CR;
	volatile u32 FLASH_OPTCR;

}FPEC_t;

#endif /* MCAL_FPEC_FPEC_PRIVATE_H_ */
