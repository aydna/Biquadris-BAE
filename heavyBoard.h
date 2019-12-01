#ifndef HEAVY_BOARD
#define HEAVY_BOARD

#include "specialBoard"
#include <string>

class HeavyBoard:public SpecialBoard {
    public:
    HeavyBoard(Board&& my_board);
    Board& clearSpecial() override;
    void spawnBlock(std::string type) override;
};

#endif