#include "board_heavy.h"
#include "level.h"
#include <utility>
#include <memory>
#include <vector>
#include <string>

BoardHeavy::BoardHeavy(std::unique_ptr<Board>&& my_board) :
    BoardSpecial{std::move(my_board)} {}

std::unique_ptr<Board>&& BoardHeavy::clearSpecial() { return std::move(my_board); }
    
void BoardHeavy::spawnBlock(std::string type, int weight) { my_board->spawnBlock(type,2+weight); } //adds 2 to the block's weight
void BoardHeavy::swapBlock(std::string type, int weight) { my_board->swapBlock(type,weight); }

void BoardHeavy::levelUp(int times) { my_board->levelUp(times); }
void BoardHeavy::levelDown(int times) { my_board->levelDown(times); }
void BoardHeavy::moveRight(int times) { my_board->moveRight(times); }
void BoardHeavy::moveLeft(int times) { my_board->moveLeft(times); }
void BoardHeavy::moveDown(int times) { my_board->moveDown(times); }
void BoardHeavy::rotateCW(int times) { my_board->rotateCW(times); }
void BoardHeavy::rotateCCW(int times) { my_board->rotateCCW(times); }
int BoardHeavy::drop() { return my_board->drop(); }
int BoardHeavy::getLevel() { return my_board->getLevel(); }
int BoardHeavy::getScore() { return my_board->getScore(); }
std::vector<BoardPixels> BoardHeavy::getBlocks() { return my_board->getBlocks(); }
std::vector<BoardPixels> BoardHeavy::getNextBlock() { return my_board->getNextBlock(); }
void BoardHeavy::checkGameOver(std::vector<std::pair<int,int>> pixels) { return my_board->checkGameOver(pixels); }
bool BoardHeavy::gameOver() { return my_board->gameOver(); }
void BoardHeavy::giveLevelBlockSeq(std::string filename) { my_board->giveLevelBlockSeq(filename); }
void BoardHeavy::removeLevelBlockSeq() { my_board->removeLevelBlockSeq(); }
