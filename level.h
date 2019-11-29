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
        int levelNum;
        int levelWeight;
    
    public:
        Level(int seed, std::string file, bool useRandom, int levelNum, int levelWeight);
        //virtual std::unique_ptr<Block> spawnBlock()=0;
        virtual std::unique_ptr<Block> spawnBlock(std::string inBlock = "");
        virtual ~Level()=0;

        void giveLevelBlockSeq(std::string filename);
        void removeLevelBlockSeq();

    private:
        virtual std::string spawnRandom() = 0;
    protected:
        std::string spawnNorandom();
        
};


#endif