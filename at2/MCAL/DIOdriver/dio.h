/*
 * dio.h
 *
 * Created: 2/10/2023 8:30:42 AM
 *  Author: SeifEldien
 */ 


#ifndef DIO_H_
#define DIO_H_
#include <stdint.h>
#include "../../Utilities/registers.h"
#include "../../Utilities/macro.h"
//all the internal type defs for drivers will be written here
//all driver macros will be also written here too!
//driver function prototypes
//Macros
#define  PORT_A 'A'
#define  PORT_B 'B'
#define  PORT_C 'C'
#define  PORT_D 'D'
//directions
#define	IN 0
#define	OUT 1
//values
#define LOW 0
#define  HIGH 1

void DIO_init(uint8_t portNumber,uint8_t PINnumber,uint8_t direction);//initializing the  directions of the pins

void DIO_write(uint8_t portNumber,uint8_t PINnumber,uint8_t value);//write data to dio

void DIO_toggle(uint8_t portNumber,uint8_t PINnumber);//toggling dio

void DIO_read(uint8_t portNumber,uint8_t PINnumber,uint8_t *value);//reading dio



#endif /* DIO_H_ */