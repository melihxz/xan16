#include "PongGame.h"
#include <iostream>
#include <termios.h>
#include <fcntl.h>
#include <chrono>
#include <thread>

PongGame::PongGame(CPU& cpu) 
    : cpu(cpu), paddle1Y(10), paddle2Y(10), ballX(40), ballY(12), 
      ballVelocityX(1), ballVelocityY(1) {}

void PongGame::run() {
    std::cout << "Running Pong Game..." << std::endl;
    while (true) {
        handleInput();
        updateGameState();
        render();
        // Add delay to control game speed
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void PongGame::updateGameState() {
    // Move the ball
    ballX += ballVelocityX;
    ballY += ballVelocityY;

    // Ball collision with top and bottom walls
    if (ballY <= 0 || ballY >= 23) {
        ballVelocityY = -ballVelocityY;
    }

    // Ball collision with paddles
    if ((ballX == 2 && ballY >= paddle1Y && ballY <= paddle1Y + 3) || 
        (ballX == 77 && ballY >= paddle2Y && ballY <= paddle2Y + 3)) {
        ballVelocityX = -ballVelocityX;
    }

    // Ball out of bounds
    if (ballX < 0 || ballX > 79) {
        // Reset ball to center
        ballX = 40;
        ballY = 12;
        ballVelocityX = -ballVelocityX;
    }
}

bool kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF) {
        ungetc(ch, stdin);
        return true;
    }

    return false;
}

char getch() {
    struct termios oldt, newt;
    int ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

void PongGame::handleInput() {
    if (kbhit()) {
        char ch = getch();
        switch (ch) {
            case 'w':
                if (paddle1Y > 0) paddle1Y--;
                break;
            case 's':
                if (paddle1Y < 20) paddle1Y++;
                break;
            case 'i':
                if (paddle2Y > 0) paddle2Y--;
                break;
            case 'k':
                if (paddle2Y < 20) paddle2Y++;
                break;
            case 'q':
                exit(0);
                break;
        }
    }
}

void PongGame::render() {
    std::system("clear"); // Clear the console

    // Draw paddles
    for (int i = 0; i < 4; ++i) {
        std::cout << std::string(2, ' ') << std::string(paddle1Y + i, ' ') << "||" << std::endl;
        std::cout << std::string(76, ' ') << std::string(paddle2Y + i, ' ') << "||" << std::endl;
    }

    // Draw ball
    for (int i = 0; i < 23; ++i) {
        if (i == ballY) {
            std::cout << std::string(ballX, ' ') << '*' << std::endl;
        } else {
            std::cout << std::endl;
        }
    }

    // Draw the game border
    std::cout << std::string(80, '-') << std::endl;
}
