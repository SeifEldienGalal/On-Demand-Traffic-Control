/*
 * button.c
 *
 * Created: 2/10/2023 9:12:38 AM
 *  Author: SeifEldien
 */ 
#include "button.h"


 uint8_t counter;
 
 
 uint8_t initialpress;
 uint8_t ovf;


//button pin direction input(0) or output(1)and calling the DIO function right away instead of creating a whole new function 
void BUTTON_init(uint8_t buttonPort,uint8_t buttonPin)
{
	DIO_init(buttonPort ,buttonPin,IN);
}

//button  value  low(0) high(1) and calling the DIO function right away instead of creating a whole new function 
void BUTTON_read(uint8_t buttonPort,uint8_t buttonPin,uint8_t *value)
{
	DIO_read(buttonPort,buttonPin,value);
}



ISR(EXT_INT_0){
	
	

	
	if(!initialpress){
		
		// if pressed in level1 it jumps over the green light remaining wait time and turns on the traffic blinking yellow light
		if(counter == level1){
			ovf=20;
		}
		
		// if pressed in level2 it resets the traffic lights blinking yellow light remaining wait time .
		else if(counter == level2){
			
			LED_off(traffic_lights, yellow_light);
			LED_off(pedestrian_lights, yellow_light);
			
			TIMER_reset();
		}
		
// If level 3 button is touched, red light wait time for automobiles is reset, and pedestrians' green and red lights are turned on.		
else if(counter == level3){
			TIMER_reset();
			LED_off(pedestrian_lights, red_light);
			LED_on(pedestrian_lights, green_light);
		}
		
		// if pushed in level4 it skips the remaining wait time for automobiles with blinking yellow lights and returns to level2. 
		// Reversing the count variable to level2 causes the car's light to go from yellow to green to red once more.
		else if(counter == level4){
			ovf=20;
			counter = level2;
		}
		else{
			printf("Error...");
		}
		
// The pedestrian mode is indicated by setting the first click variable to 1. When all 4 levels are finished, it is reset to 0.
		initialpress=1;
	}
}