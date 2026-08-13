#include "Arduino.h"
#include "DOT_MATRIX.h"


void setup() {

  unsigned char mask = 0xFF, times = 1;
  
  DOT_MATRIX_Init();

  while(1)
  {
      Entering_From_Right_Display_ETAL();
  }
}
