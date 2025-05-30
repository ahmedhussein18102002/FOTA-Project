/*
 * FPEC_program.c
 *
 *  Created on: May 27, 2025
 *      Author: ahmed
 */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "FPEC_interface.h"
#include "FPEC_private.h"
#include "FPEC_config.h"


/************************************************/



/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

static void FLASH_UNLOCK(void);
static void FLASH_LOCK(void);
static void WAIT_FOR_BSY(void);


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

static void FLASH_UNLOCK(void){

	FPEC -> FLASH_KEYR=FLASH_KEY1;
	FPEC -> FLASH_KEYR=FLASH_KEY2;

}
static void FLASH_LOCK(void){

	SET_BIT(FPEC -> FLASH_CR, FLASH_LOCK_BIT_POS);

}
static void WAIT_FOR_BSY(void){

	while(GET_BIT(FPEC->FLASH_SR, FLASH_BSY_FLAG_BIT_POS)==1);

}


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

void FPEC_Write(u32 Copy_u32Address, u8* Copy_u32Data, u32 Copy_u32DataLength ){

	u32 Local_Counter = 0;

	FLASH_UNLOCK();

	for(Local_Counter = 0;Local_Counter < Copy_u32DataLength;Local_Counter++){

		WAIT_FOR_BSY();
		SET_BIT( FPEC-> FLASH_CR, FLASH_PROGRAMMING_ACTIVE_BIT_POS);

		*((volatile u8*)Copy_u32Address) = Copy_u32Data[Local_Counter];
		WAIT_FOR_BSY();
		CLR_BIT( FPEC-> FLASH_CR, FLASH_PROGRAMMING_ACTIVE_BIT_POS);
		Copy_u32Address++;

	}

	FLASH_LOCK();


}

void FPEC_EraseSectors(u8 Copy_u8SectorNumber, u8 Copy_u8NbOfSectors){

	u32 Local_Counter = 0;

	FLASH_UNLOCK();
	for(Local_Counter = 0;Local_Counter < Copy_u8NbOfSectors;Local_Counter++){

		WAIT_FOR_BSY();

		SET_BIT( FPEC-> FLASH_CR, FLASH_SER_BIT_POS);
		/*
		u32 CLR_Mask = (u32)(0xf<<3);
		FPEC-> FLASH_CR &= ~CLR_Mask;
		u32 Sector =((u32)Copy_u8SectorNumber )<< 3;
		FPEC-> FLASH_CR |= Sector;
		*/
		MODIFY_REG(FPEC-> FLASH_CR, 0xf<<3,Copy_u8SectorNumber<<3);

		SET_BIT( FPEC-> FLASH_CR, FLASH_STRT_BIT_POS);

		WAIT_FOR_BSY();
		CLR_BIT( FPEC-> FLASH_CR, FLASH_SER_BIT_POS);
		Copy_u8SectorNumber++;

	}
	FLASH_LOCK();
}

u8 FPEC_GetReadProtectionLevel(void){
	// RDP[7:0] -> FLASH_OPTCR[15:8]
	u8 ProtectionLevel = (u8)(0xff & (FPEC->FLASH_OPTCR >>8));

	return ProtectionLevel;
}













