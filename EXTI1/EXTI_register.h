/*
 * EXTI0_register.h
 *
 *  Created on: Jul 3, 2023
 *      Author: kordy
 */

#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

#define MCUCR  *((volatile u8*)0x55)
#define MCUCSR *((volatile u8*)0x54)
#define GICR   *((volatile u8*)0x5B)
#define GIFR   *((volatile u8*)0x5A)
#define SREG   *((volatile u8*)0x5F)


#endif /* EXTI_REGISTER_H_ */
