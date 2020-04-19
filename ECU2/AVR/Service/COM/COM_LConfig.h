/******************************/
/* Author  : Moustafa Ghareeb */
/* Version : V1.0             */
/* Date    : 18-04-2020       */
/******************************/
#ifndef COM_CONFIG_H_
#define COM_CONFIG_H_

#define MAX_SYSTEM_PDUS_NUM			1
#define MAX_SYSTEM_SIGNALS_NUM		1
#define MAX_SIGNALS_PER_PDU			6

typedef struct PDU_t
{
	u8 PDU_ID;
	u8 PDU_SIGNALS_NUM;
	u8 PDU_SIGNALS_ID[MAX_SIGNALS_PER_PDU];
}PDU_t;

typedef struct Signals_t
{
	u8 Signal_Bits_Start;
	u8 Signal_Bits_Length;
}Signals_t;

extern PDU_t	 	SysPDU[MAX_SYSTEM_PDUS_NUM];
extern Signals_t 	SysSignals[MAX_SYSTEM_SIGNALS_NUM];

#endif
