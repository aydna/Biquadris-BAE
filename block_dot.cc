#include "block_dot.h"
#include <vector>
#include <utility>

BlockDot::BlockDot(int levelSpawned, int weight):
    Block{std::vector<std::pair<int,int>> {std::pair<int,int>(3,5)},
        '*',
        levelSpawned,
        weight}{}
