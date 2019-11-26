#ifndef LEVEL_H
#define LEVEL_H

#include <memory>
#include <string>

//forward declarations
class Block;


class Level{
    protected:
        int seed;
        std::string sequenceFile;
        bool useRandom;
    
    public:
        Level(int seed, std::string file, bool useRandom);
        virtual ~Level()=0;

        virtual std::unique_ptr<Block> spawnBlock() = 0;
        virtual void giveLevelBlockSeq(std::string filename) = 0;
        virtual void removeLevelBlockSeq() = 0;
        
};


#endif