#include "Arduino.h"
#include "DOT_MATRIX.h"
#include "ALPHANUM_MAPPINGS.h"


void setup() {

  unsigned char mask = 0xFF, times = 1;
  
  DOT_MATRIX_Init();

  while(1)
  {
    mask = 0xFF, times = 1;

    for (char i = 1; i < 9; i++)
    {
       Send_Data(i,Display_E[i-1],i,Display_T[i-1],i,Display_A[i-1],i,Display_L[i-1]);
    }

    make_delay(1000000);

    while (times != 9)
    {
      for (char i = 1; i < 9; i++)
      {
        Send_Data(i,Display_E[i-1],i,Display_T[i-1],i,Display_A[i-1],i,(Display_L[i-1]) & (mask << times));
      }
      make_delay(100000);
      times++;
   }

   mask = 0xFF, times = 1;

    while (times != 9)
    {
      for (char i = 1; i < 9; i++)
      {
        Send_Data(i,Display_E[i-1],i,Display_T[i-1],i,Display_A[i-1] & (mask << times),i,0x00);
      }
      make_delay(100000);
      times++;
   }

   mask = 0xFF, times = 1;

    while (times != 9)
    {
      for (char i = 1; i < 9; i++)
      {
        Send_Data(i,Display_E[i-1],i,Display_T[i-1] & (mask << times),i,0x00,i,0x00);
      }
      make_delay(100000);
      times++;
   }

   mask = 0xFF, times = 1;

    while (times != 9)
    {
      for (char i = 1; i < 9; i++)
      {
        Send_Data(i,Display_E[i-1] & (mask << times),i,0x00,i,0x00,i,0x00);
      }
      make_delay(100000);
      times++;
   }
  }
}
