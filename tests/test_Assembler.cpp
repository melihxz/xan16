#include <gtest/gtest.h>
#include "Assembler.h"

TEST(AssemblerTest, TestAssembleMOV) {
    uint8_t machineCode[10];
    size_t size;
    assemble("MOV A, 1", machineCode, size);
    EXPECT_EQ(size, 2);
    EXPECT_EQ(machineCode[0], 0x00);
    EXPECT_EQ(machineCode[1], 0x01);
}

TEST(AssemblerTest, TestAssembleADD) {
    uint8_t machineCode[10];
    size_t size;
    assemble("ADD A, 2", machineCode, size);
    EXPECT_EQ(size, 2);
    EXPECT_EQ(machineCode[0], 0x09);
    EXPECT_EQ(machineCode[1], 0x02);
}
