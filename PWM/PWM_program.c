/*
 * PWM_program.c
 *
 *  Created on: Jul 9, 2023
 *      Author: kordy
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"

#include "PWM_config.h"
#include "PWM_interface.h"
#include "PWM_private.h"
#include "PWM_register.h"



void PWM_voidInit(void)
{
    /* Select Mode (Fast PWM) */
    CLR_BIT(TCCR1A, 0);
    SET_BIT(TCCR1A, 1);
    SET_BIT(TCCR1B, 3);
    SET_BIT(TCCR1B, 4);

    /* CLear on compare Match , Set on Top */
	CLR_BIT(TCCR1A, 6);
    SET_BIT(TCCR1A, 7);

    /* Select preScaler (8) */

    TCCR1B &=0b11111000;
    TCCR1B |=PRESCALER;
}

void PWM_voidSetTopValue( u16 Cpoy_u16value )
{
   ICR1H=Cpoy_u16value;
}
void PWM_voidSetCompareMatchValue( u16 Cpoy_u16value )
{
   OCR1A=Cpoy_u16value;
}


