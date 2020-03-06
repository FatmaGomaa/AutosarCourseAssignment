/************************************************************************
 * File name: LeftDoor.c
 *
 *
 * Description: This file contains the implementatoins of the LeftDoor functionalities
 *
 * Author: 	Moustafa Ghareeb        
 * Date: 	26-2-2020  
 * Version: 1.1
 ***************************************************************************/
#include "STD_Types.h"
#include "GPIO.h"
#include "DoorSensor.h"
#include "LeftDoor.h"
/************************************************************************
 * Function name: LeftDoor_Init
 *
 * parameters:  Input:	NA
 *              Output: NA
 *              In/out: NA
 * return: E_OK, E_NOK
 * Description: This function initializes the left door pin
 ***************************************************************************/
error_status LeftDoor_Init(void)
{
    error_status localError = E_OK;
	localError = DoorSensor_Init(LEFT_DOOR);
	return localError;
}
/************************************************************************
 * Function name: LeftDoor_GetStatus
 *
 * parameters:  Input:	NA
 *              Output: 
 *                     status
 *                     type: pointer to u8
 *                     Description: address of u8 variable that will store the state of the left door sensor.
 *              In/out: NA
 * return: E_OK, E_NOK
 * Description: This function gets the value of the left door sensor
 ***************************************************************************/
error_status LeftDoor_GetStatus(u8 * status)
{
    error_status localError = E_OK;
	localError = DoorSensor_ReadStatus(LEFT_DOOR, status);
	return localError;
}
