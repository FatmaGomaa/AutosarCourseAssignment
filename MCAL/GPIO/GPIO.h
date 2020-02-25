/********************************
*Author: Mostafa Ghareeb        *
*        Mohanad Fawzy Sallam   * 
*Version: v01                   *
*Date: 25/02/2020               *
*********************************/
/* Ports Numbers*/
#define PORT_A 1
#define PORT_B 2
#define PORT_C 3
#define PORT_D 4
#define PORT_E 5
#define PORT_F 6
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
 
 

/*Dscription: This API shall initalize GPIO Configuration Mode*/
error_status GPIO_Init (u8 Port, u8 Pin, u8 Mode);
/*Dscription: This API shall Write GPIO pin output value*/
error_status GPIO_WritePin (u8 Port, u8 Pin, u8 Value);
/*Dscription: This API shall read GPIO pin input value*/*/
error_status GPIO_ReadPin (u8 Port, u8 Pin, u8 * Data);