//level0.cc
#include "level0.h"
#include "block_O.h"
#include <memory>
#include <string>

Level0::Level0(int seed, std::string file, bool useRandom): 
        Level{seed, file, useRandom} {}

Level0::~Level0() {}

// lol
std::unique_ptr<Block> Level0::spawnBlock() {
    return std::make_unique<BlockO>(0,0);
}

