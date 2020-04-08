/******************************/
/* Author  : Moustafa Ghareeb */
/* Version : V1.0             */
/* Date    : 07-04-2020       */
/******************************/
#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H

error_status TIMER0_Init(void);
error_status TIMER0_SetTimeus(u32 Time_us);
error_status TIMER0_SetCallBack(void(*Copy_CallBackPtr)(void));

#endif
