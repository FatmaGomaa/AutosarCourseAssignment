/******************************/
/* Author  : Moustafa Ghareeb */
/* Version : V1.0             */
/* Date    : 18-04-2020       */
/******************************/
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "../../LIB/BIT_MATH/BIT_MATH.h"

#include "../../Complex_Drivers/UART/UART.h"

#include "PDURouter.h"
#include "PDURouter_Config.h"

#define PDU_ID_POSITION	6

error_status PDURouter_Init(void)
{
	error_status local_error = E_OK;
	local_error = UART_Init();
	return local_error;
}

void PDURouter_Send(u8 pdudata)
{
	u8 PDUcounter;
	u8 Protocolcounter;
	u8 pduID;
	pduID = pdudata >> PDU_ID_POSITION;
	for(Protocolcounter = 0;Protocolcounter<MAX_PROTOCOL_NUM;Protocolcounter++)
	{
		for(PDUcounter = 0;PDUcounter<SysProtocols[Protocolcounter].Protocol_PDU_NUM;PDUcounter++)
		{
			if(pduID == SysProtocols[Protocolcounter].Protocol_PDU_IDs[PDUcounter])
			{
				SysProtocols[Protocolcounter].Protocol_Send(pdudata);
			}
		}
	}
}

void PDURouter_Receive(u8* pdudata)
{
	static u8 PDUcounter = 0;
	static u8 Protocolcounter = 0;
	SysProtocols[Protocolcounter].Protocol_Receive(pdudata);
	if(PDUcounter < SysProtocols[Protocolcounter].Protocol_PDU_NUM)
	{
		PDUcounter++;
	}
	else 
	{
		if(Protocolcounter < MAX_PROTOCOL_NUM)	
		{
			PDUcounter = 0;
			Protocolcounter++;
		}
		else
		{
			Protocolcounter = 0;
			PDUcounter = 0;
		}
	}
}
