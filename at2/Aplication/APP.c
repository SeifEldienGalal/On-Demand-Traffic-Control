#include "APP.h"

//here we are counting variable to have track of  the program during the execution from level1  which is 0 to level4 which is 3. starting at level1 0
uint8_t count_level = level1;

// first_click variable stores 0 when in traffic mode. but when  it is clicked the value becomes 1 switching to  pedestrian mode.
uint8_t startpress=0;


void App_init(){
	
	
	
	// calling the Timer_0 function
	TIMER_0_init();
	// setting the Timer_0 overflow interrupt
	INTERRUPT_T0_ovf_init();
	
	// Enabling the INT_0 interrupt
	INTERRUPT_0_init();
	
	// the global interrupt is called here
	INTERRUPT_global_init();
	setcallback(LED_toggle);
	
	BUTTON_init(PORT_D, 2);
	
	
	// calling all the led pins as output because they are  output devices only.
	LED_init(traffic_lights, green_light);
	
	LED_init(traffic_lights, yellow_light);
	
	LED_init(traffic_lights, red_light);
	
	LED_init(pedestrian_lights, green_light);
	
	LED_init(pedestrian_lights, yellow_light);
	
	LED_init(pedestrian_lights, red_light);
	
}


void App_start(){
	
	//*Level1*//
	
	if(count_level == level1){
		// first start of the normal mode loop
		LED_on(traffic_lights, green_light);
		LED_on(pedestrian_lights, yellow_light);
		
		// here this  function starts a 5 sec delay when the leds are turned on to prevent traffic confusion
		TIMER_0_delay();
	
		// here the count variable is added by one to switch to the next level, then modulus 4 to make the range of values from (0-3) 
		count_level = (count_level+1)%4;
	}
	else{
		printf("Error...");
	}
	
	
	
	
	
	//*Level2*//
	if(count_level == level2){
		/*	in the level2 here the timer_0 overflow interrupt blinks the traffic lights --> yellow light in normal mode
			and both cars and pedestrian light--> yellow light in pedestrian mode. */
		TIMER_0_delay();
		
		// turning  the two yellow leds off to make the toggling end with an off state for the leds after the  blinking is done.
		LED_off(traffic_lights, yellow_light);
		LED_off(pedestrian_lights, yellow_light);
		
		count_level = (count_level+1)%4;
	}
	else{
		printf("Error...");
	}
	
	
	
	
	
	//*Level3*//
	if(count_level == level3){
		// the Program  enters this if statement only when  in pedestrian mode .
		if(startpress){
			LED_on(pedestrian_lights, green_light);
			LED_off(pedestrian_lights, red_light);
		}
		
		//  turning on red traffic light and turning off green traffic light.
		LED_off(traffic_lights, green_light);
		LED_on(traffic_lights, red_light);
		
		TIMER_0_delay();
		
		count_level = (count_level+1)%4;
	}
	else{
		printf("Error...");
	}
	
	
	
	
	//*Level4*//
	
	/*	here in level4 , the timer_0 overflow makes the yellow traffic light blink in normal mode
		and both traffic and pedestrian yellow light in pedestrian mode. */
	TIMER_0_delay();
	
	// Turned off the pedestrian green light in the case of pedestrian mode to exit and enter normal mode(traffic) level1 again.
	LED_off(pedestrian_lights, green_light);
	
	// Turned off the traffic blinking yellow light in the case of normal mode to start again from Level1.
	LED_off(traffic_lights, yellow_light);
	
	// Turned off the pedestrian yellow light in case of pedestrian mode to exit and enter normal mode phase_1 again.
	LED_off(pedestrian_lights, yellow_light);
	
	
	if(count_level == level4){
		count_level = (count_level+1)%4;
		
		// Turning off cars blinking red light in case of normal mode to start again from phase_1.
		LED_off(traffic_lights, red_light);
		
		// Setting first_click flag to zero to indicate returning to normal mode.
		startpress=0;
	}
	else{
		printf("Error...");
	}
}
	//***********************************************************************************//