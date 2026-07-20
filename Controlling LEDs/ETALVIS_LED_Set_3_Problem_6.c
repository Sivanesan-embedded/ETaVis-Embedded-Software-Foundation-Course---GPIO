void make_delay(volatile long);

void setup() {
  volatile char *dir = (volatile char *)0x21;
  volatile char *out = (volatile char *)0x22;

  *dir = 0xFF;

  int s = 0, l = 1;
  
  while (1)
  {
    *out = 0x00;
    make_delay(100000);

    s = 4, l = 5;

    for (volatile int j = 0; j < 4; j++)
    {
    for (volatile int i = 0; i < 8; i++)
    {
      if ((s == i) || (l == i))
      {
        *out |= (1 << i);
      }
      else
      {
        *out &= ~(1 << i);
      }
    }
     make_delay(500000);
     if (j == 1) 
     {
       s = 6; l = 7;
     }
     if (j == 0) 
     {
       s = 2; l = 3;
     }
     if (j == 2) 
     {
       s = 0; l = 1;
     }
     *out = 0x00;
    }

    *out = 0x00;
    make_delay(100000);
  }
}

void make_delay(volatile long n)
{
  for (volatile long i = 0; i < n; i++);
}
