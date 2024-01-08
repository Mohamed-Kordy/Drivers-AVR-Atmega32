/*
 * EXTI1_Prog.c
 *
 *  Created on: Dec 8, 2023
 *      Author: Administrator
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "EXTI_register.h"
#include "EXTI1_config.h"
#include "EXTI1_interface.h"


void(* EXTI1_CallBack)(void);



void EXTI1_VoidInit(void)
{
	 SET_BIT(SREG,7);
    switch(SENSE2)
    {
    case LOW_LEVEL:
                    CLR_BIT(MCUCR ,2);
                    CLR_BIT(MCUCR ,3);
                    break;

    case ON_CHANGE:
                	SET_BIT(MCUCR ,2);
    	            CLR_BIT(MCUCR ,3);
    	            break;
    case FALLING_EDGE:
    	             CLR_BIT(MCUCR ,2);
    	             SET_BIT(MCUCR ,3);
    	             break;
    case RISING_EDGE:
    	            SET_BIT(MCUCR ,2);
    	            SET_BIT(MCUCR ,3);
                    break;
    }
    SET_BIT(GICR , 7);


}
void EXTI1_VoidSetSenseControl( u8 Copy_u8Sense)
{
	switch(Copy_u8Sense)
	    {
    	case LOW_LEVEL :
	                    CLR_BIT(MCUCR ,2);
	                    CLR_BIT(MCUCR ,3);
	                    break;

	    case ON_CHANGE :
	                	SET_BIT(MCUCR ,2);
	    	            CLR_BIT(MCUCR ,3);
	    	            break;
	    case FALLING_EDGE:
	    	             CLR_BIT(MCUCR ,2);
	    	             SET_BIT(MCUCR ,3);
	    	             break;
	    case RISING_EDGE:
	    	            SET_BIT(MCUCR ,2);
	    	            SET_BIT(MCUCR ,3);
	                    break;
	    }

}
void EXTI1_VoidSetCallBack(void(* Copy_u8CallBack)(void))
{
	EXTI1_CallBack=Copy_u8CallBack;

}





void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	EXTI1_CallBack();
}

