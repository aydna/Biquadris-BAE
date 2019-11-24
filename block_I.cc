#include "block_I.h"
#include <vector>
#include <utility>

BlockI::BlockI():
    Block{std::vector<std::pair<int,int>> {std::pair<int,int>(3,0), 
                                           std::pair<int,int>(3,1), 
                                           std::pair<int,int>(3,2), 
                                           std::pair<int,int>(3,3)}, 'I'}{}