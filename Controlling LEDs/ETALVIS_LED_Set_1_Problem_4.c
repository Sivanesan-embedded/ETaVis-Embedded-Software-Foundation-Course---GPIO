void setup() {
   volatile char *dir = (volatile char *)0x27;
   volatile char *out = (volatile char *)0x28;

   *dir = 0xFF;

   while (1) 
   {
      *out = 0xC0;
   }
}

void loop() {
  // put your main code here, to run repeatedly:

}
