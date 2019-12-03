#include "block_rand.h"
#include <vector>
#include <utility>
#include <cstdlib>

BlockRand::BlockRand(int levelSpawned, int weight):
    Block{std::vector<std::pair<int,int>> {std::pair<int,int>(rand() % 4,rand() % 4), 
                                           std::pair<int,int>(rand() % 4,rand() % 4), 
                                           std::pair<int,int>(rand() % 4,rand() % 4), 
                                           std::pair<int,int>(rand() % 4,rand() % 4), 
                                           std::pair<int,int>(rand() % 4,rand() % 4), 
                                           std::pair<int,int>(rand() % 4,rand() % 4)},
        '#',
        levelSpawned,
        weight}{
        }
