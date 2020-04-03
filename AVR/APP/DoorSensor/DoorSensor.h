/************************************************************************
 * File name: DoorSensor.h
 *
 *
 * Description: This file contains the prototypes of the doorSensor driver
 * and the macros used by the user
 *
 * owner: Mohanad Fawzy Sallam        
 * date: 26/2/2020
 * version 1.1
 ***************************************************************************/
#ifndef DOORSENSOR_H_
#define DOORSENSOR_H_
/*Door sensors macros */
#define DOOR1 11 
#define DOOR2 22
/*Door 1 initial configurations*/
#define DOOR1_PORT PORT_F
#define DOOR1_PIN PIN_4
#define DOOR1_OPERATION_MODE IP_PULL_UP
/*Door 2 initial configurations*/
#define DOOR2_PORT PORT_F
#define DOOR2_PIN  PIN_0
#define DOOR2_OPERATION_MODE IP_PULL_UP
/************************************************************************
 * Function name: DoorSensor_Init
 *
 * parameters:  Input:
 *                 doorChannel
 *                     type: u8
 *                     Description: DoorSensor number  (DOOR1,DOOR2)
 *
 *              Output: NA
 *              In/out: NA
 * return: E_OK, E_NOK
 * Description: a function to initialize the specified door sensor based on the given initial configuraton
 ***************************************************************************/
error_status DoorSensor_Init (u8 doorChannel);
/************************************************************************
 * Function name: DoorSensor_ReadStatus
 *
 * parameters:  Input:
 *                 doorChannel
 *                     type: u8
 *                     Description: DoorSensor number  (DOOR1,DOOR2)
 *              Output: 
 *                     status
 *                     type: pointer to u8
 *                     Description: address of u8 variable that will store the state of the door sensor.
 *              In/out: NA
 * return: E_OK, E_NOK
 * Description: a function to get the state of the door sensor
 ***************************************************************************/

/*Dscription: This API shall get the read of the sensor GPIO pin  based on the given door channel*/
error_status DoorSensor_ReadStatus (u8 doorChannel,u8 * status);

#endif
