#include "Arduino.h"
#include "DOT_MATRIX.h"


void setup() {
  
  DOT_MATRIX_Init();

  while(1)
  {
      Display_1234_entering_12_right_34_left();
      //Entering_SIMULTANEOUS_ALL_Direction_Display_1234_Collide();
  }
}
