/*
 * ADC_program.c
 *
 *  Created on: Jul 5, 2023
 *      Author: kordy
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_register.h"

void ADC_voidInit(void)
{
	/* select Vref */

	switch(ADC_VREF)
	{
	case AREF :
		CLR_BIT(ADMUX , 6);
		CLR_BIT(ADMUX , 7);
		break;
	case AVCC:
		SET_BIT(ADMUX , 6);
		CLR_BIT(ADMUX , 7);
		break;
	case INT2_5:
		SET_BIT(ADMUX , 6);
		SET_BIT(ADMUX , 7);
		break;
	}
	CLR_BIT(ADMUX , 5);

	/* Enable ADC */

	SET_BIT(ADCSRA ,7);

	/*set the prescaler (division/2) */

	CLR_BIT(ADCSRA ,0);
	CLR_BIT(ADCSRA ,1);
	CLR_BIT(ADCSRA ,2);

}
 u16 ADC_u16ReadChannel(u8 Copy_u8Channel)
{

	/* select  the channel*/

     ADMUX &=0b11100000;
     ADMUX |=Copy_u8Channel;

     /* start conversion  */

     SET_BIT(ADCSRA , 6);

     while ((GET_BIT(ADCSRA , 4))!=1)
     {
    	 asm("NOP");
     }
     /* clear the flag*/
    SET_BIT(ADCSRA , 4);


    return ADC ;


}
