/*
 * ICU.c
 *
 * Created: 5/8/2024 8:19:50 PM
 *  Author: Mahmoud Saber
 */ 

#include "File.h"

unsigned int t;

/*This function is used to make Initialization for ICU*/
void icu_init()
{
	setbit(PORTD,PD6);
	
	TCCR1A= 0;
	TIFR= 1<<ICF1;
	TCCR1B= 0x41;
}

/*This function is used to calculate the time period of the signal.*/
void icu_on()
{
	while((TIFR&(1<<ICF1))==0);
	t= ICR1;
	
	TIFR= 1<<ICF1;
	while((TIFR&(1<<ICF1))==0);
	t= ICR1 - t;
	

}



