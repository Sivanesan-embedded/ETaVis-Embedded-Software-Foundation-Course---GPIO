#include "DOT_MATRIX.h"
#include "ALPHANUM_MAPPINGS.h"

volatile char *out_dir = (volatile char *)0x21;
volatile char *out = (volatile char *)0x22;

void DOT_MATRIX_Init(void)
{
   *out_dir = 0xFF;
}

void Send_Data(unsigned char address1,unsigned char data1,
               unsigned char address2,unsigned char data2,
               unsigned char address3,unsigned char data3,
               unsigned char address4,unsigned char data4)
{
   *out &= ~(1 << CS);

   Send_Address(address1);
   Send_Data_Byte(data1);

   Send_Address(address2);
   Send_Data_Byte(data2);

   Send_Address(address3);
   Send_Data_Byte(data3);

   Send_Address(address4);
   Send_Data_Byte(data4);

   *out |= (1 << CS);
}

void Send_Address(unsigned char n)
{
   for (char i = 7; i >= 0; i--)
   {
      if (((n >> i) & 0x01))
      {
         *out |= (1 << DIN);
      }
      else
      {
        *out &= ~(1 << DIN);
      }

      *out |= (1 << CLK);
      *out &= ~(1 << CLK);
   }
}

void Send_Data_Byte(unsigned char n)
{
   for (char i = 0; i < 8; i++)
   {
        
      if ((n & 0x01))
      {
         *out |= (1 << DIN);
      }
      else
      {
        *out &= ~(1 << DIN);
      }

      n = n >> 1;

      *out |= (1 << CLK);
      *out &= ~(1 << CLK);
   }
}


void make_delay(long n)
{
   for (volatile long i = 0; i < n; i++);
}

void Entering_From_Right_Display_ETAL_Animation_1(void)
{
      for (int i = 7; i >= 0; i--)
      {
         for (int j = 0; j < 8; j++)
         {
            Send_Data(j+1,0x00,j+1,0x00,j+1,0x00,j+1,Display_E[j] >> i);
         }
      make_delay(50000);
      }
}

void Entering_From_Right_Display_ETAL_Animation_2(void)
{
   char left_shift = 1;

   for (int i = 7; i >= 0; i--)
      {
         for (int j = 0; j < 8; j++)
         {
            Send_Data(j+1,0x00,j+1,0x00,j+1,Display_E[j] >> i,j+1,(Display_E[j] << left_shift)|(Display_T[j] >> i));
         }
         left_shift++;
         make_delay(50000);
      }
}

void Entering_From_Right_Display_ETAL_Animation_3(void)
{
   char left_shift = 1;

   for (int i = 7; i >= 0; i--)
      {
         for (int j = 0; j < 8; j++)
         {
            Send_Data(j+1,0x00,j+1,Display_E[j] >> i,j+1,(Display_E[j] << left_shift)|(Display_T[j] >> i),
                      j+1,(Display_T[j] << left_shift)|(Display_A[j] >> i));
         }
         left_shift++;
         make_delay(50000);
      }
}

void Entering_From_Right_Display_ETAL_Animation_4(void)
{
   char left_shift = 1;

   for (int i = 7; i >= 0; i--)
      {
         for (int j = 0; j < 8; j++)
         {
            Send_Data(j+1,Display_E[j] >> i,
                      j+1,(Display_E[j] << left_shift)|(Display_T[j] >> i),
                      j+1,(Display_T[j] << left_shift)|(Display_A[j] >> i),
                      j+1,(Display_A[j] << left_shift)|(Display_L[j] >> i));
         }
         left_shift++;
         make_delay(50000);
      }
}

void Display_ETAL(void)
{
   for (int j = 0; j < 8; j++)
      {
         Send_Data(j+1,Display_E[j],
                   j+1,Display_T[j],
                   j+1,Display_A[j],
                   j+1,Display_L[j]);
      }

   make_delay(1000000);
      
}

void Entering_From_Right_Display_ETAL(void)
{
   Entering_From_Right_Display_ETAL_Animation_1();
   Entering_From_Right_Display_ETAL_Animation_2();
   Entering_From_Right_Display_ETAL_Animation_3();
   Entering_From_Right_Display_ETAL_Animation_4();
   Display_ETAL();
}