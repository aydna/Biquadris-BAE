#ifndef BOARD_UPSIDEDOWN_H
#define BOARD_UPSIDEDOWN_H

#include "board_special.h"
#include <string>

class BoardUpsidedown : public BoardSpecial {
    public:
        BoardUpsidedown(std::unique_ptr<Board>&& my_board);
        std::unique_ptr<Board>&& clearSpecial() override;
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
};

#endif