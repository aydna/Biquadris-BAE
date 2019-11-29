#include "block_diag.h"
#include <vector>
#include <utility>

BlockDiag::BlockDiag(int levelSpawned, int weight):
    Block{std::vector<std::pair<int,int>> {std::pair<int,int>(3,0),
                                           std::pair<int,int>(2,1),
                                           std::pair<int,int>(1,2)},
        '#',
        levelSpawned,
        weight}{}