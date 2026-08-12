#include "Arduino.h"
#include "DOT_MATRIX.h"
#include "ALPHANUM_MAPPINGS.h"


void setup() {
  
  DOT_MATRIX_Init();

  while(1)
  {
    for (char i = 1; i < 9; i++)
    {
       Send_Data(i,Display_E[i-1],i,Display_T[i-1],i,Display_A[i-1],i,Display_L[i-1]);
    }
  }
}
