#include <vector>
#include <memory>
#include <utility>
#include <climits>
#include <string>
#include "block.h"
#include "level.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "level5.h"
#include "board.h"
#include "board_normal.h"
#include "block_dot.h"

BoardNormal::BoardNormal(int seed, std::string scriptfile, int startLevel):
    level{startLevel},
    seed{seed},
    file{scriptfile}{
        if (level == 0) currLevel = std::make_unique<Level0>(seed, file);
        else if (level == 1) currLevel = std::make_unique<Level1>(seed, file);
        else if (level == 2) currLevel = std::make_unique<Level2>(seed, file);
        else if (level == 3) currLevel = std::make_unique<Level3>(seed, file);
        else if (level == 4) currLevel = std::make_unique<Level4>(seed, file);
        else if (level == 5) currLevel = std::make_unique<Level5>(seed, file);
        nextBlock = std::move(currLevel->spawnBlock()); //loading first block to be played
    } 

//gets a vector of all the pixels on the board except for (offBack) many off the back, most of the time it will be 0 or 1
std::vector<std::pair<int,int>> BoardNormal::getBoardPixels(int offBack){ 
    std::vector<std::pair<int,int>> boardPixels;
    for (auto b = blocks.begin(); b != blocks.end() - offBack; ++b){
        std::vector<std::pair<int,int>> bp = (*b)->getPixels();
        for (auto p : bp){
            boardPixels.emplace_back(p);
        }
    }
    return boardPixels;
}

//checks if a set of pexels is in a valid place
bool BoardNormal::validMove(std::vector<std::pair<int,int>> pixels){
    std::vector<std::pair<int,int>> boardPixels = getBoardPixels(1); // rest of blocks
    for (auto p : pixels){
        if((p.first < 0) || (p.first >= 18) || (p.second < 0) || (p.second >= 11)) return false; //tests if  pixel out of range
        for (auto bp : boardPixels){  
            if((bp.first == p.first) && (bp.second == p.second))  return false; // tests if current pixel on another pixel
        }
    }
    return true; //no collison with other pixels
}

//removes all the rows with full rows and returns the number of rows cleared by the move
int BoardNormal::removeRow(){
    int rowsCleared = 0;

    for(int row = 17; row >= 4; --row){ //starting at row 17 to 4 
        std::vector<std::pair<int,int>> boardPixels = getBoardPixels(0); // check all pixels
        int counter = 0; // counter for pixels in the current row
        for (auto bp : boardPixels) if (bp.first == row) ++counter;
        if(counter == 0) break;             //if row is empty (0) this means that there are not pixels above and we are done
        if (counter == 11){                 //if row is full (11) this means this row needs to be removed and all blocks above must drop
            auto b = blocks.begin();
            while (b != blocks.end()){ //go through all blocks
                std::vector<std::pair<int,int>> newPixels;
                for (auto p : (*b)->getPixels()){ // this loop is excluding the pixels in the row
                    if (p.first < row) newPixels.emplace_back(std::pair<int,int>{p.first + 1, p.second}); //if above row drop
                    else if (p.first > row) newPixels.emplace_back(p);                                    //if below row do nothing
                }
                if (newPixels.size() == 0){     //if block empty, remove it
                    score += ((*b)->getLevelSpawned() + 1) * ((*b)->getLevelSpawned() + 1); // calculates the score
                    b = blocks.erase(b);
                }
                else{       //if block isnt empty
                    (*b)->setPixels(newPixels);
                    ++b;
                }
            }
            ++row; //reindexing the outter for loop
            ++rowsCleared; //for scoring
        }
    }
    if (rowsCleared > 0) score += (rowsCleared + level) * (rowsCleared + level); // calcs score

    return rowsCleared;
}

//spanws the block currently in nextBlock onto the board
void BoardNormal::spawnBlock(std::string type, int weight){
    nextBlock->increaseWeight(weight); 
    blocks.emplace_back(std::move(nextBlock)); //places nextBlok on to the board
    nextBlock = currLevel->spawnBlock();       // makes a new nextBlock
    checkGameOver(blocks.back()->getPixels()); //checks if the game will end if the block is spawned where it is
}

//swaps the current block with another one of type
void BoardNormal::swapBlock(std::string type, int weight){
    blocks.pop_back();
    blocks.emplace_back(currLevel->spawnBlock(type));
    blocks.back()->increaseWeight(weight); 
    checkGameOver(blocks.back()->getPixels());
}

//level up by times
void BoardNormal::levelUp(int times){
    level += times; 
    if (level > 5) level = 5;
    if (level == 0) currLevel = std::make_unique<Level0>(seed, file);
    else if (level == 1) currLevel = std::make_unique<Level1>(seed, file);
    else if (level == 2) currLevel = std::make_unique<Level2>(seed, file);
    else if (level == 3) currLevel = std::make_unique<Level3>(seed, file);
    else if (level == 4) currLevel = std::make_unique<Level4>(seed, file);
    else if (level == 5) currLevel = std::make_unique<Level5>(seed, file);
    nextBlock = std::move(currLevel->spawnBlock());
}

