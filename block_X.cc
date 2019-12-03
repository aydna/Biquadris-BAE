#include "block_X.h"
#include <vector>
#include <utility>

BlockX::BlockX(int levelSpawned, int weight):
    Block{std::vector<std::pair<int,int>> {std::pair<int,int>(0,0), 
                                           std::pair<int,int>(1,1), 
                                           std::pair<int,int>(2,2), 
                                           std::pair<int,int>(3,3),
                                           std::pair<int,int>(0,3), 
                                           std::pair<int,int>(1,2), 
                                           std::pair<int,int>(2,1),
                                           std::pair<int,int>(3,0)},
        '#',
        levelSpawned,
        weight}{}
