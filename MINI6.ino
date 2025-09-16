void setup() {
  Serial.begin(9600);

  // 1. AND
  {
    uint8_t a = 0b11001100;
    uint8_t b = 0b10101010;
    uint8_t result;
    asm volatile (
      //move a and b to registers 16 and 17
      "mov r16, %[aval]\n\t"
      "mov r17, %[bval]\n\t"
      //perform and operation
      "and r16, r17\n\t"
      //move the result
      "mov %[res], r16\n\t"
      : [res] "=r"(result) // output
      : [aval] "r"(a), [bval] "r"(b) //input
      : "r16","r17" // clobbered registers
    );
    Serial.print("a AND b result = ");
    Serial.println(result, BIN);
  }

  // 2. ANDI
  {
    uint8_t a = 0b11001100;
    uint8_t result;
    asm volatile (
      "mov r16, %[aval]\n\t" // move a to r16
      "andi r16, 0xF0\n\t" // andi operation
      "mov %[res], r16\n\t" //move result
      : [res] "=r"(result) //input
      : [aval] "r"(a) //output 
      : "r16" // clobbered
    );
    Serial.print("a ANDI 0xF0 result = ");
    Serial.println(result, BIN);
  }

  // 3. ORI
  {
    uint8_t a = 0b11001100;
    uint8_t result;
    asm volatile (
      "mov r16, %[aval]\n\t" // move a to r16
      "ori r16, 0x0F\n\t" //ori operation
      "mov %[res], r16\n\t" // move result
      : [res] "=r"(result) // output
      : [aval] "r"(a) //input
      : "r16" //clobbered
    );
    Serial.print("a ORI 0x0F result = ");
    Serial.println(result, BIN);
  }

  // 4. OR
  {
    uint8_t a = 0b11001100;
    uint8_t b = 0b10101010;
    uint8_t result;
    asm volatile (
      "mov r16, %[aval]\n\t" // load a into r16
      "mov r17, %[bval]\n\t" //load b  into r17
      "or r16, r17\n\t" // a or b operation
      "mov %[res], r16\n\t" //move result
      : [res] "=r"(result) // output
      : [aval] "r"(a), [bval] "r"(b) //inputs
      : "r16","r17" //clobbered registers
    );
    Serial.print("a OR b result = ");
    Serial.println(result, BIN);
  }

  // 5. EOR
  {
    uint8_t a = 0b11001100;
    uint8_t b = 0b10101010;
    uint8_t result;
    asm volatile (
      "mov r16, %[aval]\n\t" // a into r16
      "mov r17, %[bval]\n\t" // b into r17
      "eor r16, r17\n\t" // XOR operation on a, b
      "mov %[res], r16\n\t" //move result
      : [res] "=r"(result) // output
      : [aval] "r"(a), [bval] "r"(b) //input
      : "r16","r17" // clobbered registers
    );
    Serial.print("a XOR b result = ");
    Serial.println(result, BIN);
  }

  // 6. COM
  {
    uint8_t a = 0b11001100;
    uint8_t result;
    asm volatile (
      "mov r16, %[aval]\n\t" // move a into r16
      "com r16\n\t"  //com operation
      "mov %[res], r16\n\t" //move result
      : [res] "=r"(result) //output
      : [aval] "r"(a) //input
      : "r16" //clobbered
    );
    Serial.print("a COM result = ");
    Serial.println(result, BIN);
  }

  // 7. NEG
  {
    uint8_t a = 0b00001100;
    uint8_t result;
    asm volatile (
      "mov r16, %[aval]\n\t" //a into r16
      "neg r16\n\t" //neg operation
      "mov %[res], r16\n\t" //move result to r16
      : [res] "=r"(result) //output
      : [aval] "r"(a)//input
      : "r16"//clobbered
    );
    Serial.print("a NEG result = ");
    Serial.println(result, BIN);
  }

  // 8. SBR
  {
    uint8_t value = 0b00001100;
    uint8_t result;
    asm volatile (
      "mov r16, %[val]\n\t" // value into r16
      "sbr r16, 0b00110000\n\t" //sbr on value
      "mov %[res], r16\n\t" //move to result
      : [res] "=r"(result) //output
      : [val] "r"(value) //input
      : "r16" //clobbered register
    );
    Serial.print("value with bits 4 and 5 set result = ");
    Serial.println(result, BIN);
  }

  // 9. CBR
  {
    uint8_t value = 0b11111111;
    uint8_t result;
    asm volatile (
      "mov r16, %[val]\n\t" // value into r16
      "cbr r16, 0b00001111\n\t" //clear br on r16
      "mov %[res], r16\n\t" //move result
      : [res] "=r"(result) //output
      : [val] "r"(value) //input
      : "r16" //clobbered
    );
    Serial.print("value with bits 0-3 cleared result = ");
    Serial.println(result, BIN);
  }

  // 10. MUL
  {
    uint8_t a = 10;
    uint8_t b = 20;
    uint16_t result;
    asm volatile (
      "mov r16, %[aval]\n\t" //a into r16
      "mov r17, %[bval]\n\t" //b into r17
      "mul r16, r17\n\t" //mul operation on r16 and r17
      "mov %A[res], r0\n\t" //move result
      "mov %B[res], r1\n\t" //move result
      "clr r0\n\t" //clear bit
      "clr r1\n\t" //clear bit
      : [res] "=r"(result) // output
      : [aval] "r"(a), [bval] "r"(b) //input
      : "r16","r17","r0","r1" //clobbered
    );
    Serial.print("a * b unsigned result (16-bit) = ");
    Serial.println(result, BIN);
  }

  // 11. MULS
  {
    int8_t a = -10;
    int8_t b = 20;
    int16_t result;
    asm volatile (
      "mov r16, %[aval]\n\t" // a into r16
      "mov r17, %[bval]\n\t" // b into r17
      "muls r16, r17\n\t" // muls operation
      "mov %A[res], r0\n\t" //move result
      "mov %B[res], r1\n\t" //move result
      "clr r0\n\t"
      "clr r1\n\t"// clr
      : [res] "=r"(result) //output
      : [aval] "r"(a), [bval] "r"(b) //inputs
      : "r16","r17","r0","r1" //clobbered registers
    );
    Serial.print("a * b signed result (16-bit) = ");
    Serial.println((uint16_t)result, BIN);

  }
}

void loop() {}
