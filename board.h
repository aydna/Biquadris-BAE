#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <memory>
#include <utility>
#include <string>
#include "block.h"

struct BoardPixels{
    std::pair<int,int> cord;
    char color;
};

class Board{
    
    public:
        Board();
        virtual void spawnBlock(std::string type = "", int weight = 0)=0;
        virtual void swapBlock(std::string type, int weight = 0)=0;
        virtual void levelUp(int times)=0;
        virtual void levelDown(int times)=0;
        virtual void moveRight(int times)=0;
        virtual void moveLeft(int times)=0;
        virtual void moveDown(int times)=0;
        virtual void rotateCW(int times)=0;
        virtual void rotateCCW(int times)=0;
        virtual int drop()=0;
        virtual int getLevel()=0;
        virtual int getScore()=0;
        virtual std::vector<BoardPixels> getBlocks()=0;
        virtual std::vector<BoardPixels> getNextBlock()=0;
        virtual void checkGameOver(std::vector<std::pair<int,int>> pixels)=0;
        virtual bool gameOver()=0;
        virtual void giveLevelBlockSeq(std::string filename)=0;
        virtual void removeLevelBlockSeq()=0;

        virtual std::unique_ptr<Board>&& clearSpecial()=0;
};

#endif
