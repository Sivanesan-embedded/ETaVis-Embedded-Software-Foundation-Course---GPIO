void make_delay(volatile long);

void setup() {
  volatile char *dir = (volatile char *)0x21;
  volatile char *out = (volatile char *)0x22;

  *dir = 0xFF;
  
  while (1)
  {
    *out = 0x00;
    make_delay(500000);
   
    for (volatile int i = 0; i < 8; i++)
    {
      *out = (1 << i);
      make_delay(500000);
    }

     *out = 0x00;
      make_delay(500000);

    for (volatile int i = 7; i >= 0; i--)
    {
      *out = (1 << i);
      make_delay(500000);
    }
  }
}

void make_delay(volatile long n)
{
  for (volatile long i = 0; i < n; i++);
}
s