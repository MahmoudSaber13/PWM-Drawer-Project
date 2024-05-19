/*
 * UART.c
 *
 * Created: 5/14/2024 10:26:27 PM
 *  Author: Mahmoud Saber
 */ 

#include "File.h"

unsigned char *duty;


/**********UART INITIALIZATION***********/
void UART_INIT(unsigned int baud)
{
	UCSRB |= (1 << RXEN) | (1 << TXEN);				// Enable UART transmitter and receiver
	UCSRC |= (1 << URSEL)| (1 << UCSZ0) | (1 << UCSZ1);	//8 bit data and 1 stop bit
	UBRRL = baud;
	UBRRH = (baud >> 8);
}
/************************************************************************/


/*This function is used to send 1 byte of data*/
void UART_sendchar(unsigned char data)
{
	while(readbit(UCSRA,UDRE)==0)// wait the reg to be empty
	{	;	}
	UDR = data; // send  data
	while(readbit(UCSRA,TXC)==0)// wait till the data to be send
	{	;	}
}
/*******************************************************/


/*This function is used to receive 1 byte of data*/
unsigned char UART_receivechar()
{
	while ((UCSRA & (1 << RXC)) == 0);/* Wait till data is received */
	return(UDR);			/* Return the byte*/
}

/****************************************************/
