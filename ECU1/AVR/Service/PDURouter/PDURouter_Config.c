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

Protocol_t	UART_protocol={UART_ID,UART_PDU_NUM,{UART_PDU_IDS},UART_Send,UART_Receive};

Protocol_t	SysProtocols[MAX_PROTOCOL_NUM]={UART_protocol};