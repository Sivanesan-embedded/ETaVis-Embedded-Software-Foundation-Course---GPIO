void make_delay(volatile long);

void setup() {
  volatile char *dir_a = (volatile char *)0x21;
  volatile char *out_a = (volatile char *)0x22;
  volatile char *dir_b = (volatile char *)0x24;
  volatile char *out_b = (volatile char *)0x25;

  *dir_a = 0xFF;
  *dir_b = 0xFF;

  int limit = 0;
  
  while (1)
  {
     for (int i = 0; i < 8; i++)
     {
        if (!(i%2))
        {
        *out_a = (1 << i);
        make_delay(200000);
        }
     }

     *out_a = 0x00;

      for (int i = 0; i < 8; i++)
     {
        if ((i%2))
        {
        *out_b = (1 << i);
        make_delay(200000);
        }
     }

     *out_b = 0x00;

      for (int i = 7; i >= 0; i--)
     {
        if (i%2)
        {
        *out_b = (1 << i);
        make_delay(200000);
        }
     }

     *out_b = 0x00;

     for (int i = 7; i >= 0; i--)
     {
        if (!(i%2))
        {
        *out_a = (1 << i);
        make_delay(200000);
        }
     }

     *out_a = 0x00;

  }
}

void make_delay(volatile long n)
{
  for (volatile long i = 0; i < n; i++);
}
