#ifndef PONGGAME_H
#define PONGGAME_H

#include "CPU.h"

class PongGame {
public:
    PongGame(CPU& cpu);
    void run();
    
private:
    CPU& cpu;
    // Game state variables
    int paddle1Y;
    int paddle2Y;
    int ballX;
    int ballY;
    int ballVelocityX;
    int ballVelocityY;

    // Additional methods
    void updateGameState();
    void handleInput();
    void render();
};

#endif
