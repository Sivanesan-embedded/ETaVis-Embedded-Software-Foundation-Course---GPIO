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

void Entering_From_Right_Display_ETAL();
void Entering_From_LEFT_Display_1234();
void Entering_From_TOP_Display_ETAL();
void Entering_From_BOTTOM_Display_1234();

void make_delay(long);