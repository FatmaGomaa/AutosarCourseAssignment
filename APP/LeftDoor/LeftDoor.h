/******************************/
/* Author  : Moustafa Ghareeb */
/* Version : V1.1             */
/* Date    : 26-2-2020        */
/******************************/
#ifndef LEFTDOOR_H_
#define LEFTDOOR_H_

#define	LEFT_DOOR	DOOR2

/*This function initializes the left door pin*/
error_status LeftDoor_Init(void);	
/*This function gets the value of the left door sensor*/
error_status LeftDoor_GetStatus(u8 * status);

#endif
