#ifndef BLIND_BOARD
#define BLIND_BOARD

#include "specialBoard"
#include <string>

class BlindBoard:public SpecialBoard {
    public:
    BlindBoard(Board&& my_board);
    Board& clearSpecial() override;
    void spawnBlock(std::string type) override;
};

#endif
