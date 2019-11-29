#ifndef LEVEL3_H
#define LEVEL3_H

#include <string>
#include "level.h"

class Block; //might give multiple declaration error

class Level3: public Level{
    public:
        Level3(int seed = 0, std::string file = "", bool useRandom = true);
        ~Level3();

        std::string spawnRandom() override;
};


#endif
