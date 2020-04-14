/*******************************************************************************************************
 * File name: DIO.c                                                                                    *
 *                                                                                                     *
 *                                                                                                     *
 * Description: This file contains the implementation of the DIO driver in MCAL Layer 				   *
 *                                                                                                     *
 * Author: Basma AbdelHakim                                                            				   *
 * Date:   April 3, 2020                                                                               *
 * Version 1.0 : Initial Creation 					                                                   *
 *******************************************************************************************************/
#ifndef DIO_H_
#define DIO_H_

#define INPUT_PIN		0
#define OUTPUT_PIN		1
#define INPUT_FLOATING  0
#define INPUT_PULLUP  	1
#define OUTPUT_LOW		0
#define OUTPUT_HIGH		1
#define PORT_A	'A'
#define PORT_B	'B'
#define PORT_C	'C'
#define PORT_D	'D'
#define PIN0	0
#define PIN1	1
#define PIN2	2
#define PIN3	3
#define PIN4	4
#define PIN5	5
#define PIN6	6
#define PIN7	7

error_status DIO_SetPinDir(u8 Port,u8 Pin,u8 Dir);
error_status DIO_SetPinValue(u8 Port,u8 Pin,u8 Val);
error_status DIO_GetPinValue(u8 Port,u8 Pin,u8* Val);

#endif
