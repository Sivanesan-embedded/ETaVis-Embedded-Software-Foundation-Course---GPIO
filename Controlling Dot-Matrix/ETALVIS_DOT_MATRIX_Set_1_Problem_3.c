void Dot_Matrix_Init(volatile char *,volatile char *);

void setup() {

  volatile char *col_dir = (volatile char *)0x24;
  volatile char *col = (volatile char *)0x25;

  volatile char *row_dir = (volatile char *)0x21;
  volatile char *row = (volatile char *)0x22;

  Dot_Matrix_Init(col_dir,row_dir);

  while (1)
  {
     *row = 0x80;
     *col = 0xFE;
  }
}

void Dot_Matrix_Init(volatile char *dir_a,volatile char *dir_b)
{
    *dir_a = 0xFF;
    *dir_b = 0xFF;
}
