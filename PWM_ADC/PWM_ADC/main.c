/*
 * PWM_ADC.c
 *
 * Created: 5/8/2024 7:28:24 PM
 * Author : Mahmoud Saber
 */ 

#include "File.h"


int main(void)
{
   
    clearbit(DDRA,4);
	adc_init();
	UART_INIT(6);
	int d=0;
	
	unsigned char w;
	
    while (1) 
    {
		PWM_init();
		d= adc_read(4);
		OCR0= (d*0.09765)+0.5;
		w= OCR0;
		UART_sendchar(w);
		 
		_delay_ms(1000);
    }
}

