/******************************/
/* Author  : Moustafa Ghareeb */
/* Version : V1.0             */
/* Date    : 03-04-2020       */
/******************************/
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "../../LIB/BIT_MATH/BIT_MATH.h"

#include "../../MCAL/DIO/DIO.h"
#include "../../RTE/RTE.h"
#include "RightDoor.h"

error_status RightDoor_Init(void)
{
	error_status local_error = E_OK;
	local_error  = RTE_RightDoorInit();
	local_error |= RTE_WriteRightDoorStatus(DOOR_CLOSED);
	return local_error;
}

error_status RightDoor_GetStatus(void)
{
	error_status local_error = E_OK;
	u8 RightDoorStatus;
	local_error  = RTE_CallGetRightDoorStatus(&RightDoorStatus);
	local_error |= RTE_WriteRightDoorStatus((RightDoorStatus^RIGHT_DOOR_MODE));
	return local_error;
}
