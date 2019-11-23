#include "level_test.h"
#include "block_O.h"
#include <memory>

LevelTest::~LevelTest(){}

std::unique_ptr<Block> LevelTest::spawnBlock(){
    return std::make_unique<BlockO>();
}
