#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <memory>
#include <utility>
#include <string>
#include "block.h"
#include "level.h"
#include "drawer.h"

class Board{
    int level;
    int seed;
    std::string file;
    int score;
    std::vector<std::unique_ptr<Block>> blocks;
    std::unique_ptr<Level> currLevel;
    bool gameOverSwitch;

    //for internal logic, makes code cleaner
    void removeRow();
    std::vector<std::pair<int,int>> getBoardPixels(int offBack);
    bool validMove(std::vector<std::pair<int,int>> pixels);

    public:
        Board(int seed, std::string scriptfile, int startLevel);
        void spawnBlock();
        void levelUp(int times);
        void levelDown(int times);
        void moveRight(int times);
        void moveLeft(int times);
        void moveDown(int times);
        void rotateCW(int times);
        void rotateCCW(int times);
        void drop();
        int getLevel();
        int getScore();
        std::vector<std::unique_ptr<Block>> &getBlocks();
        void checkGameOver(std::vector<std::pair<int,int>> pixels);
        bool gameOver();
};

#endif