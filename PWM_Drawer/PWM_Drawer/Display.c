/*
 * Display.c
 *
 * Created: 5/16/2024 12:13:11 PM
 *  Author: Mahmoud Saber
 */ 

#include "File.h"

float f;
char tm[10];
char fre[10];

char freq[10]= "Fr=\0";
char time[10]= "Time=\0";

char duty_cy[10];
char percent[2]= "%";


/*This function is used to display the Results on the GLCD*/
void display()
{
		unsigned char z;
		
		f= ((F_CPU/1000000)*(3.906));
		
		floatToString(f, fre, 10, 3);
		//res_str(freq,fre,result);
		glcd_writeStr(0, freq,0,0);
		glcd_writeStr(0,fre,0,20);
		glcd_writeStr(1, "KHZ",0,0);
		
		z= UART_receivechar();
		sprintf(duty_cy, "%u", z);
		glcd_writeStr(0,"Dut_Cy:",2,0);
		glcd_writeStr(0,duty_cy,2,42);
		
		if(z<100 && z!=0)
		glcd_writeStr(0," \0",2,54);
		
		else if(z>=0 && z<10)
		glcd_writeStr(0,"  \0",2,47);
		
		else
		glcd_writeStr(0,duty_cy,2,42);
		
		glcd_writeStr(1,percent,2,0);
		
		float time_ms=(t*0.001);
		floatToString(time_ms, tm, 10, 3);
		
		glcd_writeStr(0, time,4,0);
		glcd_writeStr(0, tm,4,30);
		glcd_writeStr(1, "mS",4,0);
		
		/*
		  ___     ___     ___     ___
		_|   |___|   |___|   |___|
		
		*/
		
		if(z>=40 && z<=60)
		{
			glcd_drawStr(0, " <--T-->\0",5,0);
			glcd_drawStr(0, "  __    __   \0",6,0);
			glcd_drawStr(0, "_|  |__|  |__\0",7,0);
			glcd_drawStr(1, " __    __  \0",6,0);
			glcd_drawStr(1, "|  |__|  |_\0",7,0);
		}
		
		else if(z==0)
		{
			glcd_drawStr(0, " <--T-->\0",5,0);
			glcd_drawStr(0, "             \0",6,0);
			glcd_drawStr(0, "|____________\0",7,0);
			glcd_drawStr(1, "_____________\0",7,0);
			glcd_drawStr(1, "             \0",6,0);
		}
		else if(z==100)
		{
			glcd_drawStr(0, " <--T-->\0",5,0);
			glcd_drawStr(0, " ____________\0",6,0);
			glcd_drawStr(0, "|            \0",7,0);
			
			glcd_drawStr(1, "___________\0",6,0);
			glcd_drawStr(1, "            \0",7,0);
		}
		
		else if(z>0 && z<40)
		{
			glcd_drawStr(0, " <--T-->\0",5,0);
			glcd_drawStr(0, "  _     _    \0",6,0);
			glcd_drawStr(0, "_| |___| |___\0",7,0);
			glcd_drawStr(1, " _     _   \0",6,0);
			glcd_drawStr(1, "| |___| |__\0",7,0);
			
		}
		
		else if(z>60 && z<100)
		{
			glcd_drawStr(0, " <--T-->\0",5,0);
			glcd_drawStr(0, "  ___   ___  \0",6,0);
			glcd_drawStr(0, "_|   |_|   |_\0",7,0);
			glcd_drawStr(1, " ___   ___  \0",6,0);
			glcd_drawStr(1, "|   |_|   |_\0",7,0);
			
		}
		
		else
		{
			glcd_drawStr(0, " <--T-->\0",5,0);
			glcd_drawStr(0, "  __    __   \0",6,0);
			glcd_drawStr(0, "_|  |__|  |__\0",7,0);
			glcd_drawStr(1, " __    __  \0",6,0);
			glcd_drawStr(1, "|  |__|  |_\0",7,0);
		}
		
		//glcd_drawStr(0, "123456789abc_\0",7,0);
}
/*****************************************************************/


/*This function is used to convert float number to string*/
void floatToString(float value, char* buffer, int bufferSize, int precision)
{
	// Handle negative numbers
	if (value < 0) {
		*buffer++ = '-';
		value = -value;
	}

	// Extract integer part
	int intPart = (int)value;
	int length = snprintf(buffer, bufferSize, "%d", intPart);
	buffer += length;
	bufferSize -= length;

	// Check if precision is required
	if (precision > 0) {
		// Add decimal point
		if (bufferSize > 1) {
			*buffer++ = '.';
			bufferSize--;
		}

		// Extract fractional part
		float fracPart = value - intPart;
		for (int i = 0; i < precision; ++i) {
			fracPart *= 10;
			int digit = (int)fracPart;
			*buffer++ = '0' + digit;
			bufferSize--;
			fracPart -= digit;
		}
	}

	// Null-terminate the string
	*buffer = '\0';
}

/*****************************************************************/
