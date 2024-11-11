/* most of our definitions and macros will be here*/


#ifndef MACRO_H_
#define MACRO_H_

typedef unsigned char uint8_t;


#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'


#define traffic_lights PORT_A
#define pedestrian_lights PORT_B

#define level1 0
#define level2 1
#define level3 2
#define level4 3

#define yellow_light 1
#define red_light	 2
#define green_light	 0



#define pin_choose(x,n) x|= (1<<n)
#define pin_clear(x,n) x&= ~(1<<n)
#define pin_toggle(x,n) x^= (1<<n)
#define pin_getting(x,n) ((x&(1<<n))>>n)



#endif /* MACRO_H_ */