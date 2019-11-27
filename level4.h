#ifndef LEVEL4_H
#define LEVEL4_H

#include <string>
#include "level.h"

class Block; //might give multiple declaration error

class Level4: public Level{
    public:
        Level4(int seed = 0, std::string file = "", bool useRandom = true);
        ~Level4();

        virtual std::string spawnRandom() override;
};


#endif
