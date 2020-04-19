/******************************/
/* Author  : Moustafa Ghareeb */
/* Version : V1.0             */
/* Date    : 18-04-2020       */
/******************************/
#ifndef PDUROUTER_H_
#define PDUROUTER_H_

error_status PDURouter_Init(void);
void PDURouter_Send(u8 pdudata);
void PDURouter_Receive(u8* pdudata);

#endif
