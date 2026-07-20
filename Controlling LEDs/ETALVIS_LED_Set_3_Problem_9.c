void make_delay(volatile long);

void setup() {
  volatile char *dir = (volatile char *)0x21;
  volatile char *out = (volatile char *)0x22;

  *dir = 0xFF;

  int limit = 0;
  
  while (1)
  {
    *out = 0x00;
    make_delay(100000);
    limit = 0;

    for (volatile int i = 0; i < 8; i++)
    {
      for (volatile int j = 0; j <= limit; j++)
      {
        *out |= (1 << j);
         make_delay(80000);
      }
      *out = 0x00;
      make_delay(100000);
      limit++;
    }
  }
}

void make_delay(volatile long n)
{
  for (volatile long i = 0; i < n; i++);
}
