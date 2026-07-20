void make_delay(volatile long);

void setup() {
  volatile char *dir = (volatile char *)0x21;
  volatile char *out = (volatile char *)0x22;

  *dir = 0xFF;

  int led_light[] = {0,2,1,3,4,6,5,7};
  
  while (1)
  {

    for (volatile int i = 0; i < 8; i++)
    {
      *out = (1 << led_light[i]);
      make_delay(500000);
    }
  }
}

void make_delay(volatile long n)
{
  for (volatile long i = 0; i < n; i++);
}
