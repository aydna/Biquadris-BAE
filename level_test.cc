#include "level_test.h"
#include "block_I.h"
#include "block_J.h"
#include "block_L.h"
#include "block_O.h"
#include "block_S.h"
#include "block_Z.h"
#include "block_T.h"
#include <memory>
#include <cstdlib>

LevelTest::~LevelTest(){}

std::unique_ptr<Block> LevelTest::spawnBlock(){
    int num = rand() % 7;
    if (num == 0){
        return std::make_unique<BlockI>();
    }
    else if (num == 1){
        return std::make_unique<BlockJ>();
    }
    else if (num == 2){
        return std::make_unique<BlockL>();
    }
    else if (num == 3){
        return std::make_unique<BlockO>();
    }
    else if (num == 4){
        return std::make_unique<BlockS>();
    }
    else if (num == 5){
        return std::make_unique<BlockZ>();
    }
    else if (num == 6){
        return std::make_unique<BlockT>();
    }
}
