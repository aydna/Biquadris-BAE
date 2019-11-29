#ifndef LEVEL_H
#define LEVEL_H

#include <memory>
#include <string>
#include <vector>
#include <fstream>

//forward declarations
class Block;


class Level{
    protected:
        int seed;
        std::string sequenceFileName;
        bool useRandom;
        int levelNum;
        int levelWeight;

        std::ifstream fileStream;

        //std::vector<std::string> blockList;
        //int blockListIndex;

    public:
        Level(int seed, std::string file, bool useRandom, int levelNum, int levelWeight);
        
        virtual std::unique_ptr<Block> spawnBlock(std::string inBlock = "");
        virtual ~Level()=0;

        void giveLevelBlockSeq(std::string filename);
        void removeLevelBlockSeq();

    private:
        virtual std::string spawnRandom() = 0;
};


#endif