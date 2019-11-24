#include <vector>
#include <memory>
#include <utility>
#include "block.h"
#include "level.h"
#include "level0.h"
#include "level1.h"
#include "display.h"
#include "board.h"

Board::Board(int boardNum): 
    boardNum{boardNum}, 
    currLevel{std::make_unique<Level1>()}{} //change to Level0

std::vector<std::unique_ptr<Block>> &Board::getBlocks(){
    return blocks;
}

void Board::spawnBlock(){
    blocks.emplace_back(currLevel->spawnBlock());
}

void Board::moveRight(int distance){ //think of a better way to do this, works for now
    std::vector<std::pair<int,int>> pixels = blocks.back()->getPixels();

    //gets a vector of all the pixels on the board except for the last one
    std::vector<std::pair<int,int>> boardPixels;
    for (auto b = blocks.begin(); b != blocks.end() - 1; ++b){
        std::vector<std::pair<int,int>> bp = (*b)->getPixels();
        for (auto p : bp){
            boardPixels.emplace_back(p);
        }
    }

    bool stop = false;
    for (int i = 0; i < distance; ++i){
        for (auto &p : pixels){ //moves right 1
            ++p.second;
        }
        for (auto &p : pixels){
            if(p.second >= 11){ //tests if out of range
                stop = true;
                break;
            }
            for (auto bp : boardPixels){  // tests if hits another block
                if((bp.first == p.first) && (bp.second == p.second))  stop = true;
            }
        }
        if (stop){
            for (auto &p : pixels){ // if out of range move back 1
                --p.second;
            }
            break;
        }
    }
    blocks.back()->setPixels(pixels);
}

void Board::moveLeft(int distance){
    std::vector<std::pair<int,int>> pixels = blocks.back()->getPixels();

    //gets a vector of all the pixels on the board except for the last one
    std::vector<std::pair<int,int>> boardPixels;
    for (auto b = blocks.begin(); b != blocks.end() - 1; ++b){
        std::vector<std::pair<int,int>> bp = (*b)->getPixels();
        for (auto p : bp){
            boardPixels.emplace_back(p);
        }
    }

    bool stop = false;
    for (int i = 0; i < distance; ++i){
        for (auto &p : pixels){
            --p.second;
        }
        for (auto &p : pixels){
            if(p.second < 0){
                stop = true;
                break;
            }
            for (auto bp : boardPixels){
                if((bp.first == p.first) && (bp.second == p.second))  stop = true;
            }
        }
        if (stop){
            for (auto &p : pixels){
                ++p.second;
            }
            break;
        }
    }
    blocks.back()->setPixels(pixels);
}

void Board::moveDown(int distance){
    std::vector<std::pair<int,int>> pixels = blocks.back()->getPixels();

    //gets a vector of all the pixels on the board except for the last one
    std::vector<std::pair<int,int>> boardPixels;
    for (auto b = blocks.begin(); b != blocks.end() - 1; ++b){
        std::vector<std::pair<int,int>> bp = (*b)->getPixels();
        for (auto p : bp){
            boardPixels.emplace_back(p);
        }
    }

    bool stop = false;
    for (int i = 0; i < distance; ++i){
        for (auto &p : pixels){
            ++p.first;
        }
        for (auto &p : pixels){
            if(p.first >= 18){
                stop = true;
                break;
            }
            for (auto bp : boardPixels){
                if((bp.first == p.first) && (bp.second == p.second))  stop = true;
            }
        }
        if (stop){
            for (auto &p : pixels){
                --p.first;
            }
            break;
        }
    }
    blocks.back()->setPixels(pixels);
}


void Board::rotateCW(int times){
    std::vector<std::pair<int,int>> pixels = blocks.back()->getPixels();

    //gets a vector of all the pixels on the board except for the last one
    std::vector<std::pair<int,int>> boardPixels;
    for (auto b = blocks.begin(); b != blocks.end() - 1; ++b){
        std::vector<std::pair<int,int>> bp = (*b)->getPixels();
        for (auto p : bp){
            boardPixels.emplace_back(p);
        }
    }

    bool stop = false;
    for (int i = 0; i < times; ++i){ //times mod 4?
        //rotation
        int rowMax = -1;
        int rowMin = 100;
        int colMax = -1;
        int colMin = 100;
        for (auto &p : pixels){
            if (p.first > rowMax) rowMax = p.first;
            if (p.first < rowMin) rowMin = p.first;
            if (p.second < colMin) colMin = p.second;
            if (p.second < colMin) colMin = p.second;
        }
        int height = 2;    //um idk
        int xoffset = rowMax - height;
        int yoffset = colMin;
        for (auto &p : pixels){ // (x,y) -> (y - yoffset + xoffset, height - x + xoffset + yoffset)
            int x = p.first;
            int y = p.second;
            p.first = y - yoffset + xoffset;
            p.second = height - x + xoffset + yoffset;
        }
        //fix offset
        int newRowMax = -1;
        for (auto &p : pixels){
            if (p.first > newRowMax) newRowMax = p.first;
        }
        for (auto &p : pixels){
            p.first += (rowMax - newRowMax);
        }
        //rotation end
    }

    for (auto &p : pixels){
        if((p.first < 0) || (p.first >= 18) || (p.second < 0) || (p.second >= 11)){
            stop = true;
            break;
        }
        for (auto bp : boardPixels){
            if((bp.first == p.first) && (bp.second == p.second))  stop = true;
        }
    }
    if (stop){
        return;
    }
    blocks.back()->setPixels(pixels);
}

bool Board::gameOver(){ return false; }

void Board::rotateCCW(int times){
    rotateCW(times * 3);
}


void Board::drop(){
    moveDown(20); // change this OMG its bad
}