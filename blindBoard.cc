#include "blindBoard.h"
#include <utility>
#include <memory>
#include <vector>
#include <string>

BlindBoard::BlindBoard(Board&& my_board):
    SpecialBoard{my_board} {}

unique_ptr<Board>& BlindBoard::clearSpecial() {
    std::vector<std::unique_ptr<Block>>& currBlocks = my_board->getBlock();
    currBlocks.pop_back();
    return my_board;
}

void BlindBoard::spawnBlock(std::string type) {
    auto blindBoi = std::make_unique<BlockBlind>;
    my_board->getBlock().emplace_back(blindBoi);     
}