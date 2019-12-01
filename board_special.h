#ifndef BOARD_SPECIAL_H
#define BOARD_SPECIAL_H

#include "board.h"
#include <memory>

class BoardSpecial:public Board {
    protected:
        std::unique_ptr<Board> my_board;
    public:
        BoardSpecial(std::unique_ptr<Board>&& my_board);
        virtual std::unique_ptr<Board>&& clearSpecial()=0;
};

#endif
