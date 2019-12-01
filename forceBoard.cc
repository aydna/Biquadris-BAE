#include "forceBoard.h"
#include <utility>
#include <memory>
#include <vector>
#include <string>

ForceBoard::ForceBoard(Board&& my_board) :
    SpecialBoard{my_board} {}


Board& ForceBoard::clearSpecial() {
    return my_board;
}
    
void ForceBoard::spawnBlock(std::string type) {
    my_board->swapBlock(type);
}