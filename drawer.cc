#include "drawer.h"
#include "board.h"
#include "game.h"
#include <vector>
#include <utility>
#include <memory>
#include <iostream>

/*
ANDY READ ME

youre gonna make this faster for the graphics display,
store the "old" grid everytime you update the grid.
This old grid is gonna be used by the graphics to see what actually needs
to be redrawn

should be pretty easy to make <3 thanks
*/
Drawer::Drawer(Game* game):my_game{game}{
    
    p1.boardSize = std::pair<int,int>(18,11);
    p2.boardSize = std::pair<int,int>(18,11);

    p1.score = 0;
    p2.score = 0;

    p1.level = 0;
    p2.level = 0;

    for (int row = 0; row < p1.boardSize.first; row++) {
        std::vector<char> newRow;
        for (int col = 0; col < p1.boardSize.second; col++) {
            newRow.emplace_back(' ');
        }
        p1.grid.emplace_back(newRow);
    }
    //for now
    p2.oldGrid = p1.oldGrid = p2.grid = p1.grid;
}

void Drawer::updateDisplay() {
    //dont remove
    p1.oldGrid = p1.grid;
    p2.oldGrid = p2.grid;
    // clear board (for now)
    for (int row = 0; row < p1.boardSize.first; ++row){
        for (int col = 0; col < p1.boardSize.second; ++col){
            p1.grid[row][col] = '.';
            p2.grid[row][col] = '.';
        }
    }

    //for p1 board
    std::unique_ptr<Board>& b1 = my_game->getBoard(1);
    std::vector<std::unique_ptr<Block>>& p1Blocks = b1->getBlocks();

    for (auto &b : p1Blocks) {
        char curr_color = b->getColor();
        for (auto p : b->getPixels()) {
            p1.grid[p.first][p.second] = curr_color;
        }
    }
    p1.score = b1->getScore();
    p1.level = b1->getLevel();


    //for p2 board
    std::unique_ptr<Board>& b2 = my_game->getBoard(2);
    std::vector<std::unique_ptr<Block>>& p2Blocks = b2->getBlocks();

    for (auto &b : p2Blocks) {
        char curr_color = b->getColor();
        for (auto p : b->getPixels()) {
            p2.grid[p.first][p.second] = curr_color;
        }
    }
    p2.score = b2->getScore();
    p2.level = b2->getLevel();
    
}
