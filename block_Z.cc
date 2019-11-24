#include "block_Z.h"
#include <vector>
#include <utility>

BlockZ::BlockZ():
    Block{std::vector<std::pair<int,int>> {std::pair<int,int>(3,0), 
                                           std::pair<int,int>(2,1), 
                                           std::pair<int,int>(3,0), 
                                           std::pair<int,int>(2,1)}, 'Z'}{}