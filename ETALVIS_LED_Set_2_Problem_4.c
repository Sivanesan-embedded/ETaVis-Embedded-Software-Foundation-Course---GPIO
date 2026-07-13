void make_delay(volatile long);

void setup() {
  volatile char *dir = (volatile char *)0x27;
  volatile char *out = (volatile char *)0x28;

  *dir = 0xFF;

  while (1)
  {
    for (volatile int i = 0; i < 8; i++)
    {
      *out = (1 << i);
      make_delay(100000);
    }
  }
}

void make_delay(volatile long n)
{
  for (volatile long i = 0; i < n; i++);
}
