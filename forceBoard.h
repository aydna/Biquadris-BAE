#ifndef FORCE_BOARD
#define FORCE_BOARD

#include "specialBoard"
#include <string>

class ForceBoard:public SpecialBoard {
    public:
    ForceBoard(Board&& my_board);
    Board& clearSpecial() override;
    void spawnBlock(std::string type) override;
};

#endif