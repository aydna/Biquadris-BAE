#ifndef GAME_H
#define GAME_H
#include <memory>
#include <utility>
#include <iostream>
#include "board.h"
#include "display.h"

class Game{
    Display *d;
    // also figure out the 3 reserve rows problem
    std::pair<int,int> boardSize = std::pair<int,int>(18,11); // change to solid numbers
    int playerTurn;
    std::unique_ptr<Board> b1;
    std::unique_ptr<Board> b2;
    //next block???? Display needs to know before it spawns? Level should do something i think? queue the next block or something
    public:
        Game(Display *d);
        void spawnBlock();
        void moveRight(int distance);
        void moveLeft(int distance);
        void moveDown(int distance);
        void rotateCW(int times);
        void rotateCCW(int times);
        void drop();
};

#endif