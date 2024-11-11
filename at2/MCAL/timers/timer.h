/*
 * timer.h
 *
 * Created: 2/12/2023 10:28:57 AM
 *  Author: SeifEldien
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utilities/registers.h"
#include "../interrupts/interrupt.h"
#include "../../Utilities/macro.h"



#define init_value 11


// TIMER0 function prototypes
void TIMER_0_init();
void TIMER_0_set_init_value(uint8_t val);
void TIMER_0_start();
void TIMER_0_stop();
void TIMER_0_reset();

void TIMER_0_delay();


// Callback function to access LED_toggle function from upper layer (HARDWARE ABSTRACTION LAYER)
void setcallback(void (*cbvar)(uint8_t portname, uint8_t pinnum));


#endif /* TIMER_H_ */