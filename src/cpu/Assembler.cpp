#include "Assembler.h"
#include <cstring>
#include <iostream>

void assemble(const char* sourceCode, uint8_t* machineCode, size_t& size) {
    size = 0;
    // Example assembly conversion
    if (std::strcmp(sourceCode, "MOV A, 1") == 0) {
        machineCode[size++] = 0x00; // MOV opcode
        machineCode[size++] = 0x01; // Operand
    }
    else if (std::strcmp(sourceCode, "ADD A, 2") == 0) {
        machineCode[size++] = 0x09; // ADD opcode
        machineCode[size++] = 0x02; // Operand
    }
    // Add other instructions here as needed
}
