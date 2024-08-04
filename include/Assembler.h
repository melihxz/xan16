#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <cstdint>
#include <cstddef>

void assemble(const char* sourceCode, uint8_t* machineCode, size_t& size);

#endif
