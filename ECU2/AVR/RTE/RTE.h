/*******************************************************************************************************
 * File name: RTE.h                                                                                   *
 *                                                                                                     *
 *                                                                                                     *
 * Description: This file contains the implementation of the RTE Layer 								   *
 *                                                                                                     *
 * Author: Fatima Gomaa  | Basma AbdelHakim                                                            *
 * Date:   April 3, 2020                                                                               *
 * Version 1.0 : Initial Creation 					                                                   *
 * Version 1.1 : Adding Tasks Functions and Modifiying Lighting Function Calls in RTE to be 		   *
 * RTE_CallLightUpdate																				   *
 *******************************************************************************************************/
#ifndef RTE_H_
#define RTE_H_

#define DOOR_OPEN   	0
#define	DOOR_CLOSED  	1
#define	LIGHT_OFF  		0
#define LIGHT_ON   		1

#define LIGHT_PORT			 PORT_A
#define LIGHT_PIN			 PIN2
#define LIGHT_DIR			 OUTPUT_PIN


error_status RTE_WriteLightStatus(u8 status);
error_status RTE_ReadDoorStatus(u8* status);
error_status RTE_ReadLightStatus(u8* status);
error_status RTE_CallLightUpdate(u8 status);
void RTE_Task_10MS(void);

#endif
