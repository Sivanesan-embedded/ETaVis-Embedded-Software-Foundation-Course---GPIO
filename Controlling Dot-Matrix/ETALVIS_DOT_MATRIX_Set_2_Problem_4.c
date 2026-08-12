void Dot_Matrix_Init(volatile char *,volatile char *);
void make_delay(long);

char display_A[] = {0xF7,0xEB,0xDD,0xBE,0xBE,0x80,0xBE,0xBE};
char display_s[] = {0x80,0x7F,0x7F,0x81,0xFE,0xFE,0x01,0xFF};
char display_1[] = {0xE7,0xD7,0xF7,0xF7,0xF7,0xF7,0xC1,0xFF};
char display_2[] = {0x00,0xFE,0xFE,0x00,0x7F,0x7F,0x00,0xFF};

void setup() {
  

  volatile char *col_dir = (volatile char *)0x24;
  volatile char *col = (volatile char *)0x25;

  volatile char *row_dir = (volatile char *)0x21;
  volatile char *row = (volatile char *)0x22;

  Dot_Matrix_Init(col_dir,row_dir);


  while (1)
  {
     for (int i = 0; i < 8; i++)
     {
        *col = display_2[i];
        *row = (1 << i);
        *row = 0x00;
     }
  }
}

void Dot_Matrix_Init(volatile char *dir_a,volatile char *dir_b)
{
    *dir_a = 0xFF;
    *dir_b = 0xFF;
}

void make_delay(long n)
{
  for (int volatile long i = 0;i < n; i++);
}
