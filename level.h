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
        std::string sequenceFileName;   // file representing the sequence of blocks to be spawned by norandom
        bool useRandom;                 // true is we want to use random generation, false otherwise
        int levelNum;                   // stores the level number for clarity
        int levelWeight;                // the weight associated with blocks in this level

        std::ifstream fileStream;       // tool to read from sequenceFileName

    public:
        Level(int seed, std::string file, bool useRandom, int levelNum, int levelWeight);
        
        // spawnBlock(string) spawns the specified block type, or follows normal generation if nothing is passed
        std::unique_ptr<Block> spawnBlock(std::string inBlock = "");
        std::string spawnNorandom();
        virtual ~Level()=0;

        // giveLevelBlockSeq(filename) tells the Level to generate blocks from a file, not randomly
        void giveLevelBlockSeq(std::string filename);
        // removeLevelBlockSeq(filename) tells the Level to generate blocks randomly, not from a file
        void removeLevelBlockSeq();

    private:
        //spawnRandom() generates a block from random numbers (probabilites vary between different levels)
        virtual std::string spawnRandom() = 0;
};


#endif