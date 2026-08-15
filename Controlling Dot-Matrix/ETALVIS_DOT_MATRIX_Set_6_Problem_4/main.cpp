#include "Arduino.h"
#include "DOT_MATRIX.h"


void setup() {
  
  DOT_MATRIX_Init();

  while(1)
  {
      Entering_From_LEFT_Display_ETAL_LEAVING_BOTTOM();
  }
}
