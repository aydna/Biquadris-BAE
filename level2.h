#ifndef LEVEL2_H
#define LEVEL2_H

#include <string>
#include "level.h"

class Block; //might give multiple declaration error

class Level2: public Level{
    public:
        Level2(int seed = 0, std::string file = "", bool useRandom = true);
        ~Level2();

        std::string spawnRandom() override;
};


#endif
