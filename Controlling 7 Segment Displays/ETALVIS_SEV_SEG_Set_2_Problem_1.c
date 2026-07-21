#include <Arduino.h>

void make_delay(long);

void setup() {
  volatile char *dir = (volatile char *)0x21;
  volatile char *out = (volatile char *)0x22;

  *dir = 0xFF;

  int arr[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

  while (1)
  {
    for (int i = 0; i < 10; i++)
    {
      *out = arr[i];
      make_delay(300000);
    }
  }
}

void make_delay(long n)
{
  for (volatile long i = 0; i < n; i++);
}

