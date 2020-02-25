/******************************/
/* Author  : Moustafa Ghareeb */
/* Version : V1.0             */
/* Date    : 25-2-2020        */
/******************************/
#include "STD_Types.h"
#include "RightDoor.h"

/*This function initializes the right door pin*/
error_status RightDoor_Init(void)
{
	u8 localError = E_OK;
	localError = DoorSensor_Init (RIGHT_DOOR);
	return localError;
}

/*This function gets the value of the right door sensor*/
error_status RightDoor_GetStatus(u8 * status)
{
	u8 localError = E_OK;
	localError = DoorSensor_ReadStatus(RIGHT_DOOR, status);
	return localError;
}