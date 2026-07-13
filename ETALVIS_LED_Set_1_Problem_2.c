void setup() {
   volatile char *dir = (volatile char *)0x2A;
   volatile char *out = (volatile char *)0x2B;

   *dir = 0xFF;

   while (1) 
   {
      *out = 0x80;
   }
}

void loop() {
  // put your main code here, to run repeatedly:

}
