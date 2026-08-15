#include "Arduino.h"
#include "DOT_MATRIX.h"


void setup() {
  
  DOT_MATRIX_Init();

  while(1)
  {
      TOP_Entering_SIMULTANEOUS_BOTTOM_Enter_1234_Collide();
  }
}
