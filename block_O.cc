#include "block_O.h"
#include <vector>
#include <utility>

BlockO::BlockO():
    Block{std::vector<std::pair<int,int>> {std::pair<int,int>(0,0), 
                                           std::pair<int,int>(0,1), 
                                           std::pair<int,int>(1,0), 
                                           std::pair<int,int>(1,1)}}{}