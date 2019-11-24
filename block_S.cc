#include "block_S.h"
#include <vector>
#include <utility>

BlockS::BlockS():
    Block{std::vector<std::pair<int,int>> {std::pair<int,int>(3,0), 
                                           std::pair<int,int>(3,1), 
                                           std::pair<int,int>(2,1), 
                                           std::pair<int,int>(2,2)}, 'S'}{}