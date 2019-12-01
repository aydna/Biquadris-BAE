#ifndef NORM_BOARD_H
#define NORM_BOARD_H
#include <vector>
#include <memory>
#include <utility>
#include <string>
#include "block.h"
#include "level.h"
#include "drawer.h"
#include "board.h"

class NormalBoard:public Board{
    int level;
    int seed;
    std::string file;
    int score;
    std::vector<std::unique_ptr<Block>> blocks;
    std::unique_ptr<Block> nextBlock;
    std::unique_ptr<Level> currLevel;
    bool gameOverSwitch;

    //for internal logic, makes code cleaner
    void removeRow();
    std::vector<std::pair<int,int>> getBoardPixels(int offBack);
    bool validMove(std::vector<std::pair<int,int>> pixels);

    public:
        virtual Board();
        Board(int seed, std::string scriptfile, int startLevel);
        void spawnBlock() override;
        void swapBlock(std::string type);
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
        std::unique_ptr<Block> &getNextBlock();
        std::unique_ptr<Board> &clearSpecial() override; //does nothing
        void checkGameOver(std::vector<std::pair<int,int>> pixels);
        bool gameOver();
};

#endif
