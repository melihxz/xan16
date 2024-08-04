#include "Instructions.h"

void MW(CPU& cpu, uint8_t reg, uint8_t imm8) {
    cpu.registers[reg] = imm8;
}

void LW(CPU& cpu, uint8_t reg, uint16_t address) {
    cpu.registers[reg] = cpu.memory[address];
}

void SW(CPU& cpu, uint16_t address, uint8_t reg) {
    cpu.memory[address] = cpu.registers[reg];
}

void PUSH(CPU& cpu, uint8_t imm8) {
    cpu.memory[cpu.SP--] = imm8;
}

void POP(CPU& cpu, uint8_t reg) {
    cpu.registers[reg] = cpu.memory[++cpu.SP];
}

void LDA(CPU& cpu, uint16_t address) {
    cpu.HL = address;
}

void JNZ(CPU& cpu, uint8_t imm8) {
    if (cpu.registers[0] != 0)
        cpu.PC = imm8;
}

void INB(CPU& cpu, uint8_t reg, uint8_t port) {
    cpu.registers[reg] = cpu.ports[port];
}

void OUTB(CPU& cpu, uint8_t port, uint8_t reg) {
    cpu.ports[port] = cpu.registers[reg];
}

void ADD(CPU& cpu, uint8_t reg, uint8_t imm8) {
    cpu.registers[reg] += imm8;
}

void ADC(CPU& cpu, uint8_t reg, uint8_t imm8) {
    cpu.registers[reg] += imm8 + cpu.flags.CARRY;
}

void AND(CPU& cpu, uint8_t reg, uint8_t imm8) {
    cpu.registers[reg] &= imm8;
}

void OR(CPU& cpu, uint8_t reg, uint8_t imm8) {
    cpu.registers[reg] |= imm8;
}

void NOR(CPU& cpu, uint8_t reg, uint8_t imm8) {
    cpu.registers[reg] = ~(cpu.registers[reg] | imm8);
}

void CMP(CPU& cpu, uint8_t reg, uint8_t imm8) {
    uint8_t result = cpu.registers[reg] - imm8;
    cpu.flags.CARRY = cpu.registers[reg] < imm8;
    cpu.flags.EQUAL = (cpu.registers[reg] == imm8);
    cpu.flags.LESS = (result > cpu.registers[reg]);
}
