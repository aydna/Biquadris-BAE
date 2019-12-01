#ifndef LEVEL5_H
#define LEVEL5_H

#include <string>
#include "level.h"

class Block; //might give multiple declaration error

class Level5: public Level{
    public:
        Level5(int seed = 0, std::string file = "", bool useRandom = true);
        ~Level5();

        std::string spawnRandom() override;
};


#endif
