#include <vector>
#include <utility>
#include "block.h"


Block::Block(std::vector<std::pair<int,int>> pixels, char color): pixels{pixels}, color{color}{}

std::vector<std::pair<int,int>> Block::getPixels(){
    return pixels;
}

void Block::setPixels(std::vector<std::pair<int,int>> newPixels){
    pixels = newPixels;
}

char Block::getColor(){
    return color;
}