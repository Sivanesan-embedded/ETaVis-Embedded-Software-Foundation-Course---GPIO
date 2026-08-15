#include "Arduino.h"
#include "DOT_MATRIX.h"


void setup() {
  
  DOT_MATRIX_Init();

  while(1)
  {
      Entering_From_BOTTOM_Display_1234();
  }
}
