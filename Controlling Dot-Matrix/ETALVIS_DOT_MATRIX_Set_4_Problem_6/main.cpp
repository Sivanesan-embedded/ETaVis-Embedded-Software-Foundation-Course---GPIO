#include "Arduino.h"
#include "DOT_MATRIX.h"

void setup() {
  
  DOT_MATRIX_Init();

  while(1)
  {
    Send_Data(8,0xFF);
  }
}
