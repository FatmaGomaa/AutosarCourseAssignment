/******************************/
/* Author  : Moustafa Ghareeb */
/* Version : V1.1             */
/* Date    : 26-2-2020        */
/******************************/
#include "STD_Types.h"
#include "GPIO.h"
#include "DoorSensor.h"
#include "LeftDoor.h"

/*This function initializes the left door pin*/
error_status LeftDoor_Init(void)
{
    error_status localError = E_OK;
	localError = DoorSensor_Init(LEFT_DOOR);
	return localError;
}

/*This function gets the value of the left door sensor*/
error_status LeftDoor_GetStatus(u8 * status)
{
    error_status localError = E_OK;
	localError = DoorSensor_ReadStatus(LEFT_DOOR, status);
	return localError;
}
