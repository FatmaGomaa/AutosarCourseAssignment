/******************************/
/* Author  : Moustafa Ghareeb */
/* Version : V1.0             */
/* Date    : 25-2-2020        */
/******************************/

#define	LEFT_DOOR	DOOR2

/*This function initializes the left door pin*/
error_status LeftDoor_Init(void);	
/*This function gets the value of the left door sensor*/
error_status LeftDoor_GetStatus(u8 * status);