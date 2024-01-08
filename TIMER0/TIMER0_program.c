/*
 * TIMER0_program.c
 *
 *  Created on: Jul 6, 2023
 *      Author: kordy
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"

#include "TIMER0_config.h"
#include "TIMER0_interface.h"
#include "TIMER0_private.h"
#include "TIMER0_register.h"


void (* TIMER0_CallBack)(void);

void  TIMER0_voidInit(void)
{
	/* select the mode of timer*/
#if (TIMER_MODE==CTC_MODE)
	SET_BIT(TCCRO , 3);
	CLR_BIT(TCCRO , 6);
#elif (TIMER_MODE==NORMAL_MODE)
	    CLR_BIT(TCCRO , 3);
		CLR_BIT(TCCRO , 6);
#endif

		/*   select PreScale  8 */

		CLR_BIT(TCCRO , 0);
	    SET_BIT(TCCRO , 1);
	    CLR_BIT(TCCRO , 2);

	    OCR0=Compare_Value;

	    /*  ENABLE INTARUPT   */
	    SET_BIT(TIMSK , 1);
}


void  TIMER0_VoidSetCTCValue(u8 copy_u8Value)
{
	OCR0=copy_u8Value;
}


void  TIMER0_VoidSetCallBack(void (* Copy_pvCallBack)(void))
{
	TIMER0_CallBack=Copy_pvCallBack;
}

void __vector_10(void)__attribute__((signal));
void __vector_10(void)
{
	static u16 Count=0;
	Count++;
	if (Count==4000)
		{
		   TIMER0_CallBack();
			Count=0;
		}

}
