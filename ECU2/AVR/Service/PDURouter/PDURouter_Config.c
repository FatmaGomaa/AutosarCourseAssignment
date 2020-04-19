/******************************/
/* Author  : Moustafa Ghareeb */
/* Version : V1.0             */
/* Date    : 18-04-2020       */
/******************************/
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "../../LIB/BIT_MATH/BIT_MATH.h"

#include "PDURouter_Config.h"
#include "../../Complex_Drivers/UART/UART.h"

#define		UART_ID			0
#define 	UART_PDU_NUM	1
#define		UART_PDU_IDS	2

Protocol_t	SysProtocols[MAX_PROTOCOL_NUM]={
											{
													.Protocol_ID = UART_ID,
													.Protocol_PDU_NUM = UART_PDU_NUM,
													.Protocol_PDU_IDs = {UART_PDU_IDS},
													.Protocol_Send = UART_Send,
													.Protocol_Receive = UART_Receive
											}
											};

