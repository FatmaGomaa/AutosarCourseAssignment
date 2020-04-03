/******************************/
/* Author  : Moustafa Ghareeb */
/* Version : V1.0             */
/* Date    : 03-04-2020       */
/******************************/
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "../../LIB/BIT_MATH/BIT_MATH.h"

#include "../../MCAL/DIO/DIO.h"
#include "../../RTE/RTE.h"
#include "DoorContact.h"

error_status DoorContact_Init(void)
{
	error_status local_error = E_OK;
	local_error = RTE_WriteDoorStatus(DOOR_CLOSED);
	return local_error;
}

error_status DoorContact_UpdateStatus(void)
{
	error_status local_error = E_OK;
	u8 RightDoorStatus;
	u8 LeftDoorStatus;
	u8 DoorStatus;
	local_error  = RTE_ReadRightDoorStatus(&RightDoorStatus);
	local_error |= RTE_ReadLeftDoorStatus(&LeftDoorStatus);
	DoorStatus = RightDoorStatus & LeftDoorStatus;
	local_error |= RTE_WriteDoorStatus(DoorStatus);
	return local_error;
}
