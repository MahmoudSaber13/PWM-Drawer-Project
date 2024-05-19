/*
 * File.c
 *
 * Created: 5/8/2024 7:28:51 PM
 *  Author: Mahmoud Saber
 */ 

#include "File.h"


/*****ADC INITIALIZATION******/
void adc_init()
{
	ADMUX |= (1<<REFS0);
	ADCSRA |= (1<<ADEN)|(1<<ADPS2);
}
/***************************************/


/*This function is used to read the value of the adc or sensor signal*/
int adc_read(int adc_chan)
{
	int adc_val=0;
	ADMUX = (ADMUX & 0xE0) | (adc_chan);
	ADCSRA |= (1<<ADSC);
	while((readbit(ADCSRA,ADIF))==0);
	_delay_us(10);
	adc_val = (int)ADCL + (int)ADCH*256;
	return adc_val;
}
/*************************************/



/*This function is used to generate PWM signal*/
void PWM_init()
{
	TCCR0= (1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS00);
	DDRB |= (1<<PB3);
}
/***********************************************/
