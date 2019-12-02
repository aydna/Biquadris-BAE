#include "board_special.h"
#include "board.h"
#include <memory>
#include <utility>

BoardSpecial::BoardSpecial(std::unique_ptr<Board>&& my_board):
    Board{}, my_board{std::move(my_board)} {}


