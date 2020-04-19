/******************************/
/* Author  : Moustafa Ghareeb */
/* Version : V1.0             */
/* Date    : 18-04-2020       */
/******************************/
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "../../LIB/BIT_MATH/BIT_MATH.h"

#include "COM_LConfig.h"

#define		PDU1_ID					2
#define		PDU1_SIGNALS_NUM		1
#define		DOOR_SIGNALS_ID			0

#define 	DOOR_SIGNAL_START_BIT		3
#define		DOOR_SIGNAL_LENGTH			1

Signals_t 	SysSignals[MAX_SYSTEM_SIGNALS_NUM] = {
													{
															.Signal_Bits_Start  = DOOR_SIGNAL_START_BIT,
														.Signal_Bits_Length = DOOR_SIGNAL_LENGTH
													 }
												 };

PDU_t SysPDU[MAX_SYSTEM_PDUS_NUM] = {
										{
											.PDU_ID = PDU1_ID,
											.PDU_SIGNALS_NUM = PDU1_SIGNALS_NUM,
											.PDU_SIGNALS_ID  = {DOOR_SIGNALS_ID}
										}
									};
