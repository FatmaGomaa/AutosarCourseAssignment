/*******************************************************************************************************
 * File name: Light.c                   	                                                            *
 *                                                                                                      *
 *                                                                                                      *
 * Description: This file contains the implementation of the Lighting software component  		  	    *
 *                                                                                                      *
 * Author: Fatima Gomaa	                                                            			   	    *
 * Date:   April 3, 2020                                                                                *
 * Version 1.0 : Initial Creation 					                                                    *
 * Version 1.1 : removing RTE init function															    *						  
 *******************************************************************************************************/
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "../../LIB/BIT_MATH/BIT_MATH.h"

#include "../../MCAL/DIO/DIO.h"
#include "../../RTE/RTE.h"
#include "Light.h"

error_status Light_Init(void)
{
	error_status local_error = E_OK;
	return local_error;
}

error_status Light_UpdateLight(void)
{
	error_status local_error = E_OK;
	u8 LightStatus;
	local_error  = RTE_ReadLightStatus(&LightStatus);
	if (LIGHT_ON == LightStatus)
	{local_error |= RTE_CallLightUpdate(LIGHT_ON);}
	else if (LIGHT_OFF == LightStatus)
	{local_error |= RTE_CallLightUpdate(LIGHT_OFF);}
	else
	{local_error = E_NOK;}
	return local_error;
}
