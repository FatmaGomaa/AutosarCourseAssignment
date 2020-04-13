/*
 * UART.h
 *
 *  Created on: Apr 14, 2020
 *      Author: toshiba
 */

#ifndef MCAL_UART_UART_H_
#define MCAL_UART_UART_H_

#define UART_PARITY_DISABLED    0U
#define UART_PARITY_EVEN        2U
#define UART_PARITY_ODD         3U

#define UART_BUAD_4800          0U
#define UART_BUAD_9600          1U
#define UART_BUAD_115200        2U

#define UART_STOP_1_BIT         0U
#define UART_STOP_2_BIT         1U

#define UART_SYS_FREQ_8M        0U
#define UART_SYS_FREQ_12M       1U
#define UART_SYS_FREQ_16M       2U

#define UCSRB_TXCIE 			6U
#define UCSRB_RXCIE 			7U


void   UART_Init(void);
error_status     UART_TransmitDataSynch   (u8 Copy_u8Data);
error_status   UART_TransmitDataAsynch  (u8 Copy_u8Data, void(*Copy_ptr)(void));

error_status     UART_ReceiveSynch  (u8* Copy_pu8Data);
error_status   UART_ReceiveAsynch ( void(*Copy_ptr)(u8) );


#endif /* MCAL_UART_UART_H_ */
