/*
 * interrupt.h
 *
 * Created: 2/12/2023 10:23:09 AM
 *  Author: SeifEldien
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_
#include "../../Utilities/macro.h"
#include "../../Utilities/registers.h"

#define ISR(INT_VECT) void INT_VECT(void) __attribute__((signal,used));\
void INT_VECT(void)

#define EXT_INT_0	__vector_1
#define EXT_INT_1	__vector_2
#define EXT_INT_2	__vector_3
#define TIMER_0_OVF __vector_11


//interrupt functions 
void INTERRUPT_global_init();
void INTERRUPT_0_init();
void INTERRUPT_T0_ovf_init();

#endif /* INTERRUPT_H_ */