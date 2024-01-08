/*
 * TIMER0_interface.h
 *
 *  Created on: Jul 6, 2023
 *      Author: kordy
 */

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

void  TIMER0_voidInit(void);
void  TIMER0_VoidSetCTCValue(u8 copy_u8Value);
void  TIMER0_VoidSetCallBack(void (* Copy_pvCallBack)(void));

#endif /* TIMER0_INTERFACE_H_ */
