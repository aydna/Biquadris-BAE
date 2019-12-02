//level0.h
#ifndef LEVEL0_H
#define LEVEL0_H

#include <string>
#include "level.h"

class Block; 

class Level0: public Level{
    public:
        Level0(int seed, std::string file, bool useRandom = false);
        ~Level0();

        std::string spawnRandom() override;
};


#endif
