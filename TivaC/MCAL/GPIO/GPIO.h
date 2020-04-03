/************************************************************************
 * File name: GPIO.h
 *
 *
 * Description: This file contains the prototypes of the GPIO driver
 * and the macros used by the user
 *
 * owner: Mostafa Ghareeb
 *        Mohanad Fawzy Sallam
 * date: 26/2/2020
 * version 1.1
 *
 ***************************************************************************/
#ifndef GPIO_H_
#define GPIO_H_

/* Ports Numbers*/
#define PORT_A 0x40004000
#define PORT_B 0x40005000
#define PORT_C 0x40006000
#define PORT_D 0x40007000
#define PORT_E 0x40024000
#define PORT_F 0x40025000
/* Pins Numbers*/
#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7
/* GPIO operation Modes*/
#define IP_PULL_UP   1
#define IP_PULL_DOWN 2
#define OP_PUSH_PULL 3
 /*GPIO OUTPUT Values*/
#define HIGH 1
#define LOW 0 
/************************************************************************
 * Function name: GPIO_Init
 *
 * parameters:  Input:
 *                 Port
 *                     type: u32
                        Description: GPIO port number (PORT_A,PORT_B,PORT_C,PORT_D,PORT_E,PORT_F)
 *                 Pin
 *                     type: u8
 *                     Description: GPIO pin number (PIN_0 .. PIN_7)
 *                 Mode
 *                     type: u8
 *                     Description: GPIO pin mode (IP_PULL_UP,IP_PULL_DOWN,OP_PUSH_PULL)
 *
 *              Output: NA
 *              In/out: NA
 * return: E_OK, E_NOK
 * Description: a function to initialize all the GPIO Groups in the configurations
 ***************************************************************************/
error_status GPIO_Init (u32 Port, u8 Pin, u8 Mode);
/************************************************************************
 * Function name: GPIO_WritePin
 *
 * parameters:  Input:
 *                 Port
 *                     type: u32
                        Description: GPIO port number (PORT_A,PORT_B,PORT_C,PORT_D,PORT_E,PORT_F)
 *                 Pin
 *                     type: u8
 *                     Description: GPIO pin number (PIN_0 .. PIN_7)
 *                 Value
 *                     type: u8
 *                     Description: GPIO pin output value (IP_PULL_UP,IP_PULL_DOWN,OP_PUSH_PULL)
 *
 *              Output: NA
 *              In/out: NA
 * return: E_OK, E_NOK
 * Description: a function to set value of the specified pin
 ***************************************************************************/
error_status GPIO_WritePin (u32 Port, u8 Pin, u8 Value);
/************************************************************************
 * Function name: GPIO_ReadPin
 *
 * parameters:  Input:
 *                 Port
 *                     type: u32
 *                     Description: GPIO port number (PORT_A,PORT_B,PORT_C,PORT_D,PORT_E,PORT_F)
 *                 Pin
 *                     type: u8
 *                     Description: GPIO pin number (PIN_0 .. PIN_7)
 *              Output: 
 *                     Data
 *                     type: pointer to u8
 *                     Description: address of u8 variable that will store the specified pin reading.
 *              In/out: NA
 * return: E_OK, E_NOK
 * Description: a function to get reading of the GPIO pin value
 ***************************************************************************/
error_status GPIO_ReadPin (u32 Port, u8 Pin, u8 * Data);

#endif
