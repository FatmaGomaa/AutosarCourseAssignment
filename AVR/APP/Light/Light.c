/******************************/
/* Author  : Moustafa Ghareeb */
/* Version : V1.0             */
/* Date    : 08-04-2020       */
/******************************/
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
