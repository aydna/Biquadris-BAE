#ifndef LEVEL0_H
#define LEVEL0_H

#include <string>
#include <memory>
#include "level.h"

class Block; //might give multiple declaration error

class Level0: public Level{
    public:
        Level0(std::string file = "sequence1.txt", bool useRandom = false);
        ~Level0();

        virtual std::unique_ptr<Block> spawnBlock() override;
};


#endif