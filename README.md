# xan16

This project is designed as a simple CPU emulator application. The CPU emulator supports basic instruction commands, memory management, and input/output operations.

## Features

- **Registers and Memory Management:** 8 registers and 64 KiB of memory.
- **Program Counter (PC) and Stack Pointer (SP):** 16-bit values.
- **Basic Arithmetic and Logic Instructions:** ADD, ADC, AND, OR, XOR, CMP, SBB, NOR.
- **Memory and I/O Instructions:** MW (Memory Write), LW (Load Word), SW (Store Word), PUSH, POP, LDA (Load Address), INB (Input Byte), OUTB (Output Byte).
- **Conditional and Control Instructions:** JNZ (Jump if Not Zero).

## Installation and Usage

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/melihxz/xan16
   cd xan16
   ```

2. **Dependencies:**

   This project is written in C++. You will need a C++ compiler (e.g., `g++`) and CMake to build it.

3. **Build:**

   To build the project using CMake:

   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

4. **Run:**

   After building, an executable file named `cpu_emulator` will be created. You can run this file to use the emulator.