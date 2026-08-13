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

//////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////            START                 ///////////////////////////////
/////////////////////////////////      Entering_From_Right         ///////////////////////////////
/////////////////////////////////         Display_ETAL             ///////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////            END                   ///////////////////////////////
/////////////////////////////////      Entering_From_Right         ///////////////////////////////
/////////////////////////////////         Display_ETAL             ///////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////            START                 ///////////////////////////////
/////////////////////////////////      Entering_From_LEFT          ///////////////////////////////
/////////////////////////////////         Display_1234             ///////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

void Entering_From_LEFT_Display_1234_Animation_1()
{
   for (int i = 7; i >= 0; i--)
      {
         for (int j = 0; j < 8; j++)
         {
            Send_Data(j+1,Display_4[j] << i,j+1,0x00,j+1,0x00,j+1,0x00);
         }
      make_delay(50000);
      }
}

void Entering_From_LEFT_Display_1234_Animation_2()
{
   char right_shift = 1;

   for (int i = 7; i >= 0; i--)
      {
         for (int j = 0; j < 8; j++)
         {
            Send_Data(j+1,(Display_3[j] << i)|(Display_4[j] >> right_shift),j+1,Display_4[j] << i,j+1,0x00,j+1,0x00);
         }
      right_shift++;
      make_delay(50000);
      }
}

void Entering_From_LEFT_Display_1234_Animation_3()
{
   char right_shift = 1;

   for (int i = 7; i >= 0; i--)
      {
         for (int j = 0; j < 8; j++)
         {
            Send_Data(j+1,(Display_2[j] << i)|(Display_3[j] >> right_shift),
                      j+1,Display_3[j] << i | (Display_4[j] >> right_shift),
                      j+1,Display_4[j] << i,j+1,0x00);
         }
      right_shift++;
      make_delay(50000);
      }
}

void Entering_From_LEFT_Display_1234_Animation_4()
{
   char right_shift = 1;

   for (int i = 7; i >= 0; i--)
      {
         for (int j = 0; j < 8; j++)
         {
            Send_Data(j+1,(Display_1[j] << i)|(Display_2[j] >> right_shift),
                      j+1,Display_2[j] << i | (Display_3[j] >> right_shift),
                      j+1,Display_3[j] << i | (Display_4[j] >> right_shift),
                      j+1,Display_4[j] << i);
         }
      right_shift++;
      make_delay(50000);
      }
}

void Display_1234(void)
{
   for (int j = 0; j < 8; j++)
      {
         Send_Data(j+1,Display_1[j],
                   j+1,Display_2[j],
                   j+1,Display_3[j],
                   j+1,Display_4[j]);
      }

   make_delay(1000000);
      
}

void Entering_From_LEFT_Display_1234()
{
   Entering_From_LEFT_Display_1234_Animation_1();
   Entering_From_LEFT_Display_1234_Animation_2();
   Entering_From_LEFT_Display_1234_Animation_3();
   Entering_From_LEFT_Display_1234_Animation_4();
   Display_1234();
}

//////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////            END                   ///////////////////////////////
/////////////////////////////////      Entering_From_LEFT         ///////////////////////////////
/////////////////////////////////         Display_1234            ///////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////            START                 ///////////////////////////////
/////////////////////////////////      Entering_From_TOP           ///////////////////////////////
/////////////////////////////////         Display_ETAL             ///////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

void Entering_From_TOP_Display_ETAL()
{
   int limit = 1, index = 7, temp = 7;

   for (int i = 0; i < 8; i++)
   {
      for (int j = 1; j < 9; j++)
      {
         if (j <= limit)
         {
            Send_Data(j,Display_E[index],
                   j,Display_T[index],
                   j,Display_A[index],
                   j,Display_L[index]);
            index++;
         }
         else
         {
            Send_Data(j,0x00,j,0x00,j,0x00,j,0x00);
         }
      }
      make_delay(50000);
      limit++;
      index = --temp;
   }

    for (int j = 0; j < 8; j++)
      {
         Send_Data(j+1,Display_E[j],
                   j+1,Display_T[j],
                   j+1,Display_A[j],
                   j+1,Display_L[j]);
      }

   make_delay(1000000); 
}

//////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////            END                   ///////////////////////////////
/////////////////////////////////      Entering_From_TOP           ///////////////////////////////
/////////////////////////////////         Display_ETAL             ///////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////