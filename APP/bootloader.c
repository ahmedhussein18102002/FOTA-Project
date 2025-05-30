/*
 * bootloader.c
 *
 *  Created on: May 27, 2025
 *      Author: ahmed
 */


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "bootloader.h"



/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
static u8 BL_HOST_RX_BUFFER[BL_HOST_RX_BUFFER_LENGTH];
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
static void Bootloader_Get_Version(u8* BL_HOST_BUFFER);
static void Bootloader_Get_Chip_ID(u8* BL_HOST_BUFFER);
static void Bootloader_Get_ReadProtection_Status(u8* BL_HOST_BUFFER);
static void Bootloader_Application_Erase(u8* BL_HOST_BUFFER);
static void Bootloader_Upload_Application(u8* BL_HOST_BUFFER);
static void Bootloader_Jump_To_Application(u8* BL_HOST_BUFFER);

static u8   Bootloader_CRC_Verify(u8* CRC_Data, u32 CRC_Data_Size, u32 Host_CRC);

static void Bootloader_Send_ACK(u8 Data_Length);
static void Bootloader_Send_NOT_ACK();

static void Bootloader_Send_Data_To_Host(u8* Host_Buffer, u32 Host_Buffer_Len);

static u8 Host_Address_Verification(u32 HOST_Address);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
static void Bootloader_Get_Version(u8* BL_HOST_BUFFER){

	u8 Bootloader_Version[4]={
			CBL_VENDOR_ID,
			CBL_SW_MAJOR_VERSION,
			CBL_SW_MINOR_VERSION,
			CBL_SW_PATCH_VERSION
	};

	u16 Host_CMD_Packet_Len = 0;
	u32 Host_CRC32 = 0; 	// from esp or raspberry

	Host_CMD_Packet_Len = BL_HOST_BUFFER[0]+1;
	Host_CRC32 = *((u32*)(BL_HOST_BUFFER + Host_CMD_Packet_Len - 4));


	/********** CRC VERIFY *********/

	if(Bootloader_CRC_Verify(BL_HOST_BUFFER,Host_CMD_Packet_Len-4,Host_CRC32) == CRC_VERFICATION_PASSED){

		Bootloader_Send_ACK(4);
		Bootloader_Send_Data_To_Host(Bootloader_Version,4);

	}else{

		Bootloader_Send_NOT_ACK();
	}

}
static void Bootloader_Get_Chip_ID(u8* BL_HOST_BUFFER){

	u16 Host_CMD_Packet_Len = 0;
	u32 Host_CRC32 = 0; 	// from esp or raspberry

	Host_CMD_Packet_Len = BL_HOST_BUFFER[0]+1;
	Host_CRC32 = *((u32*)(BL_HOST_BUFFER + Host_CMD_Packet_Len - 4));

	u16 MCU_Chip_ID = 0;

	MCU_Chip_ID = DBGMCU_IDCODE & 0x00000FFF;

	/********** CRC VERIFY *********/

	if(Bootloader_CRC_Verify(BL_HOST_BUFFER,Host_CMD_Packet_Len-4,Host_CRC32) == CRC_VERFICATION_PASSED){

		Bootloader_Send_ACK(2); // 12 bit ~ 2 bytes
		Bootloader_Send_Data_To_Host(((u8*)&MCU_Chip_ID),2);

	}else{

		Bootloader_Send_NOT_ACK();
	}

}
static void Bootloader_Get_ReadProtection_Status(u8* BL_HOST_BUFFER){


	u16 Host_CMD_Packet_Len = 0;
	u32 Host_CRC32 = 0; 	// from esp or raspberry

	Host_CMD_Packet_Len = BL_HOST_BUFFER[0]+1;
	Host_CRC32 = *((u32*)(BL_HOST_BUFFER + Host_CMD_Packet_Len - 4));

	u8 RDP_Level = 0;

	RDP_Level = FPEC_GetReadProtectionLevel();

	/********** CRC VERIFY *********/

	if(Bootloader_CRC_Verify(BL_HOST_BUFFER,Host_CMD_Packet_Len-4,Host_CRC32) == CRC_VERFICATION_PASSED){

		Bootloader_Send_ACK(1);
		Bootloader_Send_Data_To_Host(&RDP_Level,1);

	}else{

		Bootloader_Send_NOT_ACK();
	}

}
static void Bootloader_Application_Erase(u8* BL_HOST_BUFFER){


	u16 Host_CMD_Packet_Len = 0;
	u32 Host_CRC32 = 0; 	// from esp or raspberry

	Host_CMD_Packet_Len = BL_HOST_BUFFER[0]+1;
	Host_CRC32 = *((u32*)(BL_HOST_BUFFER + Host_CMD_Packet_Len - 4));

	u8 Erase_Status = 0;

	/********** CRC VERIFY *********/

	if(Bootloader_CRC_Verify(BL_HOST_BUFFER,Host_CMD_Packet_Len-4,Host_CRC32) == CRC_VERFICATION_PASSED){

		Bootloader_Send_ACK(1);
		FPEC_EraseSectors(APPLICATION_SECTOR_NUM, FLASH_NUM_OF_SECTORS-APPLICATION_SECTOR_NUM);
		Erase_Status = ERASE_SUCCESS;
		Bootloader_Send_Data_To_Host(&Erase_Status,1);

	}else{

		Bootloader_Send_NOT_ACK();
	}

}
static void Bootloader_Upload_Application(u8* BL_HOST_BUFFER){

	u16 Host_CMD_Packet_Len = 0;
	u32 Host_CRC32 = 0; 	// from esp or raspberry

	Host_CMD_Packet_Len = BL_HOST_BUFFER[0]+1;
	Host_CRC32 = *((u32*)(BL_HOST_BUFFER + Host_CMD_Packet_Len - 4));

	u32 HOST_Address = 0;
	u8 PAYLOAD_Length = 0;
	u8 Address_Verification = Address_Verification_FAILED;


	/********** CRC VERIFY *********/

	if(Bootloader_CRC_Verify(BL_HOST_BUFFER,Host_CMD_Packet_Len-4,Host_CRC32) == CRC_VERFICATION_PASSED){

		Bootloader_Send_ACK(1);
		HOST_Address = *((u32*)&BL_HOST_BUFFER[2]);
		PAYLOAD_Length = BL_HOST_BUFFER[6];
		Address_Verification = Host_Address_Verification(HOST_Address);
		if(Address_Verification==Address_Verification_SUCCESS){
			// upload

			FPEC_Write(HOST_Address, &BL_HOST_BUFFER[7], PAYLOAD_Length);

			Bootloader_Send_Data_To_Host(&Address_Verification,1);

		}else{

			Bootloader_Send_Data_To_Host(&Address_Verification,1);
		}

	}else{

		Bootloader_Send_NOT_ACK();
	}


}
static void Bootloader_Jump_To_Application(u8* BL_HOST_BUFFER){

		u16 Host_CMD_Packet_Len = 0;
		u32 Host_CRC32 = 0; 	// from esp or raspberry

		Host_CMD_Packet_Len = BL_HOST_BUFFER[0]+1;
		Host_CRC32 = *((u32*)(BL_HOST_BUFFER + Host_CMD_Packet_Len - 4));

		u32 MainAppAddress = 0;
		pMainApp ResetHandler_Address = NULL; // pointer to function
		u8 Jump_Status =  JUMP_SUCCESS;

		/********** CRC VERIFY *********/

		if(Bootloader_CRC_Verify(BL_HOST_BUFFER,Host_CMD_Packet_Len-4,Host_CRC32) == CRC_VERFICATION_PASSED){

			Bootloader_Send_ACK(1);

			MainAppAddress = *((volatile u32*)(APPLICATION_START_ADDRESS + 4));
			ResetHandler_Address = (pMainApp)MainAppAddress;
			if(MainAppAddress == 0xFFFFFFFF){
				Jump_Status = JUMP_FAILED;
				Bootloader_Send_Data_To_Host(&Jump_Status,1);
			}else{
				Jump_Status =  JUMP_SUCCESS;
				Bootloader_Send_Data_To_Host(&Jump_Status,1);

				// jump routine
				SCB->VTOR = APPLICATION_START_ADDRESS;
				ResetHandler_Address();

			}

		}else{

			Bootloader_Send_NOT_ACK();
		}

}

