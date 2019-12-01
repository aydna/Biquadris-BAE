#include "drawer.h"
#include "board.h"
#include "game.h"
//#include "playerImpl.h"
#include <vector>
#include <utility>
#include <memory>
#include <iostream>

Drawer::Drawer(Game* game):
    my_game{game},
    p1{std::make_unique<playerImpl>()},
    p2{std::make_unique<playerImpl>()}{    
    p1->boardSize = std::pair<int,int>(18,11);
    p2->boardSize = std::pair<int,int>(18,11);

    p1->score = 0;
    p2->score = 0;

    p1->level = 0;
    p2->level = 0;

    for (int row = 0; row < p1->boardSize.first; row++) {
        std::vector<char> newRow;
        for (int col = 0; col < p1->boardSize.second; col++) {
            newRow.emplace_back(' ');
        }
        p1->grid.emplace_back(newRow);
    }

    for (int row = 0; row < 4; row++) {
        std::vector<char> newRow;
        for (int col = 0; col < 4; col++) {
            newRow.emplace_back(' ');
        }
        p1->nextBlock.emplace_back(newRow);
    }
    //for now
    p2->oldGrid = p1->oldGrid = p2->grid = p1->grid;
    p2->nextBlock = p1->nextBlock;
}



void Drawer::updateDisplay() {
    //dont remove
    p1->oldGrid = p1->grid;
    p2->oldGrid = p2->grid;
    // clear board (for now)
    for (int row = 0; row < p1->boardSize.first; ++row){
        for (int col = 0; col < p1->boardSize.second; ++col){
            p1->grid[row][col] = ' ';
            p2->grid[row][col] = ' ';
        }
    }

    for (int row = 0; row < 4; ++row){
        for (int col = 0; col < 4; ++col){
            p1->nextBlock[row][col] = ' ';
            p2->nextBlock[row][col] = ' ';
        }
    }
    
    //for p1 board
    std::unique_ptr<Board>& b1 = my_game->getBoard(1);
    std::vector<BoardPixels> p1Blocks = b1->getBlocks();
    //board
    for (auto b : p1Blocks) {
        p1->grid[b.cord.first][b.cord.second] = b.color;
    }
    //nextBlock
    std::vector<BoardPixels> nb1 = b1->getNextBlock();
    for (auto b : nb1) {
        p1->nextBlock[b.cord.first][b.cord.second] = b.color;
    }

    p1->score = b1->getScore();
    p1->level = b1->getLevel();


    //for p2 board
    std::unique_ptr<Board>& b2 = my_game->getBoard(2);
    std::vector<BoardPixels> p2Blocks = b2->getBlocks();

    for (auto b : p2Blocks) {
        p2->grid[b.cord.first][b.cord.second] = b.color;
    }

    std::vector<BoardPixels> nb2 = b2->getNextBlock();
    for (auto b : nb2) {
        p2->nextBlock[b.cord.first][b.cord.second] = b.color;
    }

    p2->score = b2->getScore();
    p2->level = b2->getLevel();
}

Drawer::~Drawer(){}