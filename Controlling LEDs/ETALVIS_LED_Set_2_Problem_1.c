void make_delay(long);

void setup() {
  volatile char *dir = (volatile char *)0x104;
  volatile char *out = (volatile char *)0x105;

  *dir = 0xFF;

  while (1)
  {
    *out = 0x01;
    make_delay(100000);
    *out = 0x00;
    make_delay(100000);
  }
}

void make_delay(long n)
{
  for (volatile long i = 0; i < n; i++);
}