static u8   Bootloader_CRC_Verify(u8* CRC_Data, u32 CRC_Data_Size, u32 Host_CRC){

	u8 CRC_Status = CRC_VERFICATION_FAILED;
	u32 CRC_Calculated = 0;
	u8 Data_Counter = 0;
	u32 Data_Buffer = 0;

	for(Data_Counter = 0; Data_Counter<CRC_Data_Size;Data_Counter++ ){

		Data_Buffer = CRC_Data[Data_Counter];
		CRC_Calculated = CRC_Accumlate(&Data_Buffer, 1);

	}
	CRC_RESET_DR();

	if(Host_CRC == CRC_Calculated){
		CRC_Status = CRC_VERFICATION_PASSED;
	}else{
		CRC_Status = CRC_VERFICATION_FAILED;
	}


	return CRC_Status;

}

static void Bootloader_Send_ACK(u8 Data_Length){

	u8 Ack_Arr[2]={0};
	Ack_Arr[0] = CBL_SEND_ACK;
	Ack_Arr[1] = Data_Length;

	Bootloader_Send_Data_To_Host(Ack_Arr, 2);

}
static void Bootloader_Send_NOT_ACK(){
	u8 NACK_VALUE = CBL_SEND_NACK;

	Bootloader_Send_Data_To_Host(&NACK_VALUE,1);
}


