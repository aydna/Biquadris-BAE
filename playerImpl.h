#ifndef PLAYER_PIMPL
#define PLAYER_PIMPL
#include "drawer.h"
#include <utility>
#include <memory>

// pImpl idiom implementation

struct playerImpl{
    std::pair<int,int> boardSize;
    std::vector<std::vector<char>> oldGrid;
    std::vector<std::vector<char>> grid;
    std::vector<std::vector<char>> nextBlock;
    int score;
    int level;
};

#endif
