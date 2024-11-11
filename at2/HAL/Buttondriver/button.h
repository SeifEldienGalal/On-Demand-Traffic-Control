/*
 * button.h
 *
 * Created: 2/10/2023 9:12:30 AM
 *  Author: SeifEldien
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../LEDdriver/led.h"
#include "../../MCAL/timers/timer.h"
#include "../../MCAL/interrupts/interrupt.h"

//#define  BUTTON_1_PORT PORT_C
//#define  BUTTON_1_PIN   0
//type definition

//#define  LOW 0
//#define  HIGH 1

//button initialize
void BUTTON_init(uint8_t buttonPort,uint8_t buttonPin);

//button read to read the value on the pin
void BUTTON_read(uint8_t buttonPort,uint8_t buttonPin,uint8_t *value);



#endif /* BUTTON_H_ */