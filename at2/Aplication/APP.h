

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "../HAL/Buttondriver/button.h"
#include "../HAL/LEDdriver/led.h"

//cpu frequency(if simulating on microchip studio then it should also be set to the same frequency)
#define F_CPU 1000000U

void App_init();
void App_start();


#endif /* APPLICATION_H_ */