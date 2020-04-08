/******************************/
/* Author  : Moustafa Ghareeb */
/* Version : V1.0             */
/* Date    : 08-04-2020       */
/******************************/
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "../../LIB/BIT_MATH/BIT_MATH.h"

#include "../../MCAL/DIO/DIO.h"
#include "../../RTE/RTE.h"
#include "RightDoor.h"

error_status RightDoor_Init(void)
{
	error_status local_error = E_OK;
	local_error |= RTE_WriteRightDoorStatus(DOOR_CLOSED);
	return local_error;
}

error_status RightDoor_GetStatus(void)
{
	error_status local_error = E_OK;
	static u8 counter = 0;
	static u8 RightDoorStatusPrev;
	u8 RightDoorStatus;
	local_error  = RTE_CallGetRightDoorStatus(&RightDoorStatus);
	if(RightDoorStatus == RightDoorStatusPrev)
	{
		counter++;
		if(counter==5)
		{
			local_error |= RTE_WriteRightDoorStatus((RightDoorStatus^RIGHT_DOOR_MODE));
			counter=0;
		}
	}	
	else
	{
		counter=0;
	}
	RightDoorStatusPrev = RightDoorStatus;
	return local_error;
}
