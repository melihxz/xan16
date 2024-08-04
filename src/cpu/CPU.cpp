#include "CPU.h"
#include <iostream>
#include <cstring>

CPU::CPU() {
    std::memset(registers, 0, sizeof(registers));
    PC = 0;
    SP = MEMORY_SIZE - 1;
    HL = 0;
    std::memset(memory, 0, sizeof(memory));
    std::memset(ports, 0, sizeof(ports));
    flags.LESS = false;
    flags.EQUAL = false;
    flags.CARRY = false;
    flags.BORROW = false;
}

void CPU::loadProgram(const uint8_t* program, size_t size) {
    if (size > MEMORY_SIZE) {
        std::cerr << "Program size exceeds memory size." << std::endl;
        return;
    }
    std::memcpy(memory, program, size);
    PC = 0;
}

void CPU::executeInstruction() {
    uint8_t opcode = memory[PC++];
    switch (opcode) {
        case 0x00:  // MW
            MW(memory[PC++], memory[PC++]);
            break;
        case 0x01:  // LW
            LW(memory[PC++], memory[PC++] | (memory[PC++] << 8));
            break;
        case 0x02:  // SW
            SW(memory[PC++] | (memory[PC++] << 8), memory[PC++]);
            break;
        case 0x03:  // PUSH
            PUSH(memory[PC++]);
            break;
        case 0x04:  // POP
            POP(memory[PC++]);
            break;
        case 0x05:  // LDA
            LDA(memory[PC++] | (memory[PC++] << 8));
            break;
        case 0x06:  // JNZ
            JNZ(memory[PC++] | (memory[PC++] << 8));
            break;
        case 0x07:  // INB
            INB(memory[PC++], memory[PC++]);
            break;
        case 0x08:  // OUTB
            OUTB(memory[PC++], memory[PC++]);
            break;
        case 0x09:  // ADD
            ADD(memory[PC++], memory[PC++]);
            break;
        case 0x0A:  // ADC
            ADC(memory[PC++], memory[PC++]);
            break;
        case 0x0B:  // AND
            AND(memory[PC++], memory[PC++]);
            break;
        case 0x0C:  // OR
            OR(memory[PC++], memory[PC++]);
            break;
        case 0x0D:  // XOR
            XOR(memory[PC++], memory[PC++]);
            break;
        case 0x0E:  // CMP
            CMP(memory[PC++], memory[PC++]);
            break;
        case 0x0F:  // SBB
            SBB(memory[PC++], memory[PC++]);
            break;
        default:
            std::cerr << "Unknown opcode: " << std::hex << static_cast<int>(opcode) << std::endl;
            break;
    }
}

// Implementations for MW, LW, SW, PUSH, POP, LDA, JNZ, INB, OUTB, ADD, ADC, AND, OR, XOR, CMP, SBB
void CPU::MW(uint8_t reg, uint8_t imm8) {
    registers[reg] = imm8;
}

void CPU::LW(uint8_t reg, uint16_t address) {
    if (address < MEMORY_SIZE) {
        registers[reg] = memory[address];
    } else {
        std::cerr << "Address out of range in LW instruction." << std::endl;
    }
}

void CPU::SW(uint16_t address, uint8_t reg) {
    if (address < MEMORY_SIZE) {
        memory[address] = registers[reg];
    } else {
        std::cerr << "Address out of range in SW instruction." << std::endl;
    }
}

void CPU::PUSH(uint8_t imm8) {
    if (SP > 0) {
        memory[SP--] = imm8;
    } else {
        std::cerr << "Stack overflow in PUSH instruction." << std::endl;
    }
}

void CPU::POP(uint8_t reg) {
    if (SP < MEMORY_SIZE - 1) {
        registers[reg] = memory[++SP];
    } else {
        std::cerr << "Stack underflow in POP instruction." << std::endl;
    }
}

void CPU::LDA(uint16_t address) {
    if (address < MEMORY_SIZE) {
        HL = address;
    } else {
        std::cerr << "Address out of range in LDA instruction." << std::endl;
    }
}

void CPU::JNZ(uint16_t address) {
    if (address < MEMORY_SIZE) {
        if (registers[0] != 0) {
            PC = address;
        }
    } else {
        std::cerr << "Address out of range in JNZ instruction." << std::endl;
    }
}

void CPU::INB(uint8_t reg, uint8_t port) {
    if (port < 256) {
        registers[reg] = ports[port];
    } else {
        std::cerr << "Port out of range in INB instruction." << std::endl;
    }
}

void CPU::OUTB(uint8_t port, uint8_t reg) {
    if (port < 256) {
        ports[port] = registers[reg];
    } else {
        std::cerr << "Port out of range in OUTB instruction." << std::endl;
    }
}

void CPU::ADD(uint8_t reg, uint8_t imm8) {
    registers[reg] += imm8;
}

void CPU::ADC(uint8_t reg, uint8_t imm8) {
    registers[reg] += imm8 + (flags.CARRY ? 1 : 0);
}

void CPU::AND(uint8_t reg, uint8_t imm8) {
    registers[reg] &= imm8;
}

void CPU::OR(uint8_t reg, uint8_t imm8) {
    registers[reg] |= imm8;
}

void CPU::XOR(uint8_t reg, uint8_t imm8) {
    registers[reg] ^= imm8;
}

void CPU::CMP(uint8_t reg, uint8_t imm8) {
    uint8_t result = registers[reg] - imm8;
    flags.CARRY = registers[reg] < imm8;
    flags.EQUAL = (registers[reg] == imm8);
    flags.LESS = (result > registers[reg]);
}

void CPU::SBB(uint8_t reg, uint8_t imm8) {
    registers[reg] -= imm8 + (flags.BORROW ? 1 : 0);
}

void CPU::NOR(uint8_t reg, uint8_t imm8) {
    registers[reg] = ~(registers[reg] | imm8);
}
