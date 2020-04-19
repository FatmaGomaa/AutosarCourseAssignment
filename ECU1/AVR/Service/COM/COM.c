/******************************/
/* Author  : Moustafa Ghareeb */
/* Version : V1.0             */
/* Date    : 18-04-2020       */
/******************************/
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "../../LIB/BIT_MATH/BIT_MATH.h"

#include "../PDURouter/PDURouter.h"

#include "COM.h"
#include "COM_LConfig.h"

#define BYTE_SIZE 		8
#define PDU_ID_POSITION	6

static u8 com_signals_buffer[MAX_SYSTEM_SIGNALS_NUM];


error_status COMM_Init(void)
{
	error_status local_error = E_OK;
	local_error = PDURouter_Init();
	return local_error;
}

error_status COMM_Send(u8 signalID,u8 data)
{
	error_status local_error = E_OK;
	if(signalID < MAX_SYSTEM_SIGNALS_NUM)
	{
		com_signals_buffer[signalID] = data;
	}
	else
	{
		local_error = E_NOK;
	}
	return local_error;
}

error_status COMM_Receive(u8 signalID,u8* data)
{
	error_status local_error = E_OK;
	if(signalID < MAX_SYSTEM_SIGNALS_NUM)
	{
		*data = com_signals_buffer[signalID];
	}
	else
	{
		local_error = E_NOK;
	}
	return local_error;
}

void COMM_TXMainFunction(void)
{
	u8 PDUcounter;
	u8 Signalcounter;
	u8 pdudata;
	for(PDUcounter = 0;PDUcounter<MAX_SYSTEM_PDUS_NUM;PDUcounter++)
	{
		/*Setting PDU ID*/
		pdudata = SysPDU[PDUcounter].PDU_ID << PDU_ID_POSITION;
		/*Setting PDU Signals*/
		for(Signalcounter = 0;Signalcounter<SysPDU[PDUcounter].PDU_SIGNALS_NUM;Signalcounter++)
		{
			pdudata |= com_signals_buffer[SysPDU[PDUcounter].PDU_SIGNALS_ID[Signalcounter]]<<SysSignals[SysPDU[PDUcounter].PDU_SIGNALS_ID[Signalcounter]].Signal_Bits_Start;
		}
		PDURouter_Send(pdudata);
	}
}

void COMM_RXMainFunction(void)
{
	u8 PDUcounter;
	u8 PDUcounter2;
	u8 Signalcounter;
	u8 pdudata;
	u8 pduID;
	for(PDUcounter2 = 0;PDUcounter2<MAX_SYSTEM_PDUS_NUM;PDUcounter2++)
	{
		PDURouter_Receive(&pdudata);
		/*Getting PDU ID*/
		pduID = pdudata >> PDU_ID_POSITION;
		for(PDUcounter = 0;PDUcounter<MAX_SYSTEM_PDUS_NUM;PDUcounter++)
		{
			/*Getting PDU signals*/
			if (pduID == SysPDU[PDUcounter].PDU_ID)
			{
				for(Signalcounter = 0;Signalcounter<SysPDU[PDUcounter].PDU_SIGNALS_NUM;Signalcounter++)
				{
					com_signals_buffer[SysPDU[PDUcounter].PDU_SIGNALS_ID[Signalcounter]] = ((pdudata << (BYTE_SIZE - SysSignals[SysPDU[PDUcounter].PDU_SIGNALS_ID[Signalcounter]].Signal_Bits_Length - SysSignals[SysPDU[PDUcounter].PDU_SIGNALS_ID[Signalcounter]].Signal_Bits_Start ) )>>(BYTE_SIZE-SysSignals[SysPDU[PDUcounter].PDU_SIGNALS_ID[Signalcounter]].Signal_Bits_Length)); 
				}
			}
		}
	}
}
