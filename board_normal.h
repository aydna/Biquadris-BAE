#ifndef BOARD_NORMAL_H
#define BOARD_NORMAL_H
#include <vector>
#include <memory>
#include <utility>
#include "board.h"
#include "level.h"

class BoardNormal:public Board{
    private:
    int level;
    int seed;
    std::string file;
    int score;
    std::vector<std::unique_ptr<Block>> blocks;
    std::unique_ptr<Block> nextBlock;
    std::unique_ptr<Level> currLevel;
    bool gameOverSwitch;
    int roundsSinceClear = 0;

    int removeRow();
    std::vector<std::pair<int,int>> getBoardPixels(int offBack);
    bool validMove(std::vector<std::pair<int,int>> pixels);

    public:
        BoardNormal(int seed, std::string scriptfile, int startLevel);
        void spawnBlock(std::string type = "", int weight = 0) override;
        void swapBlock(std::string type, int weight = 0) override;
        void levelUp(int times) override;
        void levelDown(int times) override;
        void moveRight(int times) override;
        void moveLeft(int times) override;
        void moveDown(int times) override;
        void rotateCW(int times) override;
        void rotateCCW(int times) override;
        int drop() override;
        int getLevel() override;
        int getScore() override;
        std::vector<BoardPixels> getBlocks() override;
        std::vector<BoardPixels> getNextBlock() override;
        void checkGameOver(std::vector<std::pair<int,int>> pixels) override;
        bool gameOver() override;
        void giveLevelBlockSeq(std::string filename) override;
        void removeLevelBlockSeq() override;
        
        std::unique_ptr<Board>&& clearSpecial() override;
};

#endif