//level down by times
void BoardNormal::levelDown(int times){
    level -= times; 
    if (level < 0) level = 0;
    if (level == 0) currLevel = std::make_unique<Level0>(seed, file);
    else if (level == 1) currLevel = std::make_unique<Level1>(seed, file);
    else if (level == 2) currLevel = std::make_unique<Level2>(seed, file);
    else if (level == 3) currLevel = std::make_unique<Level3>(seed, file);
    else if (level == 4) currLevel = std::make_unique<Level4>(seed, file);
    else if (level == 5) currLevel = std::make_unique<Level5>(seed, file);
    nextBlock = std::move(currLevel->spawnBlock());
}

//move right times times
void BoardNormal::moveRight(int times){
    std::vector<std::pair<int,int>> pixels = blocks.back()->getPixels();
    for (int i = 0; i < times; ++i){
        std::vector<std::pair<int,int>> testPixels = pixels;
        for (auto &tp : testPixels) ++tp.second;    //moves testPixels 1 to the right
        if (!validMove(testPixels)) break;          //checks if it is a valid move
        for (auto &p : pixels) ++p.second;          //actually moves pixles 1 to the right
    }
    blocks.back()->setPixels(pixels);       //actually sets the pixels for the block
    moveDown(blocks.back()->getWeight());   //block moves down by heavy amount (weight)
}

//moves left times times
void BoardNormal::moveLeft(int times){
    std::vector<std::pair<int,int>> pixels = blocks.back()->getPixels();
    for (int i = 0; i < times; ++i){
        std::vector<std::pair<int,int>> testPixels = pixels;
        for (auto &tp : testPixels) --tp.second;    //moves testPixels 1 to the left
        if (!validMove(testPixels)) break;          //checks if it is a valid move
        for (auto &p : pixels) --p.second;          //actually moves pixles 1 to the left
    }
    blocks.back()->setPixels(pixels);
    moveDown(blocks.back()->getWeight());
}

//moves down times times
void BoardNormal::moveDown(int times){
    std::vector<std::pair<int,int>> pixels = blocks.back()->getPixels();
    for (int i = 0; i < times; ++i){
        std::vector<std::pair<int,int>> testPixels = pixels;
        for (auto &tp : testPixels) ++tp.first;    //moves testPixels 1 to the down
        if (!validMove(testPixels)) break;          //checks if it is a valid move
        for (auto &p : pixels) ++p.first;          //actually moves pixles 1 to the down
    }
    blocks.back()->setPixels(pixels);
}

//rotates clockwise times times
void BoardNormal::rotateCW(int times){
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
        int height = ((rowMax - rowMin) > (colMax - colMin)) ? (rowMax - rowMin) :  (colMax - colMin);  //finds the "height" of the block
        int xoffset = rowMax - height;
        int yoffset = colMin;

        int newRowMax = INT_MIN;

        std::vector<std::pair<int,int>> testPixels = pixels;
        for (auto &tp : testPixels){   // (x,y) -> (y - yoffset + xoffset, height - x + xoffset + yoffset)
            int x = tp.first;
            int y = tp.second;
            tp.first = y - yoffset + xoffset;
            tp.second = height - x + xoffset + yoffset;         //rotates testblock cw 90degrees
            if (tp.first > newRowMax) newRowMax = tp.first;
        }
        for (auto &tp : testPixels){
            tp.first += (rowMax - newRowMax);       //fixes spacing
        }
        if (!validMove(testPixels)) break;          //checks if it is a valid move
        for (auto &p : pixels){                     //actually rotates testblock
            int x = p.first;
            int y = p.second;
            p.first = y - yoffset + xoffset + (rowMax - newRowMax);
            p.second = height - x + xoffset + yoffset;
        }
    }
    blocks.back()->setPixels(pixels);
    moveDown(blocks.back()->getWeight());
}

//rotates counterclockwise times times
void BoardNormal::rotateCCW(int times){
    rotateCW((times % 4)* 3);       //works <3
}

//moves the block down as far as it go and then removes the rows that can be removed
int BoardNormal::drop(){
    moveDown(18);
    int rowsRemoved = removeRow();
    if (rowsRemoved == 0) ++roundsSinceClear;
    else roundsSinceClear = 0;
    if ((roundsSinceClear >= 5) && (level == 4)){
        roundsSinceClear = 0;
        blocks.emplace_back(std::make_unique<BlockDot>(4,0));
        moveDown(18);
    }
    return rowsRemoved;
}

int BoardNormal::getLevel(){ return level; }

int BoardNormal::getScore(){ return score; }

std::vector<BoardPixels> BoardNormal::getBlocks(){ 
    std::vector<BoardPixels> bp;
    for (auto &b : blocks){
        for (auto p : b->getPixels()){
            bp.emplace_back(BoardPixels{p, b->getColor()});
        }
    }
    return bp; 
}

std::vector<BoardPixels> BoardNormal::getNextBlock(){ 
    std::vector<BoardPixels> np;
    for (auto p : nextBlock->getPixels()){
        np.emplace_back(BoardPixels{p, nextBlock->getColor()});
    }
    return np; 
}

//checks if the game is over, if it should end, it turns on the gameOverSwitch
void BoardNormal::checkGameOver(std::vector<std::pair<int,int>> pixels){
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

bool BoardNormal::gameOver(){ return gameOverSwitch; }

void BoardNormal::giveLevelBlockSeq(std::string filename) {
    currLevel->giveLevelBlockSeq(filename);
}

void BoardNormal::removeLevelBlockSeq() {
    currLevel->removeLevelBlockSeq();
}

std::unique_ptr<Board>&& BoardNormal::clearSpecial(){ throw 1; }
