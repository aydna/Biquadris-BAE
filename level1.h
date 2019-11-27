//level1.h
#ifndef LEVEL1_H
#define LEVEL1_H

#include <string>
#include <memory>
#include "level.h"

class Block; //might give multiple declaration error

class Level1: public Level{
    public:
        Level1(int seed, std::string file, bool useRandom = true);
        ~Level1();

        std::unique_ptr<Block> spawnBlock() override;
        std::unique_ptr<Block> spawnBlock(std::string type) override;
};


#endif
