/*******************************************************************************************************
 * File name: Dimmer.c                                                                                 *
 *                                                                                                     *
 *                                                                                                     *
 * Description: This file contains the implementation of the Dimmer software component  			   *
 *                                                                                                     *
 * Author: Fatima Gomaa	                                                            				   *
 * Date:   April 3, 2020                                                                               *
 * Version 1.0 : Initial Creation 					                                                   *
 *******************************************************************************************************/
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "../../LIB/BIT_MATH/BIT_MATH.h"

#include "../../MCAL/DIO/DIO.h"
#include "../../RTE/RTE.h"
#include "Dimmer.h"

error_status Dimmer_Init(void)
{
	error_status local_error = E_OK;
	local_error = RTE_WriteLightStatus(LIGHT_OFF);
	return local_error;
}

error_status Dimmer_UpdateStatus(void)
{
	error_status local_error = E_OK;
	u8 DoorStatus;
	local_error  = RTE_ReadDoorStatus(&DoorStatus);
	if (DOOR_OPEN == DoorStatus)
	{local_error |= RTE_WriteLightStatus(LIGHT_ON);}
	else if (DOOR_CLOSED == DoorStatus)
	{local_error |= RTE_WriteLightStatus(LIGHT_OFF);}
	else
	{local_error = E_NOK;}
	return local_error;
}
