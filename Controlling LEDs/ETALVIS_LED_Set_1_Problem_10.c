void setup() {
   volatile char *dir = (volatile char *)0x2D;
   volatile char *out = (volatile char *)0x2E;

   *dir = 0xFF;

   while (1) 
   {
      *out = 0x3A;
   }
}

