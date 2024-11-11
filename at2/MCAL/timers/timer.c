/*
 * timer.c
 *
 * Created: 2/12/2023 10:28:47 AM
 *  Author: SeifEldien
 */ 

#include "TIMER.h"



uint8_t counting;
uint8_t firstpress;

uint8_t ovf;

//Function pointer that saves the address of the function that was supplied to the callback function.
void static (*callbackvar)(uint8_t portname, uint8_t pinnum);

// Executes the address of the toggle function from the top layers in timer 0 overflow to cause the yellow lights to flicker.
void setcallback(void (*cbvar)(uint8_t portname, uint8_t pinnum)){
	callbackvar = cbvar;
}




//selecting normal mode
void TIMER_0_init(){
	TCCR0 |= ((0<<3) | (0<<6));
	
	TIMER_0_set_init_value(init_value);
}

//assigning a starting value following a computation
void TIMER_0_set_init_value(uint8_t val){
	TCNT0 = val;
}

	// Selecting the 1024 prescaler
void TIMER_0_start(){
	TCCR0 |= ((1<<0) | (1<<2));
	
	// Waiting the overflow counter to reach 20
	while(ovf <20);
}


void TIMER_0_stop(){
	// Setting control register to 0 (no prescaler) to stop the timer
	TCCR0 = 0;
	
	// Resetting overflow counter
	ovf = 0;
}

// Delay function that perform the 5 seconds delay
void TIMER_0_delay(){
	TIMER_0_start();
	TIMER_0_stop();
}

// This function resets timer without stopping it
void TIMER_reset(){
	TIMER_0_set_init_value(init_value);
	ovf = 0;
}

// Timer_0 overflow interrupt
ISR(TIMER_0_OVF){
	// Resetting initial value for the next timer cycle
	TIMER_0_set_init_value(init_value);
	
	// Incrementing overflow variable
	ovf++;
	
	// Blinking yellow lights only in phase_2 and phase_4
	if(counting== level2 || counting == level4){
		// Only blink cars yellow light in normal mode
		if(!firstpress){
			callbackvar(traffic_lights, yellow_light);
		}
		// Blink both yellow lights in pedestrian mode
		else if(firstpress){
			callbackvar(traffic_lights, yellow_light);
			callbackvar(pedestrian_lights, yellow_light);
		}
		else{
			printf("Error..");
		}
	}
}