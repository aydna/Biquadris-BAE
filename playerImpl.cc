#include "drawer.h"
#include <utility>
#include <memory>

struct playerImpl{
    std::pair<int,int> boardSize;
    std::vector<std::vector<char>> oldGrid;
    std::vector<std::vector<char>> grid;
    int score;
    int level;
}