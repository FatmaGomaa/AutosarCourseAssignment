/******************************/
/* Author  : Moustafa Ghareeb */
/* Version : V1.0             */
/* Date    : 25-2-2020        */
/******************************/

#define	RIGHT_DOOR	DOOR1

/*This function initializes the right door pin*/
error_status RightDoor_Init(void);	
/*This function gets the value of the right door sensor*/
error_status RightDoor_GetStatus(u8 * status);