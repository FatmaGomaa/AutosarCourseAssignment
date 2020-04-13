/*****************************************************************/
/* Author    : Mohanad Sallam                                     */
/* Date      : 9 March 2020                                      */
/* Version   : V01                                               */
/*****************************************************************/
#ifndef _UART_INTERFACE_H
#define _UART_INTERFACE_H

void   UART_Init(void);
error_status     UART_TransmitDataSynch   (u8 Copy_u8Data);
error_status   UART_TransmitDataAsynch  (u8 Copy_u8Data, void(*Copy_ptr)(void));

error_status     UART_ReceiveSynch  (u8* Copy_pu8Data);
error_status   UART_ReceiveAsynch ( void(*Copy_ptr)(u8) );

#endif
