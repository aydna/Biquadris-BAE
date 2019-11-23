#include "display.h"
#include <vector>
#include <memory>
#include <utility>
#include <iostream>

Display::Display() { //sets the right size for the 2d vector, fills with '-', change it spaces at the end?
    for (int row = 0; row < boardSize.first; ++row){
        std::vector<char> newRow;
        for (int col = 0; col < boardSize.second; ++col){
            newRow.emplace_back('-');
        }
        grid1.emplace_back(newRow);
    }
    for (int row = 0; row < boardSize.first; ++row){
        std::vector<char> newRow;
        for (int col = 0; col < boardSize.second; ++col){
            newRow.emplace_back('-');
        }
        grid2.emplace_back(newRow);
    }
}

void Display::update(const std::vector<std::unique_ptr<Block>> &blocks1, const std::vector<std::unique_ptr<Block>> &blocks2) {
    // clear board
    for (int row = 0; row < boardSize.first; ++row){
        for (int col = 0; col < boardSize.second; ++col){
            grid1[row][col] = '-';
            grid2[row][col] = '-';
        }
    }
    // fills with blocks 
    for (auto const& b : blocks1){
        for (auto p : b->pixels){
            grid1[p.first][p.second] = 'O'; //blocks will have a Char class to be added
        }
    }
    for (auto const& b : blocks2){
        for (auto p : b->pixels){
            grid2[p.first][p.second] = 'O';
        }
    }
}


std::ostream &operator <<(std::ostream &out , const Display &d){
    for (int row = 0; row < d.boardSize.first; ++row){ 
        for (int col = 0; col < d.boardSize.second; ++col){
            out << d.grid1[row][col];
        }
        out << "     ";
        for (int col = 0; col < d.boardSize.second; ++col){
            out << d.grid2[row][col];
        }
        out << std::endl;
    }
    return out;
}