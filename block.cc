#include <vector>
#include <utility>
#include "block.h"


Block::Block(std::vector<std::pair<int,int>> pixels): pixels{pixels}{}

void Block::moveRight(){
    for (auto &p : pixels){
        ++p.second;
    }
}
void Block::moveLeft(){
    for (auto &p : pixels){
        --p.second;
    }
}
void Block::drop(int distance){
    for (auto &p : pixels){
        p.first += distance;
    }
}