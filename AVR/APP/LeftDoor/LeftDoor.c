/******************************/
/* Author  : Moustafa Ghareeb */
/* Version : V1.0             */
/* Date    : 03-04-2020       */
/******************************/
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "../../LIB/BIT_MATH/BIT_MATH.h"

#include "../../MCAL/DIO/DIO.h"
#include "../../RTE/RTE.h"
#include "LeftDoor.h"

error_status LeftDoor_Init(void)
{
	error_status local_error = E_OK;
	local_error  = RTE_LeftDoorInit();
	local_error |= RTE_WriteLeftDoorStatus(DOOR_CLOSED);
	return local_error;
}

error_status LeftDoor_GetStatus(void)
{
	error_status local_error = E_OK;
	u8 LeftDoorStatus;
	local_error  = RTE_CallGetLeftDoorStatus(&LeftDoorStatus);
	local_error |= RTE_WriteLeftDoorStatus((LeftDoorStatus^LEFT_DOOR_MODE));
	return local_error;
}