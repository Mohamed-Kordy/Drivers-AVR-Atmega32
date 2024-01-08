/*
 * DIO_interface.h
 *
 *  Created on: Jun 30, 2023
 *      Author: kordy
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


u8 DIO_u8SetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin , u8  Copy_u8Direction);
u8 DIO_u8SetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8  Copy_u8Value);


u8 DIO_u8SetPortDirection(u8 Copy_u8Port , u8  Copy_u8Direction);
u8 DIO_u8SetPortValue(u8 Copy_u8Port , u8  Copy_u8Value);

u8 DIO_u8GetPortValue(u8 Copy_u8Port);
u8 DIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin);

#define DIO_u8PORTA     1
#define DIO_u8PORTB     2
#define DIO_u8PORTC     3
#define DIO_u8PORTD     4

#define DIO_u8INPUT     0
#define DIO_u8OUTPUT    1

#define DIO_u8LOW       0
#define DIO_u8HIGH      1

#define DIO_u8PIN0      0




#endif /* DIO_INTERFACE_H_ */
