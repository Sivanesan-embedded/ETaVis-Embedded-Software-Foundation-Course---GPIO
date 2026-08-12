#include "Arduino.h"
#include "DOT_MATRIX.h"

void setup() {

  int left_shift = 7;
  
  DOT_MATRIX_Init();

  while(1)
  {
    left_shift = 7;
    for (char i = 1; i < 9; i++)
    {
       Send_Data(i,1 << left_shift--);
    }
  }
}
