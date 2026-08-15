#include "Arduino.h"
#include "DOT_MATRIX.h"


void setup() {
  
  DOT_MATRIX_Init();

  while(1)
  {
      Split_Entering_12_From_LEFT_34_From_Right();
  }
}
