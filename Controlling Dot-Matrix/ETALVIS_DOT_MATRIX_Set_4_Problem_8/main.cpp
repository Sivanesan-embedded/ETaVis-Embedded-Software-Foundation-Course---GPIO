#include "Arduino.h"
#include "DOT_MATRIX.h"

void setup() {
  
  DOT_MATRIX_Init();

  while(1)
  {
    for (char i = 1; i < 9; i++)
    {
       Send_Data(i,0x01);
    }
  }
}
