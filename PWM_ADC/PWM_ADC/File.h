/*
 * File.h
 *
 * Created: 5/8/2024 7:29:13 PM
 *  Author: Mahmoud Saber
 */ 


#ifndef FILE_H_
#define FILE_H_

#define F_CPU 1000000ul
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>

#define setbit(reg,pin)     reg |= (1<<pin)
#define clearbit(reg,pin)   reg &= ~(1<<pin)
#define togglebit(reg,pin)  reg ^= (1<<pin)
#define readbit(reg,pin)    ((reg>>pin)&1)



/***********ADC & PWM INITIALIZATION*************/
void adc_init();
int adc_read(int adc_chan);
void PWM_init();
/****************************************************/


/****************** UART COMMUNICATION FUNCTIONS *********************/
void UART_INIT(unsigned int baud);
void UART_sendchar(unsigned char data);
unsigned char UART_receivechar();

/****************************************************/




#endif /* FILE_H_ */