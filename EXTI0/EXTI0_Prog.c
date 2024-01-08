/*
 * EXTI0_Prog.c
 *
 *  Created on: Jul 3, 2023
 *      Author: kordy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "EXTI0_config.h"
#include "EXTI0_interface.h"
#include "EXTI0_privte.h"
#include "EXTI0_register.h"

void(* EXTI0_CallBack)(void);



void EXTI0_VoidInit(void)
{
    switch(SENSE)
    {
    case LOW_LEVEL :
                    CLR_BIT(MCUCR ,0);
                    CLR_BIT(MCUCR ,1);
                    break;

    case ON_CHANGE :
                	SET_BIT(MCUCR ,0);
    	            CLR_BIT(MCUCR ,1);
    	            break;
    case FALLING_EDGE:
    	             CLR_BIT(MCUCR ,0);
    	             SET_BIT(MCUCR ,1);
    	             break;
    case RISING_EDGE:
    	            SET_BIT(MCUCR ,0);
    	            SET_BIT(MCUCR ,1);
                    break;
    }
    SET_BIT(GICR , 6);
    SET_BIT(SREG,7);
}
void EXTI0_VoidSetSenseControl( u8 Copy_u8Sense)
{
	switch(Copy_u8Sense)
	    {
	    case LOW_LEVEL :
	                    CLR_BIT(MCUCR ,0);
	                    CLR_BIT(MCUCR ,1);
	                    break;

	    case ON_CHANGE :
	                	SET_BIT(MCUCR ,0);
	    	            CLR_BIT(MCUCR ,1);
	    	            break;
	    case FALLING_EDGE:
	    	             CLR_BIT(MCUCR ,0);
	    	             SET_BIT(MCUCR ,1);
	    	             break;
	    case RISING_EDGE:
	    	            SET_BIT(MCUCR ,0);
	    	            SET_BIT(MCUCR ,1);
	                    break;
	    }

}
void EXTI0_VoidSetCallBack(void(* Copy_u8CallBack)(void))
{
	EXTI0_CallBack=Copy_u8CallBack;

}





void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	EXTI0_CallBack();
}


