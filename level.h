#ifndef LEVEL_H
#define LEVEL_H
#include <memory>
class Block;

class Level{
    public:
        virtual std::unique_ptr<Block> spawnBlock()=0;
        virtual ~Level()=0;
};

#endif