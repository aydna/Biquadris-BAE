#include "block_blind.h"
#include <vector>
#include <utility>

BlockBlind::BlockBlind():
    Block{std::vector<std::pair<int,int>>} { 
        
        for (int row = 3; row <= 12; row++) {
            for (int col = 3; col <= 9; col++) {
                Block.emplace_back(std::pair<int,int>(row,col));
            }
        }
        
        
        }