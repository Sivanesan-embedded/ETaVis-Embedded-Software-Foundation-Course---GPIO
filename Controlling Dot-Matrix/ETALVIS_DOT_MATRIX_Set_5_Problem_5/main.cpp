#include "Arduino.h"
#include "DOT_MATRIX.h"
#include "ALPHANUM_MAPPINGS.h"


void setup() {
  
  DOT_MATRIX_Init();

  while(1)
  {
    for (char i = 1; i < 9; i++)
    {
       Send_Data(i,Display_1[i-1],i,Display_2[i-1],i,Display_3[i-1],i,Display_4[i-1]);
    }
  }
}
