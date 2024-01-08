/*
 * PWM_register.h
 *
 *  Created on: Jul 9, 2023
 *      Author: kordy
 */

#ifndef PWM_REGISTER_H_
#define PWM_REGISTER_H_

#define TCCR1A   *((volatile u8*)0x4f)
#define TCCR1B   *((volatile u8*)0x4e)
#define TCNT1    *((volatile u16*)0x4c)
#define OCR1A    *((volatile u16*)0x4a)
#define ICR1H    *((volatile u16*)0x46)
#define TIMSK    *((volatile u8*)0x59)
#define TIFR     *((volatile u8*)0x58)




#endif /* PWM_REGISTER_H_ */
