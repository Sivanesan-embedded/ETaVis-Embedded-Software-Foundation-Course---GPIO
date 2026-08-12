#pragma once 

#define DIN 0
#define CS 1
#define CLK 2

extern volatile char *out;

void DOT_MATRIX_Init(void);
void Send_Data(unsigned char,unsigned char,unsigned char,unsigned char,
               unsigned char,unsigned char,unsigned char,unsigned char);
void Send_Address(unsigned char);
void Send_Data_Byte(unsigned char);

void make_delay(long);