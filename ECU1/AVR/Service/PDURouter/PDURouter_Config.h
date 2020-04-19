/******************************/
/* Author  : Moustafa Ghareeb */
/* Version : V1.0             */
/* Date    : 18-04-2020       */
/******************************/
#ifndef PDUROUTER_CONFIG_H_
#define PDUROUTER_CONFIG_H_

#define MAX_PROTOCOL_NUM 		1
#define MAX_PDU_PER_PROTOCOL 	1

typedef struct Protocol_t
{
	u8 Protocol_ID;
	u8 Protocol_PDU_NUM;
	u8 Protocol_PDU_IDs[MAX_PDU_PER_PROTOCOL];
	error_status (*Protocol_Send)(u8);
	error_status (*Protocol_Receive)(u8*);
}Protocol_t;

extern Protocol_t	SysProtocols[MAX_PROTOCOL_NUM];

#endif
