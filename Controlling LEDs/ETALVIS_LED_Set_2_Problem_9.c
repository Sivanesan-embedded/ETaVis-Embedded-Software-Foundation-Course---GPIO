void make_delay(volatile long);

void setup() {
  volatile char *dir = (volatile char *)0x30;
  volatile char *out = (volatile char *)0x31;

  *dir = 0xFF;

  while (1)
  {
    for (volatile int i = 7; i >= 0; i--)
    {
      if (i <= 3)
      {
         *out |= (1 << i);
         make_delay(100000);
      }
      else
      {
        *out |= (0 << i);
      }
    }
    *out = 0x00;
    make_delay(100000);
  }
}

void make_delay(volatile long n)
{
  for (volatile long i = 0; i < n; i++);
}
