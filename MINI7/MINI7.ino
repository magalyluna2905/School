void setup() {
  Serial.begin(9600);

//1.
  uint8_t resultLDI;

  asm volatile (

    "ldi r16, 0x3A \n\t"
    "mov %[output], r16 \n\t"
    : [output] "=r" (resultLDI)
    :
    :"r16"
  );

Serial.print("LDI Result in r16:  ");
Serial.println(resultLDI, HEX);
//2.
uint8_t resultMOV;
 asm volatile (

    "mov r17, r16 \n\t"
    "mov %[output], r17 \n\t"
    : [output] "=r" (resultMOV) 
    :
    :"r16", "r17"
  );


Serial.print("MOV Result in r17:  ");
Serial.println(resultMOV, HEX);
//3.
uint16_t resultMOVW;
asm volatile (
    "ldi r24, 0x12 \n\t"
    "ldi r25, 0x34 \n\t"
    "movw r26, r24 \n\t"
    "movw %[output], r26 \n\t"
    : [output] "=r" (resultMOVW)
    :
    :"r24", "r25", "r26", "r27"
  );

  Serial.print("MOVW Result:  ");
Serial.println(resultMOVW, HEX);



//4.




  uint8_t arr[2] = {0x20, 0x40};

  uint8_t result;

  asm volatile (
    "movw r26, %A[arr]\n\t"  
    "ld r16, X\n\t"           
    "mov %[res], r16\n\t"     
    : [res] "=r" (result)     
    : [arr] "e" (arr)       
    : "r16", "r26", "r27"     
  );

  
  Serial.print("LD result in r16: ");
  Serial.println(result, HEX);

//5.
uint8_t memoryX[2] = {0x34, 0x12};
uint8_t resultLDXPlus;
uint8_t resultNext;
uint16_t originalX, newX;

uint16_t addr = (uint16_t)(&memoryX[0]);

asm volatile (
  "movw r26, %[addr]\n\t"     
  "movw %A[origX], r26\n\t"   
  "ld r16, X+\n\t"            
  "mov %[firstOutput], r16\n\t"
  "ld r16, X\n\t"             
  "mov %[secondOutput], r16\n\t"
  "movw %A[newX], r26\n\t"    
  : [firstOutput] "=r" (resultLDXPlus), 
    [secondOutput] "=r" (resultNext),
    [origX] "=r" (originalX),
    [newX] "=r" (newX)
  : [addr] "r" (addr)
  : "r16", "r26", "r27"
);
 
  Serial.print("First LD X+ Result: ");
  Serial.println(resultLDXPlus, HEX);  

   Serial.print("Second LD X+ Result: ");
  Serial.println(resultNext, HEX); 

   Serial.print("Original X: ");
  Serial.println(originalX, HEX); 

 
}

void loop() {
  

}

