void setup() {
   volatile char *dir = (volatile char *)0x104;
   volatile char *out = (volatile char *)0x105;

   *dir = 0xFF;

   while (1) 
   {
      *out = 0x01;
   }
}

void loop() {
  // put your main code here, to run repeatedly:

}
