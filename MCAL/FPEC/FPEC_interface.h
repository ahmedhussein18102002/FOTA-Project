/*
 * FPEC_interface.h
 *
 *  Created on: May 27, 2025
 *      Author: ahmed
 */

#ifndef MCAL_FPEC_FPEC_INTERFACE_H_
#define MCAL_FPEC_FPEC_INTERFACE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"



/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

void FPEC_Write(u32 Copy_u32Address, u8* Copy_u32Data, u32 Copy_u32DataLength );
void FPEC_EraseSectors(u8 Copy_u8SectorNumber, u8 Copy_u8NbOfSectors);
u8 FPEC_GetReadProtectionLevel(void);



#endif /* MCAL_FPEC_FPEC_INTERFACE_H_ */
