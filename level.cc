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
#include "block_branch.h"
#include "block_diag.h"
#include "block_dot.h"
#include "block_doughnut.h"
#include "block_rand.h"
#include "block_X.h"



//ctor
Level::Level(int seed, std::string file, bool useRandom, int levelNum, int levelWeight):
    seed{seed}, 
    sequenceFileName{file}, 
    useRandom{useRandom},
    levelNum{levelNum}, 
    levelWeight{levelWeight},
    fileStream{std::ifstream{sequenceFileName}} { //inits file streame to the file given
        srand(seed);
    }

//dtor
Level::~Level(){}

void Level::giveLevelBlockSeq(std::string filename) {
    useRandom = false;
    sequenceFileName = filename;
    fileStream = std::ifstream{sequenceFileName};  //reinits filesteam
}

void Level::removeLevelBlockSeq() {
    useRandom = true;
}

std::unique_ptr<Block> Level::spawnBlock(std::string inBlock) {
    std::string type;
    if (!useRandom){
        if (!(fileStream >> type)){ // if this read failes, this means that EOF
            fileStream = std::ifstream{sequenceFileName};   //reinit filestream
            fileStream >> type;
        }
    }
    else type = spawnRandom();

    if (inBlock.length() != 0) type = inBlock;

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

    } else if (type == "branch") {
        return std::make_unique<BlockBranch>(levelNum, levelWeight);

    } else if (type == "diag") {
        return std::make_unique<BlockDiag>(levelNum, levelWeight);

    } else if (type == "dot") {
        return std::make_unique<BlockDot>(levelNum, levelWeight);

    } else if (type == "doughnut") {
        return std::make_unique<BlockDoughnut>(levelNum, levelWeight);
    
    } else if (type == "X") {
        return std::make_unique<BlockX>(levelNum, levelWeight);

    } else {
        std::cerr << "Bad block type was read." << std::endl;
        return std::make_unique<BlockO>(levelNum,levelWeight);

    }
}
