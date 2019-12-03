#include "board_force.h"
#include <utility>
#include <memory>
#include <vector>
#include <string>

BoardForce::BoardForce(std::unique_ptr<Board>&& my_board) :
    BoardSpecial{std::move(my_board)} {}


std::unique_ptr<Board>&& BoardForce::clearSpecial() { return std::move(my_board); }

void BoardForce::spawnBlock(std::string type, int weight)  { //swaps the current block to a new type of block
    my_board->spawnBlock(type,weight);
    my_board->swapBlock(type,weight);
}
void BoardForce::swapBlock(std::string type, int weight) { my_board->swapBlock(type, weight); }

void BoardForce::levelUp(int times) { my_board->levelUp(times); }
void BoardForce::levelDown(int times) { my_board->levelDown(times); }
void BoardForce::moveRight(int times) { my_board->moveRight(times); }
void BoardForce::moveLeft(int times) { my_board->moveLeft(times); }
void BoardForce::moveDown(int times) { my_board->moveDown(times); }
void BoardForce::rotateCW(int times) { my_board->rotateCW(times); }
void BoardForce::rotateCCW(int times) { my_board->rotateCCW(times); }
int BoardForce::drop() { return my_board->drop(); }
int BoardForce::getLevel() { return my_board->getLevel(); }
int BoardForce::getScore() { return my_board->getScore(); }
std::vector<BoardPixels> BoardForce::getBlocks() { return my_board->getBlocks(); }
std::vector<BoardPixels> BoardForce::getNextBlock() { return my_board->getNextBlock(); }
void BoardForce::checkGameOver(std::vector<std::pair<int,int>> pixels) { return my_board->checkGameOver(pixels); }
bool BoardForce::gameOver() { return my_board->gameOver(); }
void BoardForce::giveLevelBlockSeq(std::string filename) { my_board->giveLevelBlockSeq(filename); }
void BoardForce::removeLevelBlockSeq() { my_board->removeLevelBlockSeq(); }
