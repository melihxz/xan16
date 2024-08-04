#include "emulator/Emulator.h"
#include "pong/PongGame.h"

int main() {
    Emulator emulator;
    emulator.loadROM("ponggame.rom");

    PongGame pongGame(emulator.getCPU());
    pongGame.run();

    emulator.run();
    return 0;
}
