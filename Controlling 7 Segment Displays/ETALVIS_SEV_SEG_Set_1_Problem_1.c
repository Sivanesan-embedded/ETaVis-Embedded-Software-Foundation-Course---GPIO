void setup() {
  volatile char *dir = (volatile char *)0x21;
  volatile char *out = (volatile char *)0x22;

  *dir = 0xFF;

  int arr[] = {0x3F};

  while (1)
  {
    *out = arr[0];
  }
}

