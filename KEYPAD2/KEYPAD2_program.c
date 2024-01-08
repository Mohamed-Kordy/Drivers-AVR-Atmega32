/*
 * KEYPAD2_program.c
 *
 *  Created on: Aug 30, 2023
 *      Author: kordy
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_register.h"

#include "KEYPAD2_config.h"
#include "KEYPAD2_interface.h"

void KEYPAD2_VoidInit()
{
	DIO_u8SetPortDirection(KEYPADPORT,11110000);
}

u8 KEYPAD2_u8Scankey()

{

	u8 key='a';

	while(key=='a')

	{
		_delay_ms(80);
		key=KEYPAD2_u8keycheck();


	}

	return key;

}
u8 KEYPAD2_u8keycheck()

{

	DIO_u8SetPortValue(KEYPADPORT,0b11101111);

	_delay_ms(10);

	if((DIO_u8GetPortValue(KEYPADPORT)&0b00000001)==0)

	{

		return '7';

	}

	if((DIO_u8GetPortValue(KEYPADPORT)&0b00000010)==0)

	{

		return '8';

	}

	if((DIO_u8GetPortValue(KEYPADPORT)&0b00000100)==0)

	{

		return '9';


	}
	if((DIO_u8GetPortValue(KEYPADPORT)&0b00001000)==0)
	{
			return 'A';
	}

	DIO_u8SetPortValue(KEYPADPORT,0b11011111);

	_delay_ms(10);

	if((DIO_u8GetPortValue(KEYPADPORT)&0b00000001)==0)

	{

		return '4';

	}

	if((DIO_u8GetPortValue(KEYPADPORT)&0b00000010)==0)

	{

		return '5';

	}

	if((DIO_u8GetPortValue(KEYPADPORT)&0b00000100)==0)

	{

		return '6';

	}
	if((DIO_u8GetPortValue(KEYPADPORT)&0b00001000)==0)
	{
		return 'B';
	}

	DIO_u8SetPortValue(KEYPADPORT, 0b10111111);

	_delay_ms(10);

	if((DIO_u8GetPortValue(KEYPADPORT)&0b00000001)==0)

	{

		return '1';

	}

	if((DIO_u8GetPortValue(KEYPADPORT)&0b00000010)==0)

	{

		return '2';

	}

	if((DIO_u8GetPortValue(KEYPADPORT)&0b00000100)==0)

	{

		return '3';

	}
	if((DIO_u8GetPortValue(KEYPADPORT)&0b00001000)==0)
	{
		return'C';
	}

	DIO_u8SetPortValue(KEYPADPORT,0b01111111);

	_delay_ms(10);

	if((DIO_u8GetPortValue(KEYPADPORT)&0b00000001)==0)

	{

		return '*';

	}

	if((DIO_u8GetPortValue(KEYPADPORT)&0b00000010)==0)

	{

		return '0';

	}

	if((DIO_u8GetPortValue(KEYPADPORT)&0b00000100)==0)

	{

		return '#';

	}
	if((DIO_u8GetPortValue(KEYPADPORT)&0b00001000)==0)
	{
		return'D';
	}


	return 'a';

}
