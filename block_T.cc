#include "block_T.h"
#include <vector>
#include <utility>

BlockT::BlockT(int levelSpawned, int weight):
    Block{std::vector<std::pair<int,int>> {std::pair<int,int>(2,0), 
                                           std::pair<int,int>(2,1), 
                                           std::pair<int,int>(2,2), 
                                           std::pair<int,int>(3,1)},
        'T',
        levelSpawned,
        weight}{}
