#include "block_doughnut.h"
#include <vector>
#include <utility>

BlockDoughnut::BlockDoughnut(int levelSpawned, int weight):
    Block{std::vector<std::pair<int,int>> {std::pair<int,int>(3,0),
                                           std::pair<int,int>(3,1),
                                           std::pair<int,int>(3,2),
                                           std::pair<int,int>(2,0),
                                           std::pair<int,int>(2,2),
                                           std::pair<int,int>(1,0),
                                           std::pair<int,int>(1,1),
                                           std::pair<int,int>(1,2)},
        '#',
        levelSpawned,
        weight}{}
