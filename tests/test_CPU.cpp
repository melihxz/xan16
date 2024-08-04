#include <gtest/gtest.h>
#include "CPU.h"

TEST(CPUTest, TestAddition) {
    CPU cpu;
    cpu.setRegister(0, 5);
    cpu.setRegister(1, 10);
    cpu.executeInstruction(0x00); // Example: ADD R0, R1
    EXPECT_EQ(cpu.getRegister(0), 15);
}

TEST(CPUTest, TestSubtraction) {
    CPU cpu;
    cpu.setRegister(0, 10);
    cpu.setRegister(1, 5);
    cpu.executeInstruction(0x01); // Example: SUB R0, R1
    EXPECT_EQ(cpu.getRegister(0), 5);
}
