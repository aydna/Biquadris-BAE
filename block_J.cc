#include "block_J.h"
#include <vector>
#include <utility>

BlockJ::BlockJ(int levelSpawned, int weight):
    Block{std::vector<std::pair<int,int>> {std::pair<int,int>(3,0), 
                                           std::pair<int,int>(3,1), 
                                           std::pair<int,int>(3,2), 
                                           std::pair<int,int>(2,0)},
        'J',
        levelSpawned,
        weight}{}
