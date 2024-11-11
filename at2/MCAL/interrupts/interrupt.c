/*
 * interrupt.c
 *
 * Created: 2/12/2023 10:23:21 AM
 *  Author: SeifEldien
 */ 
#include "interrupt.h"

void INTERRUPT_global_init(){
//activating the interrupt in the register's status
	pin_choose(SREG, 7);
}



void INTERRUPT_T0_ovf_init(){
	//turning on the t0_ovf interrupt
	pin_choose(TIMSK, 0);
}



void INTERRUPT_0_init(){
	pin_choose(MCUCR, 0);
	pin_choose(MCUCR, 1);
	pin_choose(GICR, 6);
}


