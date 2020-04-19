/***********************************************************************************************/
/* AUTHOR: Fatima Gomaa                                                                        */
/* DATE	 : March 9 2020                                                                        */
/* VERSION: V01                                                                                */
/***********************************************************************************************/
#include "../../LIB/STD_TYPES/STD_Types.h"

#include "UART.h"

#define UART_UDR_RXB								                *((volatile u8*)0x2C)
#define UART_UDR_TXB                                                *((volatile u8*)0x2C)
#define UART_UCSRA                                                  *((volatile u8*)0x2B)
#define UART_UCSRB                                                  *((volatile u8*)0x2A)
#define UART_UCSRC                                                  *((volatile u8*)0x40)
#define UART_UBRRL                                                  *((volatile u8*)0x29)
#define UART_UBRRH                                                  *((volatile u8*)0x40)

#define UART_PARITY_DISABLES										0b00000000
#define UART_PARITY_EVEN                                            0b00100000
#define UART_PARITY_ODD                                             0b00110000

#define UART_BAUD_4800                                              0X64
#define UART_BAUD_9600                                              0X33
#define UART_BAUD_115200                                            0X03

#define UART_STOP_1_BIT												0b00000000
#define UART_STOP_2_BIT                                             0b00001000

#define UART_SYS_FREQUENCY_8M										0u
#define UART_SYS_FREQUENCY_12M                                      1u
#define UART_SYS_FREQUENCY_16M                                      2u

#define UART_BAUD_RATE_4800											0X64
#define UART_BAUD_RATE_9600											0X33
#define UART_BAUD_RATE_115200										0X03

#define UCSRA_U2X							                        0b00000010
#define UCSRA_UDRE							                        0b00100000
#define UCSRA_TXC							                        0b01000000
#define UCSRA_RXC							                        0b10000000

#define UCSRB_RXCIE							                        0b10000000
#define UCSRB_TXCIE							                        0b01000000
#define UCSRB_UDRIE							                        0b00100000
#define UCSRB_RXEN							                        0b00010000
#define UCSRB_TXEN							                        0b00001000
#define UCSRB_UCSZ2							                        0b00000100
#define UCSRB_RXB8							                        0b00000010
#define UCSRB_TXB8							                        0b00000001

#define UCSRC_URSEL							                        0b10000000
#define UCSRC_UMSEL							                        0b01000000
#define UCSRC_UPM1							                        0b00100000
#define UCSRC_UPM0							                        0b00010000
#define UCSRC_USBS							                        0b00001000
#define UCSRC_UCSZ1							                        0b00000100
#define UCSRC_UCSZ0							                        0b00000010
#define UCSRC_UCPOL							                        0b00000001


error_status UART_Init(void)
{
	error_status local_errorStatus = E_NOK;

	/*disable U2X*/
	UART_UCSRA &= ~ UCSRA_U2X;

	/*1. Disable all interrupts
	  2. Enable RX and TX
	  3. Choose Character Size of 8 bit*/
	UART_UCSRB &= ~ (UCSRB_RXCIE | UCSRB_TXCIE | UCSRB_UDRIE | UCSRB_UCSZ2 | UCSRB_TXB8 | UCSRB_RXB8);
	UART_UCSRB |= UCSRB_RXEN | UCSRB_TXEN;

	/*Asynchronous Mode
	  Character Size = 8 bit*/
	UART_UCSRC |= (UCSRC_URSEL | UCSRC_UCSZ1 | UCSRC_UCSZ0);
	UART_UCSRC &= ~ (UCSRC_UMSEL | UCSRC_UPM1 | UCSRC_UPM0 | UCSRC_USBS | UCSRC_UCPOL);

	/*Assign BaudRate*/
	UART_UBRRL |= UART_U8_BAUD_RATE;
	
	if (UART_UBRRL == UART_U8_BAUD_RATE){
		local_errorStatus = E_OK;
	}
	return local_errorStatus;
}

error_status UART_Send(u8 Data){
	error_status Local_ErrorStatus = E_NOK;

	while( !(UART_UCSRA & UCSRA_UDRE) );

	/*Disable TXC and UDRE flags*/
	UART_UCSRA |= UCSRA_TXC | UCSRA_UDRE;

	/*send data on UDR*/
	UART_UDR_TXB = Data;

	/*this check could be removed and return OK directly*/
	if((UART_UCSRA & UCSRA_UDRE )){
		Local_ErrorStatus = E_OK;
	}

	return Local_ErrorStatus;

}

error_status UART_Receive(u8* Data){
	error_status Local_ErrorStatus = E_NOK;
	
	if (Data){
		Local_ErrorStatus = E_OK;
	}
	/*wait till flag is raised */
	while( ((UART_UCSRA & UCSRA_RXC) == 0 ) );

	*Data = UART_UDR_RXB;

	UART_UCSRA |= UCSRA_RXC;
	
	return Local_ErrorStatus;
}
