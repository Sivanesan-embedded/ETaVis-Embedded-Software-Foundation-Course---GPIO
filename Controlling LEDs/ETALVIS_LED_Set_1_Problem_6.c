void setup() {
   volatile char *dir = (volatile char *)0x24;
   volatile char *out = (volatile char *)0x25;

   *dir = 0xFF;

   while (1) 
   {
      *out = 0xF0;
   }
}

void loop() {
  // put your main code here, to run repeatedly:

}