#include "DOT_MATRIX.h"

volatile char *out_dir = (volatile char *)0x21;
volatile char *out = (volatile char *)0x22;

void DOT_MATRIX_Init(void)
{
   *out_dir = 0xFF;
}

void Send_Data(char address1,char data1,
               char address2,char data2)
{
   *out &= ~(1 << CS);

   Send_Address(address1);
   Send_Data_Byte(data1);

   Send_Address(address2);
   Send_Data_Byte(data2);

   *out |= (1 << CS);
}

void Send_Address(char n)
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

void Send_Data_Byte(char n)
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