#include <vector>
#include <memory>
#include <utility>
#include <climits>
#include <string>
#include "block.h"
#include "level.h"
#include "level0.h"
#include "level1.h"
#include "drawer.h"
#include "board.h"

#include <iostream>

Board::Board(int seed, std::string scriptfile, int startLevel):
    level{startLevel},
    seed{seed},
    file{scriptfile}{
        if (level == 0) currLevel = std::make_unique<Level0>(seed, file);
        else if (level == 1) currLevel = std::make_unique<Level1>(seed, file);
    } 


std::vector<std::pair<int,int>> Board::getBoardPixels(int offBack){ //gets a vector of all the pixels on the board except for the last one
    std::vector<std::pair<int,int>> boardPixels;
    for (auto b = blocks.begin(); b != blocks.end() - offBack; ++b){
        std::vector<std::pair<int,int>> bp = (*b)->getPixels();
        for (auto p : bp){
            boardPixels.emplace_back(p);
        }
    }
    return boardPixels;
}

bool Board::validMove(std::vector<std::pair<int,int>> pixels){
    //gets a vector of all the pixels on the board except for the last one
    std::vector<std::pair<int,int>> boardPixels = getBoardPixels(1);
    for (auto p : pixels){
        if((p.first < 0) || (p.first >= 18) || (p.second < 0) || (p.second >= 11)) return false; //tests if  pixel out of range
        for (auto bp : boardPixels){  
            if((bp.first == p.first) && (bp.second == p.second))  return false; // tests if current pixel on another pixel
        }
    }
    return true;
}

void Board::removeRow(){
    int rowsCleared = 0;
    for(int row = 17; row > 3; --row){
        std::vector<std::pair<int,int>> boardPixels = getBoardPixels(0);
        int counter = 0;
        for (auto bp : boardPixels) if (bp.first == row) ++counter;
        if(counter == 0) break;             //if row is empty
        if (counter == 11){                 //if row is full
            auto b = blocks.begin();
            while (b != blocks.end()){
                std::vector<std::pair<int,int>> newPixels;
                for (auto p : (*b)->getPixels()){
                    if (p.first < row) newPixels.emplace_back(std::pair<int,int>{p.first + 1, p.second}); //if above row
                    else if (p.first > row) newPixels.emplace_back(p);                                    //if below row
                }
                if (newPixels.size() == 0){     //if block empty, remove it
                    score += ((*b)->getLevelSpawned() + 1) * ((*b)->getLevelSpawned() + 1);
                    b = blocks.erase(b);
                }
                else{
                    (*b)->setPixels(newPixels);
                    ++b;
                }
            }
            ++row;
            ++rowsCleared;
        }
    }
    if (rowsCleared > 0) score += (rowsCleared + level) * (rowsCleared + level);
}

void Board::spawnBlock(){
    blocks.emplace_back(currLevel->spawnBlock());
    checkGameOver(blocks.back()->getPixels());
}

void Board::levelUp(int times){
    level += times; 
    if (level > 4) level = 4;
    if (level == 0) currLevel = std::make_unique<Level0>(seed, file);
    else if (level == 1) currLevel = std::make_unique<Level1>(seed, file);
}

void Board::levelDown(int times){
    level -= times; 
    if (level < 0) level = 0;
    if (level == 0) currLevel = std::make_unique<Level0>(seed, file);
    else if (level == 1) currLevel = std::make_unique<Level1>(seed, file);
}


void Board::moveRight(int times){
    std::vector<std::pair<int,int>> pixels = blocks.back()->getPixels();
    for (int i = 0; i < times; ++i){
        std::vector<std::pair<int,int>> testPixels = pixels;
        for (auto &tp : testPixels) ++tp.second;    //moves testPixels 1 to the right
        if (!validMove(testPixels)) break;          //checks if it is a valid move
        for (auto &p : pixels) ++p.second;          //actually moves pixles 1 to the right
    }
    blocks.back()->setPixels(pixels);
}

void Board::moveLeft(int times){
    std::vector<std::pair<int,int>> pixels = blocks.back()->getPixels();
    for (int i = 0; i < times; ++i){
        std::vector<std::pair<int,int>> testPixels = pixels;
        for (auto &tp : testPixels) --tp.second;    //moves testPixels 1 to the left
        if (!validMove(testPixels)) break;          //checks if it is a valid move
        for (auto &p : pixels) --p.second;          //actually moves pixles 1 to the left
    }
    blocks.back()->setPixels(pixels);
}

void Board::moveDown(int times){
    std::vector<std::pair<int,int>> pixels = blocks.back()->getPixels();
    for (int i = 0; i < times; ++i){
        std::vector<std::pair<int,int>> testPixels = pixels;
        for (auto &tp : testPixels) ++tp.first;    //moves testPixels 1 to the down
        if (!validMove(testPixels)) break;          //checks if it is a valid move
        for (auto &p : pixels) ++p.first;          //actually moves pixles 1 to the down
    }
    blocks.back()->setPixels(pixels);
}


void Board::rotateCW(int times){
    std::vector<std::pair<int,int>> pixels = blocks.back()->getPixels();
    for (int i = 0; i < times % 4; ++i){
        //sets up cordinates for the rotation
        int rowMax = INT_MIN;
        int rowMin = INT_MAX;
        int colMax = INT_MIN;
        int colMin = INT_MAX;
        for (auto &p : pixels){
            if (p.first > rowMax) rowMax = p.first;
            if (p.first < rowMin) rowMin = p.first;
            if (p.second < colMin) colMin = p.second;
            if (p.second < colMin) colMin = p.second;
        }
        int height = ((rowMax - rowMin) > (colMax - colMin)) ? (rowMax - rowMin) :  (colMax - colMin);  //finds the "height" block
        int xoffset = rowMax - height;
        int yoffset = colMin;

        int newRowMax = INT_MIN;

        std::vector<std::pair<int,int>> testPixels = pixels;
        for (auto &tp : testPixels){   // (x,y) -> (y - yoffset + xoffset, height - x + xoffset + yoffset)
            int x = tp.first;
            int y = tp.second;
            tp.first = y - yoffset + xoffset;
            tp.second = height - x + xoffset + yoffset;         //rotates block cw 90degrees
            if (tp.first > newRowMax) newRowMax = tp.first;
        }
        for (auto &tp : testPixels){
            tp.first += (rowMax - newRowMax);       //fixes spacing
        }
        if (!validMove(testPixels)) break;          //checks if it is a valid move
        for (auto &p : pixels){
            int x = p.first;
            int y = p.second;
            p.first = y - yoffset + xoffset + (rowMax - newRowMax);
            p.second = height - x + xoffset + yoffset;
        }
    }
    blocks.back()->setPixels(pixels);
}


void Board::rotateCCW(int times){
    rotateCW((times % 4)* 3);       //works <3
}


void Board::drop(){
    moveDown(18); 
    removeRow();
}

int Board::getLevel(){ return level; }

int Board::getScore(){ return score; }

std::vector<std::unique_ptr<Block>> &Board::getBlocks(){ return blocks; }

void Board::checkGameOver(std::vector<std::pair<int,int>> pixels){
    std::vector<std::pair<int,int>> boardPixels = getBoardPixels(1);
    for (auto p : pixels){
        for (auto bp : boardPixels){
            if ((p.first == bp.first) && (p.second == bp.second)){
                gameOverSwitch = true;
                return;
            }
        } 
    }
}

bool Board::gameOver(){ return gameOverSwitch; }
