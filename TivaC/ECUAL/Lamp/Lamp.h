#ifndef LAMP_INTERFACE_H
#define LAMP_INTERFACE_H


#define NUMBER_OF_LAMPS     1

#define  lAMP1_CHANNEL     0


#define   LAMP_1_PORT      PORT_F
#define   LAMP_1_PIN       PIN_1
#define   LAMP_1_MODE      OP_PUSH_PULL


error_status Lamp_Init(void);

#define   LAMP_ON      1
#define   LAMP_OFF     0

error_status Lamp_Update(u8 lampChannel, u8 lampState);

#endif
