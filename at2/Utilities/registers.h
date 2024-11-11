/*
 * registers.h
 *
 * Created: 2/10/2023 8:28:13 AM
 *  Author: SeifEldien
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

//PORTA registers
#define  PORTA *((volatile uint8_t*)0x3B)//we used volatile because hardware could have input that changes
#define  DDRA *((volatile uint8_t*)0x3A)//we used volatile because hardware could have input that changes
#define  PINA *((volatile uint8_t*)0x39)//we used volatile because hardware could have input that changes

//PORTB registers
//we used volatile because hardware could have input that changes
#define  PORTB *((volatile uint8_t*)0x38)
#define  DDRB *((volatile uint8_t*)0x37)
#define  PINB *((volatile uint8_t*)0x36)

//PORTC registers
//we used volatile because hardware could have input that changes
#define  PORTC *((volatile uint8_t*)0x35)
#define  DDRC *((volatile uint8_t*)0x34)
#define  PINC *((volatile uint8_t*)0x33)

//PORTD registers
//we used volatile because hardware could have input that changes
#define  PORTD *((volatile uint8_t*)0x32)
#define  DDRD *((volatile uint8_t*)0x31)
#define  PIND *((volatile uint8_t*)0x30)

//the registers used for timers
//we used volatile because hardware could have input that changes
#define  TCCR0 *((volatile uint8_t*)0x53)
#define  TCNT0 *((volatile uint8_t*)0x52)
#define  TIFR *((volatile uint8_t*)0x58)
#define OCR0 *((volatile uint8_t*)0x5C)
#define TIMSK *((volatile uint8_t*)0x59)



//status 
#define SREG *((volatile uint8_t*)0x5F)




//the interrupt registers
#define MCUCR *((volatile uint8_t*)0x55)
#define GICR *((volatile uint8_t*)0x5B)
#define GIFR *((volatile uint8_t*)0x5A)





#endif /* REGISTERS_H_ */