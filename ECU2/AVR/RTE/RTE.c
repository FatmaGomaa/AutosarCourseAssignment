/*******************************************************************************************************
 * File name: RightDoor.c                                                                            	*
 *                                                                                                     *
 *                                                                                                     *
 * Description: This file contains the implementation of the Right Door	 software component  		   *
 *                                                                                                     *
 * Author: Basma AbdelHakim	                                                            			   *
 * Date:   April 3, 2020                                                                               *
 * Version 1.0 : Initial Creation 					                                                   *
 * Version 1.1 : Adding Tasks Functions and Modifiying Lighting Function Calls in RTE to be 		   *
 * RTE_CallLightUpdate																				   *
 * Version 1.2 : Implementing the Dimmer and Lighting on a separate ECU								   *
 *******************************************************************************************************/
#include "../LIB/STD_TYPES/STD_TYPES.h"
#include "../LIB/BIT_MATH/BIT_MATH.h"

#include "../MCAL/DIO/DIO.h"
#include "./MCAL/UART/UART.h"

#include "../APP/Light/Light.h"
#include "../APP/Dimmer/Dimmer.h"

#include "RTE.h"

#define DOOR_OPEN   	0
#define	DOOR_CLOSED  	1
#define	LIGHT_OFF  		0
#define LIGHT_ON   		1


static u8 Rte_DoorStatus      ;
static u8 Rte_LightStatus     ;


/*Send-Rec*/

error_status RTE_WriteLightStatus(u8 status)
{
	error_status local_error = E_OK;
	Rte_LightStatus = status;
	return local_error;
}


error_status RTE_ReadDoorStatus(u8* status)
{
	error_status local_error = E_OK;
	local_error = UART_ReceiveSynch(status);
	return local_error;
}

error_status RTE_ReadLightStatus(u8* status)
{
	error_status local_error = E_OK;
	*status = Rte_LightStatus;
	return local_error;
}

/*Client - Server*/

error_status RTE_CallLightUpdate(u8 status)
{
	error_status local_error = E_OK;
	local_error = DIO_SetPinValue(LIGHT_PORT,LIGHT_PIN,status);
	return local_error;
}


void RTE_Task_10MS(void)
{
	Dimmer_UpdateStatus();
	Light_UpdateLight();
}
