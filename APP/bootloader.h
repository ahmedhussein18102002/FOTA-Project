/*
 * bootloader.h
 *
 *  Created on: May 27, 2025
 *      Author: ahmed
 */

#ifndef APP_BOOTLOADER_H_
#define APP_BOOTLOADER_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <string.h>
#include "MCAL/UART/UART_Lcfg.h"
#include "MCAL/SCB/SCB_private.h"
#include "MCAL/CRC/CRC_interface.h"
#include "MCAL/FPEC/FPEC_interface.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define BL_HOST_RX_BUFFER_LENGTH 200

#define BL_HOST_COMMUNICATION_UART &UART1_Cfg

#define UART_MAX_DELAY 1800000

#define CBL_GET_VER_CMD 0x10
#define CBL_GET_CID_CMD 0x11
#define CBL_GET_RDP_STATUS_CMD 0x12
#define CBL_APPLICATION_ERASE_CMD 0x13
#define CBL_MEM_WRITE_CMD 0x14
#define CBL_GO_TO_MAIN_APP_CMD 0x15


#define CBL_VENDOR_ID 200
#define CBL_SW_MAJOR_VERSION 1
#define CBL_SW_MINOR_VERSION 0
#define CBL_SW_PATCH_VERSION 0

#define CRC_VERFICATION_FAILED 0
#define CRC_VERFICATION_PASSED 1

#define CBL_SEND_NACK 0x00
#define CBL_SEND_ACK  0xff

#define DBGMCU_IDCODE (*((volatile u32*)0xE0042000))

#define APPLICATION_SECTOR_NUM 1
#define FLASH_NUM_OF_SECTORS 8 //for 401xD/E > target E

#define ERASE_SUCCESS 0x01


#define Address_Verification_SUCCESS 0x01
#define Address_Verification_FAILED 0x04


#define FLASH_BASE 0x08000000U
#define FLASH_SIZE (512*1025) //STM32F401xD/E
#define FLASH_END (0x08000000U + FLASH_SIZE)

#define JUMP_SUCCESS 0x01
#define JUMP_FAILED 0x04

#define APPLICATION_START_ADDRESS 0x08004000

typedef void (*pMainApp)(void) ;  // pointer to function
typedef void (*Jump_Ptr)(void) ;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

void BL_UART_Fetch_Host_Command(void);

#endif /* APP_BOOTLOADER_H_ */
