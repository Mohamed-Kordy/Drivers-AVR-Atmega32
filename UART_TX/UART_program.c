/*
 * UART_program.c
 *
 *  Created on: Jul 10, 2023
 *      Author: kordy
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"

#include "UART_config.h"
#include "UART_interface.h"
#include "UART_private.h"
#include "UART_register.h"


void UART_voidInit(void)
{

	u8 Local_UCSRC=0;
	/* receiver and Tx enable */
   SET_BIT(UCSRB, 4);
   SET_BIT(UCSRB, 3);

   /* select size of data (8 bit)*/
   CLR_BIT(UCSRB, 2);
   SET_BIT(Local_UCSRC, 2);
   SET_BIT(Local_UCSRC, 1);

   /* Select UCSRC Register*/
   SET_BIT(Local_UCSRC, 7);

   /* Select Asynchronous mode */
   CLR_BIT(Local_UCSRC, 6);

   /* no parity */
   CLR_BIT(Local_UCSRC, 5);
   CLR_BIT(Local_UCSRC, 4);

   /*1 stop bit */
   CLR_BIT(Local_UCSRC, 3);
   /*Access the whole Register */
   UCSRC=Local_UCSRC;

   /*Baude Rate =9600 */
   UBRRL = 51;


}


void UART_voidSendData(u8 Copy_u8Date)
{

	while((GET_BIT(UCSRA , 5))!=1)
	{
		asm("NOP");
	}
	UDR=Copy_u8Date;
}
u8 UART_u8ReceiveData(void)
{
	while((GET_BIT(UCSRA , 7))!=1)
		{
			asm("NOP");
		}
	return UDR ;
}
