void setup() {
   volatile char *dir = (volatile char *)0x30;
   volatile char *out = (volatile char *)0x31;

   *dir = 0xFF;

   while (1) 
   {
      *out = 0xFF;
   }
}
