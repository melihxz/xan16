#ifndef EMULATOR_H
#define EMULATOR_H

#include "../cpu/CPU.h"

class Emulator {
public:
    Emulator();
    void run();
    void loadROM(const char* fileName);
    CPU& getCPU() { return cpu; }
    
private:
    CPU cpu;
};

#endif
