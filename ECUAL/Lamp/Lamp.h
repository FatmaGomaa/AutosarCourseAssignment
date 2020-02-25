#ifndef LAMP_INTERFACE_H
#define LAMP_INTERFACE_H


#define NUMBER_OF_LAMPS     1

#define  lAMP1_CHANNEL     0


#define   LAMP_1_PORT      'C'
#define   LAMP_1_PIN        13
#define   LAMP_1_MODE      0b0010


error_status Lamp_Init(void);

#define   LAMP_ON      1
#define   LAMP_OFF     0

error_status Lamp_Update(u8 lampChannel, u8 lampState);

#endif