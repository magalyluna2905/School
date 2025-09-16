# AVR Inline Assembly: LDI, MOV, MOVW, and LD Operations

This project demonstrates basic **AVR inline assembly instructions** for loading and moving data on an 8-bit microcontroller (e.g., Arduino). It focuses on LDI, MOV, MOVW, and LD operations, showing how to manipulate registers and memory directly.

---

## Project Description
The purpose of this project is to practice low-level programming on an AVR microcontroller using inline assembly. The program performs the following operations:

### **1. LDI (Load Immediate)**
- Loads an 8-bit constant directly into a register (`r16`).  
- Example: `ldi r16, 0x3A`  

### **2. MOV (Move Register)**
- Copies the value from one register to another (`r16` → `r17`).  

### **3. MOVW (Move Word)**
- Moves a 16-bit word between register pairs (`r24:r25` → `r26:r27`).  

### **4. LD (Load from SRAM)**
- Loads a value from memory into a register using the X pointer (`r26:r27`).  
- Demonstrates normal `LD` and post-increment `LD X+` addressing modes.  

---

## Variables Used
| Variable | Type | Description |
|----------|------|-------------|
| `resultLDI` | `uint8_t` | Stores result of LDI operation |
| `resultMOV` | `uint8_t` | Stores result of MOV operation |
| `resultMOVW` | `uint16_t` | Stores result of MOVW operation |
| `arr` | `uint8_t[2]` | Array used for LD operations |
| `result` | `uint8_t` | Stores value loaded from array using LD |
| `memoryX` | `uint8_t[2]` | Array used for LD X+ operations |
| `resultLDXPlus` | `uint8_t` | First value loaded using `LD X+` |
| `resultNext` | `uint8_t` | Second value loaded from X pointer |
| `originalX` | `uint16_t` | Stores the original X register address |
| `newX` | `uint16_t` | Stores the updated X register address |

---

## How It Works
- Inline assembly (`asm volatile`) is used to move and load data into AVR registers.  
- The **Serial Monitor** prints results in **HEX format** for verification.  
- The program shows how immediate values, register moves, word moves, and SRAM loads are performed at the assembly level.

---

## Tools & Languages
- **Language:** C/C++ with AVR Inline Assembly  
- **Platform:** Arduino / AVR microcontroller  
- **IDE:** Arduino IDE  

---

## Usage
1. Connect your AVR microcontroller to your computer.  
2. Open the code in the Arduino IDE.  
3. Upload the program.  
4. Open the **Serial Monitor** at 9600 baud to view the results of all operations.

---

