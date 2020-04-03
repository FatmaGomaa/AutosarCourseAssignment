/************************************************************************
 * File name: RightDoor.c
 *
 * Description: This file contains the implementatoins of the RightDoor functionalities
 *
 * Author: 	Moustafa Ghareeb        
 * Date: 	26-2-2020  
 * Version: 1.1
 ***************************************************************************/
#include "STD_Types.h"
#include "GPIO.h"
#include "DoorSensor.h"
#include "RightDoor.h"

/************************************************************************
 * Function name: RightDoor_Init
 *
 * parameters:  Input:	NA
 *              Output: NA
 *              In/out: NA
 * return: E_OK, E_NOK
 * Description: This function initializes the right door pin
 ***************************************************************************/
error_status RightDoor_Init(void)
{
    error_status localError = E_OK;
	localError = DoorSensor_Init(RIGHT_DOOR);
	return localError;
}
/************************************************************************
 * Function name: RightDoor_GetStatus
 *
 * parameters:  Input:	NA
 *              Output: 
 *                     status
 *                     type: pointer to u8
 *                     Description: address of u8 variable that will store the state of the right door sensor.
 *              In/out: NA
 * return: E_OK, E_NOK
 * Description: This function gets the value of the right door sensor
 ***************************************************************************/
error_status RightDoor_GetStatus(u8 * status)
{
    error_status localError = E_OK;
	localError = DoorSensor_ReadStatus(RIGHT_DOOR, status);
	return localError;
}
