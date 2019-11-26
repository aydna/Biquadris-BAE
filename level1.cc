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


Level1::Level1(int seed, std::string file, bool useRandom): 
        Level{seed, file, useRandom} {}

Level1::~Level1() {}



std::unique_ptr<Block> Level1::spawnBlock() {
    int gen = rand() % 12;
    if (gen < 1) {
        return std::make_unique<BlockS>(1,0);

    } else if (gen < 2) {
        return std::make_unique<BlockZ>(1,0);

    } else if (gen < 4) {
        return std::make_unique<BlockI>(1,0);

    } else if (gen < 6) {
        return std::make_unique<BlockJ>(1,0);

    } else if (gen < 8) {
        return std::make_unique<BlockL>(1,0);

    } else if (gen < 10) {
        return std::make_unique<BlockO>(1,0);

    } else {
        return std::make_unique<BlockT>(1,0);
    }
}
