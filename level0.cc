//level0.cc
#include "level0.h"
#include "block_O.h"
#include <memory>
#include <string>

Level0::Level0(std::string file, bool useRandom): 
        Level{file, useRandom} {}

Level0::~Level0() {}

// lol
std::unique_ptr<Block> Level0::spawnBlock() {
    return std::make_unique<BlockO>();
}

