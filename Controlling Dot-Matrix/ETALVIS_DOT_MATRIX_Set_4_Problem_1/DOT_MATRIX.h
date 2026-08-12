#pragma once 

#define DIN 0
#define CS 1
#define CLK 2

extern volatile char *out;

void DOT_MATRIX_Init(void);
void Send_Data(char,char);
void Send_Address(char);
void Send_Data_Byte(char);