uint8_t a =15; //1st number
uint8_t b = 25; //2nd number
uint8_t c = 40; //3rd number
uint16_t wordResult = 1000;
uint8_t result;
uint8_t subResult;
uint8_t carryFlag;
uint8_t sumc;
uint8_t subiResult;
uint8_t subiCResult;
uint16_t wordAddResult;
uint16_t wordSubResult;

void setup() {
  Serial.begin(9600);

  asm volatile (
  //adding a +b = result
  "mov r16, %[valA] \n\t"
  "mov r17, %[valB] \n\t"
  "add r16, r17 \n\t"
  "mov %[sum], r16"
  :[sum] "=r" (result)
  :[valA] "r" (a), [valB] "r" (b)
  :"r16","r17"
  );

  asm volatile (
  //subtracting result - c = result
  "mov r16, %[valresult] \n\t"
  "mov r17, %[valC] \n\t"
  "sub r16, r17 \n\t"
  "mov %[result], r16\n\t"
  :[result] "=r" (subResult)
  :[valresult] "r" (result), [valC] "r" (c)
  :"r16","r17"
  );

  asm volatile (
  //add with carry
  "mov r16, %[valA] \n\t"
  "mov r17, %[valB] \n\t"
  "sec \n\t"
  "adc r16, r17 \n\t"
  "mov %[sumc], r16\n\t"
  "in r18, __SREG__ \n\t"
  "andi r18, 0x01 \n\t"
  "mov %[carry], r18\n\t"
  :[sumc] "=r" (sumc), [carry] "=r" (carryFlag)
  :[valA] "r" (a), [valB] "r" (b)
  :"r16","r17","r18"
  );

  asm volatile (
  //subtract immediate and carry
  "mov r16, %[valC] \n\t"
  "subi r16, 10 \n\t"
  "mov %[subiRes], r16 \n\t"
  "sec \n\t"
  "sbc r16, %[valB] \n\t"
  "mov %[subiCRes], r16 \n\t"
  :[subiRes] "=r" (subiResult), [subiCRes] "=r" (subiCResult)
  :[valC] "r" (c), [valB] "r" (b)
  :"r16"
  );

  asm volatile (
  //ADDIW
  "movw r26, %A[val] \n\t"
  "adiw r26, 53 \n\t"
  "movw %A[res], r26"
  :[res] "=r" (wordAddResult)
  :[val] "r" (wordResult)
  :"r26","r27"
  );

  asm volatile (
  //SBIW
  "movw r26, %A[val] \n\t"
  "sbiw r26, 24 \n\t"
  "movw %A[res], r26"
  :[res] "=r" (wordSubResult)
  
  :[val] "r" (wordResult)
  :"r26","r27"
  );

  Serial.println(subResult);
  Serial.println(sumc);
 
  Serial.println(carryFlag);
  Serial.println(subiResult);
  Serial.println(subiCResult);
  Serial.println(wordAddResult);
  Serial.println(wordSubResult);
}

void loop() {
  delay(1000);
}
