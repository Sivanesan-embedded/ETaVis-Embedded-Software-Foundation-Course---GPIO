void make_delay(volatile long);

void setup() {
  volatile char *dir = (volatile char *)0x21;
  volatile char *out = (volatile char *)0x22;

  *dir = 0xFF;

  while (1)
  {
    *out = 0xFF;
    make_delay(100000);
    *out = 0x00;
    make_delay(100000);
  }
}

void make_delay(volatile long n)
{
  for (volatile long i = 0; i < n; i++);
}
