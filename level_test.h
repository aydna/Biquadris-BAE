#ifndef LEVELTEST_H
#define LEVELTEST_H
#include "level.h"
#include <memory>

class Block;

class LevelTest: public Level{
    public:
        ~LevelTest();
        virtual std::unique_ptr<Block> spawnBlock() override;
};

#endif