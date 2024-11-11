/*
 * led.h
 *
 * Created: 2/10/2023 9:09:40 AM
 *  Author: SeifEldien
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIOdriver/dio.h"



void LED_init(uint8_t ledport,uint8_t ledpin);
void LED_on(uint8_t ledport,uint8_t ledpin);
void LED_off(uint8_t ledport,uint8_t ledpin);
void LED_toggle(uint8_t ledport,uint8_t ledpin);




#endif /* LED_H_ */