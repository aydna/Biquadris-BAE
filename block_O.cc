#include "block_O.h"
#include <vector>
#include <utility>

BlockO::BlockO(int levelSpawned, int weight):
    Block{std::vector<std::pair<int,int>> {std::pair<int,int>(2,0), 
                                           std::pair<int,int>(2,1), 
                                           std::pair<int,int>(3,0), 
                                           std::pair<int,int>(3,1)},
        'O',
        levelSpawned,
        weight}{}
