/******************************/
/* Author  : Moustafa Ghareeb */
/* Version : V1.0             */
/* Date    : 08-04-2020       */
/******************************/
#ifndef RTE_H_
#define RTE_H_

#define DOOR_OPEN   	0
#define	DOOR_CLOSED  	1
#define	LIGHT_OFF  		0
#define LIGHT_ON   		1

#define RIGHT_DOOR_PORT		 PORT_A
#define RIGHT_DOOR_PIN		 PIN0
#define RIGHT_DOOR_DIR		 INPUT_PIN
#define RIGHT_DOOR_MODE		 INPUT_PULLUP

#define LEFT_DOOR_PORT		 PORT_A
#define LEFT_DOOR_PIN		 PIN1
#define LEFT_DOOR_DIR		 INPUT_PIN
#define LEFT_DOOR_MODE		 INPUT_PULLUP

#define LIGHT_PORT			 PORT_A
#define LIGHT_PIN			 PIN2
#define LIGHT_DIR			 OUTPUT_PIN

error_status RTE_WriteRightDoorStatus(u8 status);
error_status RTE_WriteLeftDoorStatus(u8 status);
error_status RTE_WriteDoorStatus(u8 status);
error_status RTE_WriteLightStatus(u8 status);
error_status RTE_ReadRightDoorStatus(u8* status);
error_status RTE_ReadLeftDoorStatus(u8* status);
error_status RTE_ReadDoorStatus(u8* status);
error_status RTE_ReadLightStatus(u8* status);
error_status RTE_CallGetRightDoorStatus(u8* status);
error_status RTE_CallGetLeftDoorStatus(u8* status);
error_status RTE_CallLightUpdate(u8 status);
void RTE_Task_02MS(void);
void RTE_Task_10MS(void);

#endif
