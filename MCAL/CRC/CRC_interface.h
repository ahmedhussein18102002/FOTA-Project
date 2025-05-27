/*
 * CRC_interface.h
 *
 *  Created on: May 27, 2025
 *      Author: ahmed
 */

#ifndef MCAL_CRC_CRC_INTERFACE_H_
#define MCAL_CRC_CRC_INTERFACE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"



/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void CRC_Init(void);
u32 CRC_Accumlate(u32 Arr_Data[], u32 Copy_u32ArrSize);
void CRC_RESET_DR(void);

#endif /* MCAL_CRC_CRC_INTERFACE_H_ */
