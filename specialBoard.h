#include "board.h"
#include <memory>

class SpecialBoard:public Board {
    protected:
    std::unique_vector<Board> my_board;
    public:
    SpecialBoard(Board &&my_board);
    virtual ~SpecialBoard();
};