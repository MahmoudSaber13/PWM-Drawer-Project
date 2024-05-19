/*
 * PWM_Drawer.c
 *
 * Created: 5/6/2024 12:59:56 PM
 * Author : Mahmoud Saber
 */ 

#include "File.h"


int main(void)
{
	
	glcd_init();
	icu_init();
	UART_INIT(6);
	
    while (1) 
    {
		icu_on();
		display();
		
    }
}

