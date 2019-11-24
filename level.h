#ifndef LEVEL_H
#define LEVEL_H
#include <memory>
#include <string>
class Block;

class Level{
    protected:
        std::string sequenceFile;
        bool useRandom;
    
    public:
        Level(std::string file, bool useRandom);
        virtual std::unique_ptr<Block> spawnBlock()=0;
        virtual ~Level()=0;
};

#endif