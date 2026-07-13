void setup() {
   volatile char *dir = (volatile char *)0x21;
   volatile char *out = (volatile char *)0x22;

   *dir = 0xFF;

   while (1) 
   {
      *out = 0x0F;
   }
}

void loop() {
  // put your main code here, to run repeatedly:

}
