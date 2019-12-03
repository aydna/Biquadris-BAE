#include "board_upsidedown.h"
#include "level.h"
#include <utility>
#include <memory>
#include <vector>
#include <string>

BoardUpsidedown::BoardUpsidedown(std::unique_ptr<Board>&& my_board) :
    BoardSpecial{std::move(my_board)} {}

std::unique_ptr<Board>&& BoardUpsidedown::clearSpecial() { return std::move(my_board); }
    
void BoardUpsidedown::spawnBlock(std::string type, int weight) { my_board->spawnBlock(type,weight);  }
void BoardUpsidedown::swapBlock(std::string type, int weight) { my_board->swapBlock(type,weight); }

void BoardUpsidedown::levelUp(int times) { my_board->levelUp(times); }
void BoardUpsidedown::levelDown(int times) { my_board->levelDown(times); }
void BoardUpsidedown::moveRight(int times) { my_board->moveRight(times); }
void BoardUpsidedown::moveLeft(int times) { my_board->moveLeft(times); }
void BoardUpsidedown::moveDown(int times) { my_board->moveDown(times); }
void BoardUpsidedown::rotateCW(int times) { my_board->rotateCW(times); }
void BoardUpsidedown::rotateCCW(int times) { my_board->rotateCCW(times); } 
int BoardUpsidedown::drop() { return my_board->drop(); }
int BoardUpsidedown::getLevel() { return my_board->getLevel(); }
int BoardUpsidedown::getScore() { return my_board->getScore(); }
std::vector<BoardPixels> BoardUpsidedown::getBlocks() { //flips the screen upside down
    std::vector<BoardPixels> bp = my_board->getBlocks();
    std::vector<BoardPixels> np;
    for (auto p : bp){
        np.emplace_back(BoardPixels{std::pair<int,int>(18 - p.cord.first - 1, p.cord.second),p.color});
    }
    return np;
 }
std::vector<BoardPixels> BoardUpsidedown::getNextBlock() { return my_board->getNextBlock(); }
void BoardUpsidedown::checkGameOver(std::vector<std::pair<int,int>> pixels) { return my_board->checkGameOver(pixels); }
bool BoardUpsidedown::gameOver() { return my_board->gameOver(); }
void BoardUpsidedown::giveLevelBlockSeq(std::string filename) { my_board->giveLevelBlockSeq(filename); }
void BoardUpsidedown::removeLevelBlockSeq() { my_board->removeLevelBlockSeq(); }