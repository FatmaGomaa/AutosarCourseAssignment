/******************************/
/* Author  : Moustafa Ghareeb */
/* Version : V1.1             */
/* Date    : 26-2-2020        */
/******************************/
#ifndef RIGHTDOOR_H_
#define RIGHTDOOR_H_

#define	RIGHT_DOOR	DOOR1

/*This function initializes the right door pin*/
error_status RightDoor_Init(void);	
/*This function gets the value of the right door sensor*/
error_status RightDoor_GetStatus(u8 * status);

#endif
