/******************************/
/* Author  : Moustafa Ghareeb */
/* Version : V1.0             */
/* Date    : 03-04-2020       */
/******************************/
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "../../LIB/BIT_MATH/BIT_MATH.h"

#include "DIO.h"

		/*A*/
#define	PORTA	*((u8*)0x3B)
#define	DDRA	*((u8*)0x3A)
#define	PINA	*((u8*)0x39)
		/*B*/
#define	PORTB	*((u8*)0x38)
#define	DDRB	*((u8*)0x37)
#define	PINB	*((u8*)0x36)
		/*C*/
#define	PORTC	*((u8*)0x35)
#define	DDRC	*((u8*)0x34)
#define	PINC	*((u8*)0x33)
		/*D*/
#define	PORTD	*((u8*)0x32)
#define	DDRD	*((u8*)0x31)
#define	PIND	*((u8*)0x30)

error_status DIO_SetPinDir(u8 Port,u8 Pin,u8 Dir)
{
	error_status local_error  =  E_OK;
	switch(Port)
	{
		case'A':
			if(Dir==0)
			{
				CLR_BIT(DDRA,Pin);	
			}
			else
			{
				SET_BIT(DDRA,Pin);	
			}
			break;
		case'B':
			if(Dir==0)
			{
				CLR_BIT(DDRB,Pin);	
			}
			else
			{
				SET_BIT(DDRB,Pin);	
			}
			break;
		case'C':
			if(Dir==0)
			{
				CLR_BIT(DDRC,Pin);	
			}
			else
			{
				SET_BIT(DDRC,Pin);	
			}
			break;
		case'D':
			if(Dir==0)
			{
				CLR_BIT(DDRD,Pin);	
			}
			else
			{
				SET_BIT(DDRD,Pin);	
			}
			break;
		default:
			local_error = E_NOK;
			break;
	}	
	return local_error;
}

error_status DIO_SetPinValue(u8 Port,u8 Pin,u8 Val)
{
	error_status local_error  =  E_OK;
	switch(Port)
	{
		case'A':
			if(Val==0)
			{
				CLR_BIT(PORTA,Pin);	
			}
			else
			{
				SET_BIT(PORTA,Pin);	
			}
			break;
		case'B':
			if(Val==0)
			{
				CLR_BIT(PORTB,Pin);	
			}
			else
			{
				SET_BIT(PORTB,Pin);	
			}
			break;
		case'C':
			if(Val==0)
			{
				CLR_BIT(PORTC,Pin);	
			}
			else
			{
				SET_BIT(PORTC,Pin);	
			}
			break;
		case'D':
			if(Val==0)
			{
				CLR_BIT(PORTD,Pin);	
			}
			else
			{
				SET_BIT(PORTD,Pin);	
			}
			break;
		default:
			local_error = E_NOK;
			break;
	}
	return local_error;
}

error_status DIO_GetPinValue(u8 Port,u8 Pin,u8* Val)
{
	error_status local_error  =  E_OK;
	switch(Port)
	{
		case'A':
			*Val =  GET_BIT(PINA,Pin);	
			break;
		case'B':
			*Val =  GET_BIT(PINB,Pin);	
			break;
		case'C':
			*Val =  GET_BIT(PINC,Pin);		
			break;
		case'D':
			*Val =  GET_BIT(PIND,Pin);
			break;
		default:
			local_error = E_NOK;
			break;
	}
	return local_error;
}
