#include <string>
#include <fstream>
#include <iostream>
#include "level.h"
#include "block_O.h"
#include "block_T.h"
#include "block_S.h"
#include "block_Z.h"
#include "block_J.h"
#include "block_L.h"
#include "block_I.h"


//pushing a sequencefile of blocks to a vector for sanity
void pushBlockList(std::string sequenceFileName, std::vector<std::string> &blockList) {
    std::ifstream pants{sequenceFileName};
    std::string in;
    while (pants >> in) {
        blockList.push_back(in);
    }
    pants.close();
}

//ctor
Level::Level(int seed, std::string file, bool useRandom, int levelNum, int levelWeight):
    seed{seed}, sequenceFileName{file}, useRandom{useRandom}, blockList{std::vector<std::string>{}}, blockListIndex{0},
    levelNum{levelNum}, levelWeight{levelWeight} {
    if (file != "") {
        pushBlockList(file, blockList);
    }
    srand(seed);
}
//dtor
Level::~Level(){}

void Level::giveLevelBlockSeq(std::string filename) {
    useRandom = false;
    sequenceFileName = filename;
    pushBlockList(filename, blockList);
    blockListIndex = 0;
}

void Level::removeLevelBlockSeq() {
    useRandom = true;
}


std::unique_ptr<Block> Level::spawnBlock(std::string inBlock) {
    std::string type;
    if (useRandom) {
        type = spawnRandom();
    } else {
        type = spawnNorandom();
    }
    if (inBlock.length() != 0) {
        type = inBlock;
    }
    std::cerr << type << std::endl;

    //block type processing
    if (type == "S") {
        return std::make_unique<BlockS>(levelNum,levelWeight);

    } else if (type == "Z") {
        return std::make_unique<BlockZ>(levelNum,levelWeight);

    } else if (type == "I") {
        return std::make_unique<BlockI>(levelNum,levelWeight);

    } else if (type == "J") {
        return std::make_unique<BlockJ>(levelNum,levelWeight);

    } else if (type == "L") {
        return std::make_unique<BlockL>(levelNum,levelWeight);

    } else if (type == "T") {
        return std::make_unique<BlockT>(levelNum,levelWeight);

    } else if (type == "O") {
        return std::make_unique<BlockO>(levelNum,levelWeight);
    } else {
        std::cerr << "Bad block type was read." << std::endl;
    }
}

//overloading spawnBlock() with a string input
/*std::unique_ptr<Block> Level::spawnBlock(std::string type){
    if (type == "I") {
        return std::make_unique<BlockI>(0,0);

    } else if (type == "J") {
        return std::make_unique<BlockJ>(0,0);

    } else if (type == "L") {
        return std::make_unique<BlockL>(0,0);

    } else if (type == "O") {
        return std::make_unique<BlockO>(0,0);

    } else if (type == "S") {
        return std::make_unique<BlockS>(0,0);

    } else if (type == "Z") {
        return std::make_unique<BlockZ>(0,0);

    } else {
        return std::make_unique<BlockT>(0,0);
    }
}
*/

std::string Level::spawnNorandom() {
    int len = blockList.size();
    if (blockListIndex >= len) {
        blockListIndex = 0;
    }
    std::cerr << blockListIndex << std::endl;
    ++blockListIndex;
    return blockList.at(blockListIndex);
}
