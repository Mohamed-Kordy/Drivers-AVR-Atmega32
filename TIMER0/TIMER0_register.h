/*
 * TIMER0_register.h
 *
 *  Created on: Jul 6, 2023
 *      Author: kordy
 */

#ifndef TIMER0_REGISTER_H_
#define TIMER0_REGISTER_H_

#define  TCCRO  *((volatile u8* )0x53)
#define  TCNTO  *((volatile u8* )0x52)
#define  OCR0   *((volatile u8* )0x5c)
#define  TIMSK  *((volatile u8* )0x59)
#define  TIFR   *((volatile u8* )0x58)


#endif /* TIMER0_REGISTER_H_ */
