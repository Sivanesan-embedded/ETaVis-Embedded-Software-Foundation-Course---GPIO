void setup() {
   volatile char *dir = (volatile char *)0x107;
   volatile char *out = (volatile char *)0x108;

   *dir = 0xFF;

   while (1) 
   {
      *out = 0x55;
   }
}

