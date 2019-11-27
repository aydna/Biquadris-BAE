//level0.cc
#include "level0.h"
#include <memory>
#include <string>

#include "block_O.h"
#include "block_T.h"
#include "block_S.h"
#include "block_Z.h"
#include "block_J.h"
#include "block_L.h"
#include "block_I.h"

Level0::Level0(int seed, std::string file, bool useRandom): 
        Level{seed, file, useRandom} {}

Level0::~Level0() {}

// lol
std::unique_ptr<Block> Level0::spawnBlock() {
    return std::make_unique<BlockO>(0,0);
}

std::unique_ptr<Block> Level0::spawnBlock(std::string type){
    if (type == "I") {
        return std::make_unique<BlockI>(1,0);

    } else if (type == "J") {
        return std::make_unique<BlockJ>(1,0);

    } else if (type == "L") {
        return std::make_unique<BlockL>(1,0);

    } else if (type == "O") {
        return std::make_unique<BlockO>(1,0);

    } else if (type == "S") {
        return std::make_unique<BlockS>(1,0);

    } else if (type == "Z") {
        return std::make_unique<BlockZ>(1,0);

    } else {
        return std::make_unique<BlockT>(1,0);
    }
}