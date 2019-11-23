#include <vector>
#include <memory>
#include "block.h"
#include "level.h"
#include "level_test.h"
#include "display.h"
#include "board.h"


Board::Board(int boardNum): 
    boardNum{boardNum}, 
    currLevel{std::make_unique<LevelTest>()}{} //change to Level0

std::vector<std::unique_ptr<Block>> &Board::getBlocks(){
    return blocks;
}

void Board::spawnBlock(){
    blocks.emplace_back(currLevel->spawnBlock());
}

void Board::moveLeft(){
    blocks.back()->moveLeft();
}

void Board::moveRight(){
    blocks.back()->moveRight();
}

void Board::drop(){
    blocks.back()->drop(10); // pass right collison param
}