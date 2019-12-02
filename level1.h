#ifndef LEVEL1_H
#define LEVEL1_H

#include <string>
#include "level.h"

class Block; //might give multiple declaration error

class Level1: public Level{
    public:
        Level1(int seed = 0, std::string file = "", bool useRandom = true);
        ~Level1();

        std::string spawnRandom() override;
};


#endif
