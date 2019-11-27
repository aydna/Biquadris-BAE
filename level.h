#ifndef LEVEL_H
#define LEVEL_H

#include <memory>
#include <string>
#include <vector>

//forward declarations
class Block;


class Level{
    protected:
        int seed;
        std::string sequenceFileName;
        bool useRandom;
        std::vector<std::string> blockList;
        int blockListIndex;
    
    public:
        Level(int seed, std::string filename, bool useRandom);
        virtual ~Level()=0;

        std::unique_ptr<Block> spawnBlock();
        void giveLevelBlockSeq(std::string filename);
        void removeLevelBlockSeq();

    private:
        virtual std::string spawnRandom() = 0;
    protected:
        std::string spawnNorandom();
        
};


#endif