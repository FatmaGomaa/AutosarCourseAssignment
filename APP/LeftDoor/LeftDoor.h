/************************************************************************
 * File name: LeftDoor.h
 *
 * Description: This file contains the prototypes of the left door
 * and the macros used by the user
 *
 * Author: 	Moustafa Ghareeb        
 * Date: 	26-2-2020  
 * Version: 1.1
 ***************************************************************************/
#ifndef LEFTDOOR_H_
#define LEFTDOOR_H_

#define	LEFT_DOOR	DOOR2

/************************************************************************
 * Function name: LeftDoor_Init
 *
 * parameters:  Input:	NA
 *              Output: NA
 *              In/out: NA
 * return: E_OK, E_NOK
 * Description: This function initializes the left door pin
 ***************************************************************************/
error_status LeftDoor_Init(void);	
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
error_status LeftDoor_GetStatus(u8 * status);

#endif
