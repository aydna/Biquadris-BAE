#include "board_blind.h"
#include <utility>
#include <memory>
#include <vector>
#include <string>

BoardBlind::BoardBlind(std::unique_ptr<Board>&& my_board):
    BoardSpecial{std::move(my_board)} {}

std::unique_ptr<Board>&& BoardBlind::clearSpecial() { return std::move(my_board); }
    
void BoardBlind::spawnBlock(std::string type, int weight) { my_board->spawnBlock(type,weight); }
void BoardBlind::swapBlock(std::string type, int weight) { my_board->swapBlock(type,weight); }

void BoardBlind::levelUp(int times) { my_board->levelUp(times); }
void BoardBlind::levelDown(int times) { my_board->levelDown(times); }
void BoardBlind::moveRight(int times) { my_board->moveRight(times); }
void BoardBlind::moveLeft(int times) { my_board->moveLeft(times); }
void BoardBlind::moveDown(int times) { my_board->moveDown(times); }
void BoardBlind::rotateCW(int times) { my_board->rotateCW(times); }
void BoardBlind::rotateCCW(int times) { my_board->rotateCCW(times); }
int BoardBlind::drop() { return my_board->drop(); }
int BoardBlind::getLevel() { return my_board->getLevel(); }
int BoardBlind::getScore() { return my_board->getScore(); }
//adds some ? to the board
std::vector<BoardPixels> BoardBlind::getBlocks() { 
    std::vector<BoardPixels> bp = my_board->getBlocks();
    for (int row = 4; row <= 15; ++row){
        for (int col = 2; col <= 8; ++col){
            bp.emplace_back(BoardPixels{std::pair<int,int>(row,col),'?'});
        }
    }
    return bp;
}
std::vector<BoardPixels> BoardBlind::getNextBlock() { return my_board->getNextBlock(); }
void BoardBlind::checkGameOver(std::vector<std::pair<int,int>> pixels) { return my_board->checkGameOver(pixels); }
bool BoardBlind::gameOver() { return my_board->gameOver(); }
void BoardBlind::giveLevelBlockSeq(std::string filename) { my_board->giveLevelBlockSeq(filename); }
void BoardBlind::removeLevelBlockSeq() { my_board->removeLevelBlockSeq(); }