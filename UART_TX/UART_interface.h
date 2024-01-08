/*
 * UART_interface.h
 *
 *  Created on: Jul 10, 2023
 *      Author: kordy
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_voidInit(void);
void UART_voidSendData(u8 Copy_u8Date);
u8 UART_u8ReceiveData(void);

#endif /* UART_INTERFACE_H_ */
