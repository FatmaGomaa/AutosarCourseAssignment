/********************************
*Author: Mohanad Fawzy Sallam   *
*Version: v1.1                  *
*Date: 26/02/2020               *
*********************************/
#ifndef DOORSENSOR_H_
#define DOORSENSOR_H_

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

/*Dscription: This API shall initalize DoorSensor GPIO Pin based on the given door channel*/
error_status DoorSensor_Init (u8 doorChannel);
/*Dscription: This API shall get the read of the sensor GPIO pin  based on the given door channel*/
error_status DoorSensor_ReadStatus (u8 doorChannel,u8 * status);

#endif
