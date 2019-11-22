#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <memory>
#include "block.h"
#include "level.h"
#include "display.h"

class Board{
    int boardNum; //player 0 or 1
    std::vector<std::unique_ptr<Block>> blocks;
    std::unique_ptr<Level> currLevel;
    
    public:
        Board(int boardNum);
        std::vector<std::unique_ptr<Block>> &getBlocks();
        void spawnBlock();
        void moveLeft();
        void moveRight();
        void drop();
};

#endif