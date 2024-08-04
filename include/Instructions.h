#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "CPU.h"

void MW(CPU& cpu, uint8_t reg, uint8_t imm8);
void LW(CPU& cpu, uint8_t reg, uint16_t address);
void SW(CPU& cpu, uint16_t address, uint8_t reg);
void PUSH(CPU& cpu, uint8_t imm8);
void POP(CPU& cpu, uint8_t reg);
void LDA(CPU& cpu, uint16_t address);
void JNZ(CPU& cpu, uint8_t imm8);
void INB(CPU& cpu, uint8_t reg, uint8_t port);
void OUTB(CPU& cpu, uint8_t port, uint8_t reg);
void ADD(CPU& cpu, uint8_t reg, uint8_t imm8);
void ADC(CPU& cpu, uint8_t reg, uint8_t imm8);
void AND(CPU& cpu, uint8_t reg, uint8_t imm8);
void OR(CPU& cpu, uint8_t reg, uint8_t imm8);
void NOR(CPU& cpu, uint8_t reg, uint8_t imm8);
void CMP(CPU& cpu, uint8_t reg, uint8_t imm8);
void SBB(CPU& cpu, uint8_t reg, uint8_t imm8);

#endif
