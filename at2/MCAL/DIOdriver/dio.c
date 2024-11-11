/*
 * CFile1.c
 *
 * Created: 2/10/2023 8:30:26 AM
 *  Author: SeifEldien
 */ 
//including libraries .h
//global variables
//function definitions
#include "../../Utilities/registers.h"
#include "dio.h"
void DIO_init(uint8_t portNumber,uint8_t PINnumber,uint8_t direction){
	switch(portNumber){
		case PORT_A:
		if(direction== IN){
			pin_clear(DDRA, PINnumber);//Output
		}
		else if(direction == OUT){
			pin_choose(DDRA, PINnumber);
		}
		else{
			printf("Error..");
		}
		break;
		case PORT_B:
		if(direction== IN){
			pin_clear(DDRB, PINnumber);//Output
		}
		else if(direction == OUT){
			pin_choose(DDRB, PINnumber);
		}
		else{
			printf("Error..");
		}
		break;
		
		case PORT_C:
		if(direction== IN){
			pin_clear(DDRC, PINnumber);//Output
		}
		else if(direction == OUT){
			pin_choose(DDRC, PINnumber);
		}
		else{
			printf("Error..");
		}
		break;
		case PORT_D:
		if(direction== IN){
			pin_clear(DDRD, PINnumber);//Output
		}
		else if(direction == OUT){
			pin_choose(DDRD, PINnumber);
		}
		else{
			printf("Error..");
		}
		break;
	}
}

void DIO_write(uint8_t portNumber,uint8_t PINnumber,uint8_t value){
	switch(portNumber){
		case PORT_A:
		if(value== LOW){
			pin_clear(PORTA, PINnumber);//write 0
		}
		else if(value == HIGH){//write 1
			pin_choose(PORTA, PINnumber);
		}
		else{
			printf("Error..");
		}
		break;
		case PORT_B:
		if(value== LOW){
			pin_clear(PORTB, PINnumber);//write 0
		}
		else if(value == HIGH){
			pin_choose(PORTB, PINnumber);
		}
		else{
			printf("Error..");
		}
		break;
		
		case PORT_C:
		if(value== LOW){
			pin_clear(PORTC, PINnumber);//write 0
		}
		else if(value == HIGH){
			pin_choose(PORTC, PINnumber);
		}
		else{
			printf("Error..");
		}
		break;
		
		case PORT_D:
		if(value== LOW){
			pin_clear(PORTD, PINnumber);//write 0
		}
		else if(value == HIGH){
			pin_choose(PORTD, PINnumber);
		}
		else{
			printf("Error..");
		}
		break;
	}
}//write data to dio

void DIO_read(uint8_t portNumber,uint8_t PINnumber,uint8_t *value){
	switch(portNumber){
		case PORT_A:
		*value = pin_getting(PINA, PINnumber);
		break;
		case PORT_B:
		*value = pin_getting(PINA, PINnumber);
		break;
		case PORT_C:
		*value = pin_getting(PINA, PINnumber);
		break;
		case PORT_D:
		*value = pin_getting(PINA, PINnumber);
		break;
		default:
printf("Error..");
		break;	
		}
	
}


void DIO_toggle(uint8_t portname, uint8_t PINnumber){
	switch(portname){
		case PORT_A:
		pin_toggle(PORTA, PINnumber);
		break;
		
		case PORT_B:
		pin_toggle(PORTB, PINnumber);
		break;
		
		case PORT_C:
		pin_toggle(PORTC, PINnumber);
		break;
		
		case PORT_D:
		pin_toggle(PORTD, PINnumber);
		break;
		default:
		printf("Error..");
		break;
	}
}