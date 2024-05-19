/*
 * File.c
 *
 * Created: 5/6/2024 1:05:18 PM
 *  Author: Mahmoud Saber
 */ 


#include "File.h"

/*Function to make delay to make configuration for GLCD*/
void delay(int cnt)
{
	int i;
	for(i=0;i<cnt;i++);
}


/*Function to send commands to GLCD*/
void glcd_send_com(uint8_t com)
{
	data_port = com;
	clearbit(com_port, RS);
	clearbit(com_port, RW);
	setbit(com_port, EN);
	delay(100);
	clearbit(com_port, EN);
	delay(1000);
}

/*Function to send Data to GLCD*/
void glcd_send_data(uint8_t data)
{
	data_port = data;
	setbit(com_port, RS);
	clearbit(com_port, RW);
	setbit(com_port, EN);
	delay(100);
	clearbit(com_port, EN);
	delay(1000);
	
}


/*GLCD has two pages, this function is used to choose the pages*/
void glcd_pageSelect(char page)
{
	switch(page)
	{
		case 0:
		clearbit(com_port, CS2);
		setbit(com_port, CS1);
		break;
		
		case 1:
		clearbit(com_port, CS1);
		setbit(com_port, CS2);
		break;
		
		case 2:
		setbit(com_port, CS1);
		setbit(com_port, CS2);
		break;
		
		case 3:
		clearbit(com_port, CS1);
		clearbit(com_port, CS2);
		break;
		
		default:
		setbit(com_port, CS1);
		setbit(com_port, CS2);
		break;
	}
}

/*This function is used to move in x and y directions on the GLCD*/
void glcd_setCursor(uint8_t x, uint8_t y)
{
	glcd_send_com(0xB8+x);
	glcd_send_com(0x40+y);
}


/*This Function is used to write string on a specific location*/
void glcd_writeStr(char page, char *str, uint8_t x, uint8_t y)
{
	int i=0;
	int startfont=0, endFont=0;
	glcd_pageSelect(page);
	glcd_setCursor(x,y);
	while(*str)
	{
		startfont= (*str -32)*6;
		endFont= startfont + 6;
		for(i=startfont; i<endFont; i++)
		{
			glcd_send_data(sys5x7[i]);
			delay(1000);
		}
		str++;
	}
}


/*This Function is used to make initialization for our GLCD*/
void glcd_init()
{
	com_dir= 0xff;
	data_dir= 0xFF;
	
	clearbit(com_port,RST);
	_delay_ms(10);
	setbit(com_port,RST);
	_delay_ms(1);
	glcd_pageSelect(2);
	_delay_ms(1);
	glcd_send_com(0x3F);
	glcd_send_com(0xc0);
	_delay_ms(1);
	glcd_pageSelect(1);
	_delay_ms(1);
}


/*This Function is used to draw on the GLCD*/
void glcd_drawStr(char page, char *str, uint8_t x, uint8_t y)
{
	int i=0;
	int startfont=0, endFont=0;
	glcd_pageSelect(page);
	glcd_setCursor(x,y);
	while(*str)
	{
		startfont= (*str -32)*5;
		endFont= startfont + 5;
		for(i=startfont; i<endFont; i++)
		{
			glcd_send_data(sys5x6[i]);
			delay(1000);
		}
		str++;
	}
}