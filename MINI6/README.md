# AVR Inline Assembly: Bitwise and Multiplication Operations

This project demonstrates **AVR inline assembly instructions** for performing bitwise operations and multiplication on an 8-bit microcontroller (e.g., Arduino). The code showcases operations such as AND, OR, XOR, COM, NEG, SBR, CBR, and both signed and unsigned multiplication.

---

## Project Description
The goal of this project is to practice low-level programming on an AVR microcontroller using inline assembly. The program demonstrates the following operations:

### **Bitwise Operations**
1. **AND** – Logical AND between two 8-bit numbers  
2. **ANDI** – Logical AND with an immediate value  
3. **OR** – Logical OR between two 8-bit numbers  
4. **ORI** – Logical OR with an immediate value  
5. **EOR (XOR)** – Exclusive OR between two numbers  
6. **COM** – One’s complement (bit inversion)  
7. **NEG** – Two’s complement (negation)  
8. **SBR** – Set specific bits in a register  
9. **CBR** – Clear specific bits in a register  

### **Multiplication Operations**
10. **MUL** – Unsigned 8-bit multiplication producing a 16-bit result  
11. **MULS** – Signed 8-bit multiplication producing a 16-bit result  

The results are printed to the **Serial Monitor** in binary format.

---

## Variables Used
| Variable | Type | Description |
|----------|------|-------------|
| `a`, `b`, `value` | `uint8_t` / `int8_t` | Input operands for bitwise and multiplication operations |
| `result` | `uint8_t` / `uint16_t` / `int16_t` | Stores the result of each operation |

---

## How It Works
- Each operation is implemented using **inline assembly (`asm volatile`)**.  
- Input values are moved into registers (`r16`, `r17`) for processing.  
- The result is stored back into a variable and printed via the Serial Monitor.  
- The program prints the results of all operations sequentially.

---

## Tools & Languages
- **Language:** C/C++ with AVR Inline Assembly  
- **Platform:** Arduino / AVR microcontroller  
- **IDE:** Arduino IDE  

---

## Usage
1. Connect your AVR microcontroller to your computer.  
2. Open the code in the Arduino IDE.  
3. Upload the program to the microcontroller.  
4. Open the **Serial Monitor** at 9600 baud to see the results of all operations.  

---

