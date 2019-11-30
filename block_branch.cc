#include "block_branch.h"
#include <vector>
#include <utility>

BlockBranch::BlockBranch(int levelSpawned, int weight):
    Block{std::vector<std::pair<int,int>> {std::pair<int,int>(3,0), 
                                           std::pair<int,int>(2,0), 
                                           std::pair<int,int>(2,1), 
                                           std::pair<int,int>(2,2),
                                           std::pair<int,int>(2,3),
                                           std::pair<int,int>(1,1),
                                           std::pair<int,int>(0,1)},
        '#',
        levelSpawned,
        weight}{}