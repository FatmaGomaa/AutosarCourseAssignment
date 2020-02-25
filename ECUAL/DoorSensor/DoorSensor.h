/********************************
*Author: Mohanad Fawzy Sallam   *
*Version: v01                   *
*Date: 25/02/2020               *
*********************************/
#define DOOR1 11 
#define DOOR2 22
/*Door 1 initial configurations*/
#define DOOR1_PORT PORT_A
#define DOOR1_PIN PIN_5
#define DOOR1_OPERATION_MODE IP_PULL_UP
/*Door 2 initial configurations*/
#define DOOR2_PORT PORT_A
#define DOOR2_PIN  PIN_6
#define DOOR2_OPERATION_MODE IP_PULL_UP

/*Dscription: This API shall initalize DoorSensor GPIO Pin based on the given door channel*/
error_status DoorSensor_Init (u8 doorChannel);
/*Dscription: This API shall get the read of the sensor GPIO pin  based on the given door channel*/
error_status DoorSensor_ReadStatus (u8 doorChannel,u8 * status);
