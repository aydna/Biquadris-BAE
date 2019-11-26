#include "display.h"
#include "board.h"
#include "game.h"
#include <vector>
#include <utility>
#include <memory>
#include <iostream>


Display::Display(Game* game):my_game{game}{
    
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
    p2.grid = p1.grid;
}

void Display::updateDisplay() {

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


    //for p2 board
    std::unique_ptr<Board>& b2 = my_game->getBoard(2);
    std::vector<std::unique_ptr<Block>>& p2Blocks = b2->getBlocks();

    for (auto &b : p2Blocks) {
        char curr_color = b->getColor();
        for (auto p : b->getPixels()) {
            p2.grid[p.first][p.second] = curr_color;
        }
    }
    
}


std::ostream &operator <<(std::ostream &out, const Display &d) {
    out << std::endl << std::endl;
    out << " Level:    " << d.p1.level << "      "; // 6 spaces between the boards
    out << "Level:    " << d.p2.level << std::endl;
    out << " Score:    " << d.p1.level << "      ";
    out << "Score:    " << d.p2.level << std::endl;
    out << " -----------      -----------" << std::endl;

    for (int row = 0; row < d.p1.boardSize.first; row++) {
        out << "|";
        for (int col = 0; col < d.p1.boardSize.second; col++) {
            out << d.p1.grid[row][col];
        }
        out << "|    |";
        for (int col = 0; col < d.p2.boardSize.second; col++) {
            out << d.p2.grid[row][col];
        }
        out << "|";
        out << std::endl;
    }
    out << " -----------      -----------";
    //out << "Next:" for later impl
    return out;
}