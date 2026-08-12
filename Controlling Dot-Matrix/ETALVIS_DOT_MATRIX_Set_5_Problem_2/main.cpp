#include "Arduino.h"
#include "DOT_MATRIX.h"

char Display_1[] = {0x10,0x30,0x50,0x10,0x10,0x10,0x7C,0x00};
char Display_2[] = {0x7E,0x02,0x02,0x7E,0x40,0x40,0x7E,0x00};

void setup() {
  
  DOT_MATRIX_Init();

  while(1)
  {
    for (char i = 1; i < 9; i++)
    {
       Send_Data(i,Display_1[i-1],i,Display_2[i-1]);
    }
  }
}
