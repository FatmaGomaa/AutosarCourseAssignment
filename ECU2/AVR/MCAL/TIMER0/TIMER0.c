/*******************************************************************************************************
 * File name: Timer0.c                   	                                                            *
 *                                                                                                      *
 *                                                                                                      *
 * Description: This file contains the implementation of Timer 0						  		  	    *
 *                                                                                                      *
 * Author: Fatima Gomaa	                                                            			   	    *
 * Date:   April 7, 2020                                                                                *
 * Version 1.0 : Initial Creation 					                                                    *
 *******************************************************************************************************/
#include "../../LIB/STD_TYPES/STD_TYPES.h"

#include "TIMER0.h"
/*TIMER 0 regs*/
#define TCCR0  *((u8*)0x53)
#define TCNT0  *((u8*)0x52)
#define TIMSK  *((u8*)0x59)
/*Global INT reg*/
#define SREG   *((u8*)0x5F)
/*Required definitions*/
#define TIMER0_WGM00	6
#define TIMER0_WGM01	3
#define TIMER0_CS00		0
#define TIMER0_CS01		1
#define TIMER0_CS02		2
#define TIMER0_TOIE0	0
#define NO_CLOCK_SOURCE					0
#define PRESCALER_DIV_1					1
#define PRESCALER_DIV_8					2
#define PRESCALER_DIV_64				3
#define PRESCALER_DIV_256				4
#define PRESCALER_DIV_1024				5
#define EXTERNAL_CLOCK_ON_FALLING_EDGE	6
#define EXTERNAL_CLOCK_ON_RISING_EDGE	7
#define TIMER0_FULL_COUNT				255

#define PRESCALER	PRESCALER_DIV_256

static void (*TIMER0_CallBackFunction)(void);
static u16 Num_Overflow = 0;
static u16 OV_Counter = 0;
static u8 initial_time = 0;

error_status TIMER0_Init(void)
{
	error_status local_error  =  E_OK;
	TCCR0 = PRESCALER;
	TIMSK|=0x01;
	SREG|=1<<7;
	return local_error;
}

error_status TIMER0_SetTimeus(u32 Time_us)
{
	error_status local_error  =  E_OK;
	Num_Overflow = Time_us/TIMER0_FULL_COUNT;
	initial_time = Time_us % TIMER0_FULL_COUNT;
	if(initial_time>0){Num_Overflow++;}
	TCNT0 = initial_time;
	return local_error;
}

error_status TIMER0_SetCallBack(void(*Copy_CallBackPtr)(void))
{
	error_status local_error  =  E_OK;
	if(Copy_CallBackPtr)
	{
		TIMER0_CallBackFunction=Copy_CallBackPtr;
	}
	else
	{
		local_error = E_NOK;
	}
	return local_error;
}

void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	OV_Counter++;
	if (OV_Counter >= Num_Overflow)
	{
		OV_Counter=0;
		TCNT0=initial_time;
		if(TIMER0_CallBackFunction)
		{
			TIMER0_CallBackFunction();
		}
	}
	else
	{
		TCNT0 = TIMER0_FULL_COUNT;
	}
}
