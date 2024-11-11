/*
 * at2.c
 *
 * Created: 2/10/2023 8:26:35 AM
 * Author : SeifEldien
 */ 
//#include <avr/io.h>
#include "Aplication/APP.h"

//Starting the application and calling all the functions
int main(void)
{
App_init();
	while (1)
	{
		App_start();
		
	}
}
