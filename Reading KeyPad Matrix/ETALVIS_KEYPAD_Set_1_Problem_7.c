#include <Arduino.h>

void make_delay(long);
int map_keys(int,int);
void display_number(int *);
void display_number_f(int *);
void display_neg_number(int *);

volatile char *seg_dir = (volatile char *)0x24;
volatile char *seg = (volatile char *)0x25;

volatile char *con_dir = (volatile char *)0x2A;
volatile char *con = (volatile char *)0x2B;

int arr[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
int display[] = {-1,-1,-1,-1};
int control[] = {0xFE,0xFD,0xFB,0xF7};

int inc = 0, count = 0;
long long sum = 0,sum_1 = 0,sum_2 = 0;

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
      for (int i = 0; i < 4; i++)
      {
          *row = (1<<i);

          if (*col)
          {
             display[inc] = map_keys(i,*col);
             display_number_f(display);

             if (display[inc] == 'A')
             {
                display[0] = -1;
                display[1] = -1;
                display[2] = -1;
                display[3] = -1;
                inc = 0;
                count = 4;
                break;
             }

             if (display[inc] == 'D')
             {
                sum = (long long)sum_1 - sum_2;
                if (sum < 0)
                {
                  sum *= -1;
                  
                  display_neg_number(display);
                }
                else
                {
                  display_number(display);
                }

                 sum = 0;
                 sum_1 = 0;
                 sum_2 = 0;
                 display[0] = -1;
                 display[1] = -1;
                 display[2] = -1;
                 display[3] = -1;
                 inc = 0;
                 count = 0;
                 break;
             }

             if (count > 3)
             {
                sum_2 = (sum_2 * 10) + display[inc];
             }

             else if (count <= 3) 
             {
                 sum_1 = (sum_1 * 10) + display[inc];
             }

             inc++;

             if (count == 7)
             {
                 sum = (long long)sum_1 - sum_2;
                 if (sum < 0)
                {
                  sum *= -1;
                  
                  display_neg_number(display);
                }
                else
                {
                  display_number(display);
                }
                 sum = 0;
                 sum_1 = 0;
                 sum_2 = 0;
                 display[0] = -1;
                 display[1] = -1;
                 display[2] = -1;
                 display[3] = -1;
                 inc = 0;
                 count = 0;
                 break;
             }

             if (count == 3) 
             {
                display[0] = -1;
                display[1] = -1;
                display[2] = -1;
                display[3] = -1;
                inc = 0;
             }

             count++;

             while (*col);
          }
      }
  }
}

void display_number_f(int *display)
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
}

void display_number(int *display)
{
  for (int k = 0; k < 35; k++)
  {
    for (int i = 0; i < 4; i++)
    {
        if (sum > 9999)
        {
          *seg = 0x79;
          *con = control[i];
          make_delay(5000);
          *con = 0xFF;  
        }

        else if (sum/1000)
        {
          long long dis[] = {(sum/1000),(sum/100)%10,(sum/10)%10,sum%10};

          *seg = arr[dis[i]];
          *con = control[i];
          make_delay(5000);
          *con = 0xFF;  
        }

        else if (sum/100)
        {
          *seg = arr[sum / 100];
          *con = 0xFE;
          make_delay(5000);
          *con = 0xFF;  

          *seg = arr[(sum / 10)%10];
          *con = 0xFD;
          make_delay(5000);
          *con = 0xFF;  

          *seg = arr[sum % 10];
          *con = 0xFB;
          make_delay(5000);
          *con = 0xFF;  
        }
        else if (sum/10)
        {
          *seg = arr[sum / 10];
          *con = 0xFE;
          make_delay(5000);
          *con = 0xFF;  

          *seg = arr[sum % 10];
          *con = 0xFD;
          make_delay(5000);
          *con = 0xFF;  
        }
        else
        {
          *seg = arr[sum];
          *con = 0xFE;
          make_delay(5000);
          *con = 0xFF;  
        }
    }
  }
}

void display_neg_number(int *)
{
   for (int k = 0; k < 35; k++)
  {
    for (int i = 0; i < 4; i++)
    {
        if (sum > 999)
        {
          *seg = 0x79;
          *con = control[i];
          make_delay(5000);
          *con = 0xFF;  
        }

        else if (sum/100)
        {
          //long long dis[] = {,(sum/100)%10,(sum/10)%10,sum%10};

          *seg = 0x40;
          *con = 0xFE;
          make_delay(5000);
          *con = 0xFF;  
          
          *seg = arr[sum / 100];
          *con = 0xFD;
          make_delay(5000);
          *con = 0xFF;  

          *seg = arr[(sum / 10)%10];
          *con = 0xFB;
          make_delay(5000);
          *con = 0xFF;  

          *seg = arr[sum % 10];
          *con = 0xF7;
          make_delay(5000); 
          *con = 0xFF;  
        }

        else if (sum/10)
        {
          *seg = 0x40;
          *con = 0xFE;
          make_delay(5000);
          *con = 0xFF; 

          *seg = arr[sum / 10];
          *con = 0xFD;
          make_delay(5000);
          *con = 0xFF;  

          *seg = arr[sum % 10];
          *con = 0xFB;
          make_delay(5000);
          *con = 0xFF;  
        }
        else
        {
          *seg = 0x40;
          *con = 0xFE;
          make_delay(5000);
          *con = 0xFF; 

          *seg = arr[sum];
          *con = 0xFD;
          make_delay(5000);
          *con = 0xFF;  
        }
    }
  }
}

void make_delay(long n)
{
  for (volatile long i = 0; i < n; i++);
}

int map_keys(int row,int col)
{

  if ((row == 0) && (col == 1)) return 1;
  if ((row == 0) && (col == 2)) return 2;
  if ((row == 0) && (col == 4)) return 3;
  if ((row == 0) && (col == 8)) return 'A';

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
  if ((row == 3) && (col == 8)) return 'D';

  return 0;
}