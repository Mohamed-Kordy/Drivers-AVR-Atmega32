/*
 * EXTI1_interface.h
 *
 *  Created on: Dec 8, 2023
 *      Author: Administrator
 */

#ifndef EXTI1_INTERFACE_H_
#define EXTI1_INTERFACE_H_

void EXTI1_VoidInit(void);
void EXTI1_VoidSetSenseControl( u8 Copy_u8Sense);
void EXTI1_VoidSetCallBack(void(* Copy_u8CallBack)(void));


#define LOW_LEVEL      0
#define RISING_EDGE    1
#define FALLING_EDGE   2
#define ON_CHANGE      3

#endif /* EXTI1_INTERFACE_H_ */
