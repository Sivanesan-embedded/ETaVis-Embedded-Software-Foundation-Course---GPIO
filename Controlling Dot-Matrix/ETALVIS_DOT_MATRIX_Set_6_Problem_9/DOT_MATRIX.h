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

void Entering_From_BOTTOM_Display_ETAL_LEAVING_LEFT();
void Entering_From_TOP_Display_ETAL_LEAVING_RIGHT();
void Entering_From_RIGHT_Display_ETAL_LEAVING_TOP();
void Entering_From_LEFT_Display_ETAL_LEAVING_BOTTOM();

void Entering_From_TOP_Display_ETAL_SPLIT_HALF();
void Split_Entering_12_From_LEFT_34_From_Right();
void TOP_Entering_SIMULTANEOUS_BOTTOM_Enter_1234();
void TOP_Entering_SIMULTANEOUS_BOTTOM_Enter_1234_Collide();
void Entering_SIMULTANEOUS_ALL_Direction_Display_1234_Collide();
void Display_1234_entering_12_right_34_left(void);

void make_delay(long);