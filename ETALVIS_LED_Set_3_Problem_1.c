void make_delay(volatile long);

void setup() {
  volatile char *dir = (volatile char *)0x21;
  volatile char *out = (volatile char *)0x22;

  *dir = 0xFF;

  int f = 3,l = 7;

  while (1)
  {
    f = 3; l = 7;

    for (volatile int j = 0; j < 4; j++)
    {
    for (volatile int i = 7; i >= 0; i--)
    {
      if ((f == i) || (l == i))
      {
         *out |= (1 << i);
      }
      else
      {
        *out |= (0 << i);
      }
    }
    f--;l--;
    make_delay(1000000);
    *out = 0x00;
  }
  }
}

void make_delay(volatile long n)
{
  for (volatile long i = 0; i < n; i++);
}
