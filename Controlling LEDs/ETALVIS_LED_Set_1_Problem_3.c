void setup() {
   volatile char *dir = (volatile char *)0x101;
   volatile char *out = (volatile char *)0x102;

   *dir = 0xFF;

   while (1) 
   {
      *out = 0x03;
   }
}

void loop() {
  // put your main code here, to run repeatedly:

}
