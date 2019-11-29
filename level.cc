#include <string>
#include <fstream>
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
Level::Level(int seed, std::string file, bool useRandom):
    seed{seed}, sequenceFileName{file}, useRandom{useRandom}, blockList{std::vector<std::string>{}}, blockListIndex{0} {
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


std::unique_ptr<Block> Level::spawnBlock() {
    std::string type;
    if (useRandom) {
        type = spawnRandom();
    } else {
        type = spawnNorandom();
    }

    if (type == "S") {
        return std::make_unique<BlockS>(1,0);

    } else if (type == "Z") {
        return std::make_unique<BlockZ>(1,0);

    } else if (type == "I") {
        return std::make_unique<BlockI>(1,0);

    } else if (type == "J") {
        return std::make_unique<BlockJ>(1,0);

    } else if (type == "L") {
        return std::make_unique<BlockL>(1,0);

    } else if (type == "T") {
        return std::make_unique<BlockT>(1,0);

    } else {
        return std::make_unique<BlockO>(1,0);
    }
}

std::string Level::spawnNorandom() {
    int len = blockList.size();
    if (blockListIndex >= len) {
        blockListIndex = 0;
    }
    ++blockListIndex;
    return blockList.at(blockListIndex);
}
