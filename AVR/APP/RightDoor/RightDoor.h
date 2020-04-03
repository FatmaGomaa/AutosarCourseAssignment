/************************************************************************
 * File name: RightDoor.h
 *
 * Description: This file contains the prototypes of the right door
 * and the macros used by the user
 *
 * Author: 	Moustafa Ghareeb        
 * Date: 	26-2-2020  
 * Version: 1.1
 ***************************************************************************/
#ifndef RIGHTDOOR_H_
#define RIGHTDOOR_H_

#define	RIGHT_DOOR	DOOR1

/************************************************************************
 * Function name: RightDoor_Init
 *
 * parameters:  Input:	NA
 *              Output: NA
 *              In/out: NA
 * return: E_OK, E_NOK
 * Description: This function initializes the right door pin
 ***************************************************************************/
error_status RightDoor_Init(void);	
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
error_status RightDoor_GetStatus(u8 * status);

#endif
