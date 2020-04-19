/******************************/
/* Author  : Moustafa Ghareeb */
/* Version : V1.0             */
/* Date    : 18-04-2020       */
/******************************/
#ifndef COM_H_
#define COM_H_

error_status COMM_Init(void);
error_status COMM_Send(u8 signalID,u8 data);
error_status COMM_Receive(u8 signalID,u8* data);
void COMM_TXMainFunction(void);
void COMM_RXMainFunction(void);

#endif
