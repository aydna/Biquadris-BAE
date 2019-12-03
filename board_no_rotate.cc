#include "board_no_rotate.h"
#include "level.h"
#include <utility>
#include <memory>
#include <vector>
#include <string>

BoardNoRotate::BoardNoRotate(std::unique_ptr<Board>&& my_board) :
    BoardSpecial{std::move(my_board)} {}

std::unique_ptr<Board>&& BoardNoRotate::clearSpecial() { return std::move(my_board); }
    
void BoardNoRotate::spawnBlock(std::string type, int weight) { my_board->spawnBlock(type,weight);  }
void BoardNoRotate::swapBlock(std::string type, int weight) { my_board->swapBlock(type,weight); }

void BoardNoRotate::levelUp(int times) { my_board->levelUp(times); }
void BoardNoRotate::levelDown(int times) { my_board->levelDown(times); }
void BoardNoRotate::moveRight(int times) { my_board->moveRight(times); }
void BoardNoRotate::moveLeft(int times) { my_board->moveLeft(times); }
void BoardNoRotate::moveDown(int times) { my_board->moveDown(times); }
void BoardNoRotate::rotateCW(int times) {} //this do nothing on this board
void BoardNoRotate::rotateCCW(int times) {} //this do nothing on this board
int BoardNoRotate::drop() { return my_board->drop(); }
int BoardNoRotate::getLevel() { return my_board->getLevel(); }
int BoardNoRotate::getScore() { return my_board->getScore(); }
std::vector<BoardPixels> BoardNoRotate::getBlocks() { return my_board->getBlocks(); }
std::vector<BoardPixels> BoardNoRotate::getNextBlock() { return my_board->getNextBlock(); }
void BoardNoRotate::checkGameOver(std::vector<std::pair<int,int>> pixels) { return my_board->checkGameOver(pixels); }
bool BoardNoRotate::gameOver() { return my_board->gameOver(); }
void BoardNoRotate::giveLevelBlockSeq(std::string filename) { my_board->giveLevelBlockSeq(filename); }
void BoardNoRotate::removeLevelBlockSeq() { my_board->removeLevelBlockSeq(); }