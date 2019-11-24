#include "level0.h"
#include <memory>
#include <string>
#include <cstdlib>

#include "block_O.h"
#include "block_T.h"
#include "block_S.h"
#include "block_Z.h"
#include "block_J.h"
#include "block_L.h"
#include "block_I.h"


Level1::Level1(std::string file, bool useRandom): 
        Level{file, useRandom} {}

Level1::~Level1() {}



std::unique_ptr<Block> Level1::spawnBlock() {
    int gen = rand();
    if (gen < 1 * RAND_MAX / 12 {
        return std::make_unique<BlockS>();

    } else if (gen < 2 * RAND_MAX / 12 {
        return std::make_unique<BlockZ>();

    } else if (gen < 2 * RAND_MAX / 6 {
        return std::make_unique<BlockI>();

    } else if (gen < 3 * RAND_MAX / 6 {
        return std::make_unique<BlockJ>();

    } else if (gen < 4 * RAND_MAX / 6 {
        return std::make_unique<BlockL>();

    } else if (gen < 5 * RAND_MAX / 6 {
        return std::make_unique<BlockO>();

    } else {
        return std::make_unique<BlockT>();
    }
}