static void Bootloader_Send_Data_To_Host(u8* Host_Buffer, u32 Host_Buffer_Len){

	UART_voidTransmit(BL_HOST_COMMUNICATION_UART, Host_Buffer, Host_Buffer_Len, UART_MAX_DELAY);

}


static u8 Host_Address_Verification(u32 HOST_Address){

	u8 Address_Verification = Address_Verification_FAILED;

	if(HOST_Address >= FLASH_BASE && HOST_Address <= FLASH_END){
		Address_Verification = Address_Verification_SUCCESS;
	}else{
		Address_Verification = Address_Verification_FAILED;
	}

	return Address_Verification;
}



/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
void BL_UART_Fetch_Host_Command(void){
	memset(BL_HOST_RX_BUFFER,0,sizeof(BL_HOST_RX_BUFFER));
	UART_ReceiveByte(BL_HOST_COMMUNICATION_UART, &BL_HOST_RX_BUFFER[0], UART_MAX_DELAY);
	UART_voidReceive(BL_HOST_RX_BUFFER_LENGTH, &BL_HOST_RX_BUFFER[1], BL_HOST_RX_BUFFER[0], UART_MAX_DELAY);
	switch(BL_HOST_RX_BUFFER[1])
	{
		case CBL_GET_VER_CMD:
			Bootloader_Get_Version(BL_HOST_RX_BUFFER);
			break;
		case CBL_GET_CID_CMD:
			Bootloader_Get_Chip_ID(BL_HOST_RX_BUFFER);
			break;
		case CBL_GET_RDP_STATUS_CMD:
			Bootloader_Get_ReadProtection_Status(BL_HOST_RX_BUFFER);
			break;
		case CBL_APPLICATION_ERASE_CMD:
			Bootloader_Application_Erase(BL_HOST_RX_BUFFER);
			break;
		case CBL_MEM_WRITE_CMD:
			Bootloader_Upload_Application(BL_HOST_RX_BUFFER);
			break;
		case CBL_GO_TO_MAIN_APP_CMD:
			Bootloader_Jump_To_Application(BL_HOST_RX_BUFFER);
			break;
		default:
			break;
	}

}



