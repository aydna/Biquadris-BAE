#include "heavyBoard.h"
#include <utility>
#include <memory>
#include <vector>
#include <string>

ForceBoard::HeavyBoard(Board&& my_board) :
    SpecialBoard{my_board} {}


Board& ForceBoard::clearSpecial() {
    remove_heaviness();
    return my_board;
}
    
void ForceBoard::spawnBlock(std::string type) {
    add_heaviness();
}