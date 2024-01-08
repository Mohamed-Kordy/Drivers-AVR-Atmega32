/*
 * DIO_program.c
 *
 *  Created on: Jun 30, 2023
 *      Author:kordy
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_register.h"


u8 DIO_u8SetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin , u8  Copy_u8Direction)
{
	u8 Local_u8ErrorState=0;
	if(Copy_u8Direction==DIO_u8INPUT)
	{
		switch(Copy_u8Port)
		{
		case DIO_u8PORTA: CLR_BIT(DDRA , Copy_u8Pin); break;
		case DIO_u8PORTB: CLR_BIT(DDRB , Copy_u8Pin); break;
		case DIO_u8PORTC: CLR_BIT(DDRC , Copy_u8Pin); break;
		case DIO_u8PORTD: CLR_BIT(DDRD , Copy_u8Pin); break;
		default: Local_u8ErrorState=1;

		}
	}
	else if (Copy_u8Direction==DIO_u8OUTPUT)
	{
		switch(Copy_u8Port)
		{
		case DIO_u8PORTA: SET_BIT(DDRA , Copy_u8Pin); break;
		case DIO_u8PORTB: SET_BIT(DDRB , Copy_u8Pin); break;
		case DIO_u8PORTC: SET_BIT(DDRC , Copy_u8Pin); break;
		case DIO_u8PORTD: SET_BIT(DDRD , Copy_u8Pin); break;
		default: Local_u8ErrorState=1;

		}
	}
	else
	{
		Local_u8ErrorState=1;
	}

	return Local_u8ErrorState;
}



u8 DIO_u8SetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8  Copy_u8Value)
{
	u8 Local_u8ErrorState=0;
		if(Copy_u8Value==DIO_u8LOW)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA: CLR_BIT(PORTA , Copy_u8Pin); break;
			case DIO_u8PORTB: CLR_BIT(PORTB , Copy_u8Pin); break;
			case DIO_u8PORTC: CLR_BIT(PORTC , Copy_u8Pin); break;
			case DIO_u8PORTD: CLR_BIT(PORTD , Copy_u8Pin); break;
			default: Local_u8ErrorState=1;

			}
		}
		else if (Copy_u8Value==DIO_u8HIGH)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA: SET_BIT(PORTA , Copy_u8Pin); break;
			case DIO_u8PORTB: SET_BIT(PORTB , Copy_u8Pin); break;
			case DIO_u8PORTC: SET_BIT(PORTC , Copy_u8Pin); break;
			case DIO_u8PORTD: SET_BIT(PORTD , Copy_u8Pin); break;
			default: Local_u8ErrorState=1;

			}
		}
		else
		{
			Local_u8ErrorState=1;
		}

		return Local_u8ErrorState;
}











u8 DIO_u8SetPortDirection(u8 Copy_u8Port , u8  Copy_u8Direction)
{
	u8 Local_u8ErrorState=0;
	switch(Copy_u8Port)
	{
	case DIO_u8PORTA: DDRA=Copy_u8Direction; break;
	case DIO_u8PORTB: DDRB=Copy_u8Direction; break;
	case DIO_u8PORTC: DDRC=Copy_u8Direction; break;
	case DIO_u8PORTD: DDRD=Copy_u8Direction; break;
	default : Local_u8ErrorState=1;

	}
	return Local_u8ErrorState;
}

u8 DIO_u8SetPortValue(u8 Copy_u8Port , u8  Copy_u8Value)
{
	u8 Local_u8ErrorState=0;
	switch(Copy_u8Port)
	{
	case DIO_u8PORTA: PORTA=Copy_u8Value; break;
	case DIO_u8PORTB: PORTB=Copy_u8Value; break;
	case DIO_u8PORTC: PORTC=Copy_u8Value; break;
	case DIO_u8PORTD: PORTD=Copy_u8Value; break;
	default : Local_u8ErrorState=1;

	}
	return Local_u8ErrorState;
}

u8 DIO_u8GetPortValue(u8 Copy_u8Port)
{
	u8 Result=0;
	switch(Copy_u8Port)
		{
		case DIO_u8PORTA: Result=PINA; break;
		case DIO_u8PORTB: Result=PINB; break;
		case DIO_u8PORTC: Result=PINC; break;
		case DIO_u8PORTD: Result=PIND; break;
		}
	return Result;
}


u8 DIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	u8 Result;
	switch(Copy_u8Port)
	{
	case DIO_u8PORTA : Result =GET_BIT(PINA , Copy_u8Pin); break;
	case DIO_u8PORTB : Result =GET_BIT(PINB , Copy_u8Pin); break;
	case DIO_u8PORTC : Result =GET_BIT(PINC , Copy_u8Pin); break;
	case DIO_u8PORTD : Result =GET_BIT(PIND , Copy_u8Pin); break;
	}

	return Result;
}
