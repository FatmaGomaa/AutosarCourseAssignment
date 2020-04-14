/*****************************************************************/
/* Author    : Mohanad Sallam                                    */
/* Date      : 9 March 2020                                      */
/* Version   : V01                                               */
/*****************************************************************/
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "../../LIB/BIT_MATH/BIT_MATH.h"

#include "../UART/UART_config.h"
#include "../UART/UART.h"


#define UDR_T      *((volatile u8*)0x2C)
#define UDR_R      *((volatile u8*)0x2C)
#define UCSRA      *((volatile u8*)0x2B)
#define UCSRB      *((volatile u8*)0x2A)
#define UCSRC      *((volatile u8*)0x40)
#define UBRRL      *((volatile u8*)0x29)
#define UBRRH      *((volatile u8*)0x40)

const u8 BaudRateValue [3][3] =
{
		/*  4800    ,   9600   , 115200   */
		{   0x67    ,   0x33   ,  0x03     },  /* Clock System 0 = 8  MHz */
		{   154     ,     77   ,   6       },  /* Clock System 1 = 12 MHz */
		{   0xcf    ,   0x67   ,   0x08    }   /* Clock System 2 = 16 MHz */
};


void (*EndOfTransmitCB)(void);
void (*EndOfRecCB)(u8  );

void UART_Init (void)
{
	/* U2X = 0 */
	CLR_BIT(UCSRA,1);

	/* Disable all UART Interrupts */
	/* Enable RX and TX */
	/* Character size 8 bit */
	UCSRB = 0x18;

	/* Asynch Mode
       Character size = 8 bit   	*/
	UCSRC = (
			(1                 << 7) |
			(UART_u8_PARTIY    << 4) |
			(UART_u8_STOP_BITS << 3) |
			(3                 << 1)
	);

	/* Assign Baud Rate */
	UBRRL = BaudRateValue[UART_u8_SYS_FREQ][UART_u8_BUAD_RATE];
}

error_status UART_TransmitDataSynch   (u8 Copy_u8Data)
{
	u32 Local_u32Timeout = 0;
	error_status  LocalError    = E_OK;

	/* Send data on UDR */
	UDR_T = Copy_u8Data;

	/* wait till flag is raised */
	while( ((GET_BIT(UCSRA,6)) == 0) && (Local_u32Timeout < UART_u32_TIME_OUT_TH))
	{
		Local_u32Timeout++;
	}

	/* timeout happened */
	if (Local_u32Timeout >= UART_u32_TIME_OUT_TH)
	{
		LocalError = E_NOK;
	}

	else
	{
		/* Clear Flag */
		SET_BIT(UCSRA,6);
	}

	return LocalError;
}


error_status UART_TransmitDataAsynch  (u8 Copy_u8Data, void(*Copy_ptr)(void))
{
	error_status LocalError=E_OK;
	if (!Copy_ptr)
	{
		LocalError=E_NOK;

	}
	else
	{
		/* Enable Tx Interrupt */
		SET_BIT(UCSRB,UCSRB_TXCIE);

		/* Set received Data to UDR */
		UDR_T = Copy_u8Data;

		/* Save the callback address */
		EndOfTransmitCB = Copy_ptr;
	}
	return LocalError;
}


error_status     UART_ReceiveSynch  (u8* Copy_pu8Data)
{
	u32 Local_u32Timeout = 0;
	u8  LocalError    = E_OK;

	/* wait till flag is raised */
	while( ((GET_BIT(UCSRA,7)) == 0) && (Local_u32Timeout < UART_u32_TIME_OUT_TH))
	{
		Local_u32Timeout++;
	}

	/* timeout happened */
	if (Local_u32Timeout >= UART_u32_TIME_OUT_TH)
	{
		LocalError = E_NOK;
	}

	else
	{
		/* Set data to received pointer */
		*Copy_pu8Data = UDR_R;
	}

	return LocalError;
}




error_status   UART_ReceiveAsynch ( void(*Copy_ptr)(u8) )
{
	u8 LocalError = E_OK;
	if (!Copy_ptr)
	{
		LocalError = E_OK;
	}
	else
	{
		/* Check if there is data to receive */
		if ( (GET_BIT(UCSRA,UCSRB_RXCIE)) == 1)
		{
			Copy_ptr(UDR_R);
		}

		/* Nothing to receive now, enable receive interrupt */
		else
		{
			/* Enable Rx Interrupt */
			SET_BIT(UCSRB,UCSRB_RXCIE);

			/* Save call back in global variable */
			EndOfRecCB = Copy_ptr;

		}
	}
	return LocalError;
}
void __vector_15 (void) __attribute__((signal));
void __vector_15 (void)
{
	CLR_BIT(UCSRB,UCSRB_TXCIE);
	EndOfTransmitCB();
}
void __vector_13 (void) __attribute__((signal));
void __vector_13 (void)
{
	CLR_BIT(UCSRB,UCSRB_RXCIE);
	EndOfRecCB(UDR_R);
}
