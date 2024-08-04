#include "Emulator.h"
#include <fstream>
#include <iostream>
#include <chrono>
#include <thread>

Emulator::Emulator() {}

void Emulator::loadROM(const char* fileName) {
    std::ifstream file(fileName, std::ios::binary);
    if (file) {
        file.read(reinterpret_cast<char*>(cpu.memory), MEMORY_SIZE);
        cpu.PC = 0;
    } else {
        std::cerr << "Error loading ROM file." << std::endl;
    }
}

void Emulator::run() {
    while (true) {
        cpu.executeInstruction();
        // Check for a break condition
        if (cpu.isHalted()) {
            std::cout << "CPU halted." << std::endl;
            break;
        }
        // Add a delay to control execution speed
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
