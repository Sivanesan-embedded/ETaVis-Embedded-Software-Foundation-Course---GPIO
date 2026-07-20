void setup() {
   volatile char *dir = (volatile char *)0x10A;
   volatile char *out = (volatile char *)0x10B;

   *dir = 0xFF;

   while (1) 
   {
      *out = 0xAA;
   }
}

