#ifndef CPU_H
#define CPU_H

#include <cstdint>

#define MEMORY_SIZE 65536  // 64 KiB

class CPU {
public:
    CPU();
    void executeInstruction();
    void loadProgram(const uint8_t* program, size_t size);
    
    // Public member functions
    void MW(uint8_t reg, uint8_t imm8);       // Memory Write
    void LW(uint8_t reg, uint16_t address);   // Load Word
    void SW(uint16_t address, uint8_t reg);   // Store Word
    void PUSH(uint8_t imm8);                  // Push Immediate
    void POP(uint8_t reg);                    // Pop to Register
    void LDA(uint16_t address);               // Load Address
    void JNZ(uint16_t address);               // Jump if Not Zero
    void INB(uint8_t reg, uint8_t port);      // Input Byte
    void OUTB(uint8_t port, uint8_t reg);     // Output Byte
    void ADD(uint8_t reg, uint8_t imm8);      // Add
    void ADC(uint8_t reg, uint8_t imm8);      // Add with Carry
    void AND(uint8_t reg, uint8_t imm8);      // Logical AND
    void OR(uint8_t reg, uint8_t imm8);       // Logical OR
    void XOR(uint8_t reg, uint8_t imm8);      // Logical XOR
    void CMP(uint8_t reg, uint8_t imm8);      // Compare
    void SBB(uint8_t reg, uint8_t imm8);      // Subtract with Borrow
    void NOR(uint8_t reg, uint8_t imm8);      // Logical NOR

    uint8_t registers[8];
    uint16_t HL;  // 16-bit register for address
    uint16_t PC;  // Program Counter
    uint16_t SP;  // Stack Pointer
    struct Flags {
        bool LESS;
        bool EQUAL;
        bool CARRY;
        bool BORROW;
    } flags;
    uint8_t memory[MEMORY_SIZE];
    uint8_t ports[256];  // 8-bit ports
};

#endif // CPU_H
