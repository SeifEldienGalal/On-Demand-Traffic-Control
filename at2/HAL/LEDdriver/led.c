/*
 * led.c
 *
 * Created: 2/10/2023 9:09:26 AM
 *  Author: SeifEldien
 */ 
#include "led.h"

void LED_init(uint8_t ledport,uint8_t ledpin)
{
	
	DIO_init(ledport ,ledpin,OUT);//output
	
}

void LED_on(uint8_t ledport,uint8_t ledpin)
{
	
	DIO_write(ledport ,ledpin,HIGH);
}
void LED_off(uint8_t ledport,uint8_t ledpin){
		DIO_write(ledport ,ledpin,LOW);

}
void LED_toggle(uint8_t ledport,uint8_t ledpin){
	DIO_toggle(ledport ,ledpin);

}