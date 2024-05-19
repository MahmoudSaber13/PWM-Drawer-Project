/*
 * File.h
 *
 * Created: 5/6/2024 1:05:36 PM
 *  Author: Mahmoud Saber
 */ 


#ifndef FILE_H_
#define FILE_H_

#define F_CPU 1000000ul
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define setbit(reg,pin)     reg |= (1<<pin)
#define clearbit(reg,pin)   reg &= ~(1<<pin)
#define togglebit(reg,pin)  reg ^= (1<<pin)
#define readbit(reg,pin)    ((reg>>pin)&1)

/*GLCD Configuration*/
#define RS   PC0
#define RW   PC1
#define EN   PC2
#define RST  PC3
#define CS1  PC4
#define CS2  PC5

#define com_dir   DDRC
#define com_port  PORTC

#define data_dir  DDRA
#define data_port PORTA
/********************************************************/

/*Belong to floatToString Function*/
#define BUFFER_SIZE 50 // Adjust the buffer size as needed
extern char receivedString[BUFFER_SIZE]; // Global buffer to store received string

/*Alphabets Arrays*/
extern char sys5x7[];
extern char sys5x6[];


/**************GLCD Functions*******************/

void delay(int cnt);
void glcd_send_com(uint8_t com);
void glcd_send_data(uint8_t data);
void glcd_pageSelect(char page);
void glcd_writeChar(char *chr);
void glcd_setCursor(uint8_t x, uint8_t y);
void glcd_writeStr(char page, char *str, uint8_t x, uint8_t y);
void glcd_writeImg(char *pxl);
void glcd_init();
void glcd_drawChar(char *chr);
void glcd_drawStr(char page, char *str, uint8_t x, uint8_t y);

/***************************************************************************/

/*********************** ICU Functions *******************/
void icu_init();
void icu_on();
/*************************************************/


/****************** UART COMMUNICATION FUNCTIONS *********************/
extern unsigned int t;
void UART_INIT(unsigned int baud);
void UART_sendchar(unsigned char data);
unsigned char UART_receivechar();

/********************************************************/

/************************DISPLAY FUNCTIONS****************************/
void display();
void floatToString(float value, char* buffer, int bufferSize, int precision);

/******************************** END *************************************/


#endif /* FILE_H_ */