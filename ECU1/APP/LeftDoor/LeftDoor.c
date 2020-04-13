/******************************/
/* Author  : Moustafa Ghareeb */
/* Version : V1.0             */
/* Date    : 08-04-2020       */
/******************************/
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "../../LIB/BIT_MATH/BIT_MATH.h"

#include "../../MCAL/DIO/DIO.h"
#include "../../RTE/RTE.h"
#include "LeftDoor.h"

error_status LeftDoor_Init(void)
{
	error_status local_error = E_OK;
	local_error = RTE_WriteLeftDoorStatus(DOOR_CLOSED);
	return local_error;
}

error_status LeftDoor_GetStatus(void)
{
	error_status local_error = E_OK;
	static u8 counter = 0;
	static u8 LeftDoorStatusPrev;
	u8 LeftDoorStatus;
	local_error  = RTE_CallGetLeftDoorStatus(&LeftDoorStatus);
	if(LeftDoorStatus == LeftDoorStatusPrev)
	{
		counter++;
		if(counter==5)
		{
			local_error |= RTE_WriteLeftDoorStatus((LeftDoorStatus^LEFT_DOOR_MODE));
			counter=0;
		}
	}	
	else
	{
		counter=0;
	}
	LeftDoorStatusPrev = LeftDoorStatus;
	return local_error;
}
