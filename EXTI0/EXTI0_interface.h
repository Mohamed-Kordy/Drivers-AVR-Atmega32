/*
 * EXTI0_interface.h
 *
 *  Created on: Jul 3, 2023
 *      Author: kordy
 */

#ifndef EXTI0_INTERFACE_H_
#define EXTI0_INTERFACE_H_

void EXTI0_VoidInit(void);
void EXTI0_VoidSetSenseControl( u8 Copy_u8Sense);
void EXTI0_VoidSetCallBack(void(* Copy_u8CallBack)(void));


#define LOW_LEVEL      0
#define RISING_EDGE    1
#define FALLING_EDGE   2
#define ON_CHANGE      3



#endif /* EXTI0_INTERFACE_H_ */
