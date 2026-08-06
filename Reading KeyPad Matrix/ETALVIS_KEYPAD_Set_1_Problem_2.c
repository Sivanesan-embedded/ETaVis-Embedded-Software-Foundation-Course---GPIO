#include <Arduino.h>

void make_delay(long);
int map_keys(int,int);
void display_number(int *,int);

volatile char *seg_dir = (volatile char *)0x24;
volatile char *seg = (volatile char *)0x25;

volatile char *con_dir = (volatile char *)0x2A;
volatile char *con = (volatile char *)0x2B;

int arr[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
int display[] = {-1,-1,-1,-1};
int control[] = {0xFE,0xFD,0xFB,0xF7};

int inc = 0;


void setup() {

  volatile char *row_dir = (volatile char *)0x30;
  volatile char *row = (volatile char *)0x31;
  volatile char *col_dir = (volatile char *)0x107;
  volatile char *col = (volatile char *)0x106;

  volatile char *dir_a = (volatile char *)0x21;
  volatile char *out_a = (volatile char *)0x22;

  *row_dir = 0xFF;
  *col_dir = 0x00;
  *dir_a = 0xFF;
  *seg_dir = 0xFF;
  *con_dir = 0xFF;

  *con = 0xFF;

  while (1)
  {
    //inc = 0;

      for (int i = 0; i < 4; i++)
      {
          *row = (1<<i);

          if (*col)
          {
             display[inc++] = map_keys(i,*col);
             display_number(display,inc);

             if (inc == 5)
             {
              inc = 0;
              for (int i = 0; i < 5; i++)
              {
                  arr[i] = -1;
              }
             }

             while (*col);
          }
      }
  }
}

void display_number(int *display,int inc)
{
  for (int k = 0; k < 25; k++)
  {
    for (int i = 0; i < 4; i++)
    {
        if (display[i] != -1)
          {
            *seg = arr[display[i]];
            *con = control[i];
            make_delay(5000);
            *con = 0xFF;
          }  
    }
  }
//   *con = 0x00;
// *seg = arr[inc]; 
  // if (display[0] != -1)
  // *seg = arr[display[0]];

  // if (display[1] != -1)
  // *seg = arr[display[1]];
}

void make_delay(long n)
{
  for (volatile long i = 0; i < n; i++);
}

int map_keys(int row,int col)
{
  int r = 0, c = 0;

  if ((row == 0) && (col == 1)) return 1;
  if ((row == 0) && (col == 2)) return 2;
  if ((row == 0) && (col == 4)) return 3;
  //if ((row == 0) && (col == 8)) return 'A';

  if ((row == 1) && (col == 1)) return 4;
  if ((row == 1) && (col == 2)) return 5;
  if ((row == 1) && (col == 4)) return 6;
  //if ((row == 1) && (col == 8)) return 'B';

  if ((row == 2) && (col == 1)) return 7;
  if ((row == 2) && (col == 2)) return 8;
  if ((row == 2) && (col == 4)) return 9;
  //if ((row == 2) && (col == 8)) return 'C';

  //if ((row == 3) && (col == 1)) return '*';
  if ((row == 3) && (col == 2)) return 0;
  //if ((row == 3) && (col == 4)) return '#';
  //if ((row == 3) && (col == 8)) return 'D';
}