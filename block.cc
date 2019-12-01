#include <vector>
#include <utility>
#include "block.h"

Block::Block(std::vector<std::pair<int,int>> pixels, char color, int levelSpawned, int weight): 
    pixels{pixels}, 
    color{color},
    levelSpawned{levelSpawned},
    weight{weight}{}

std::vector<std::pair<int,int>> Block::getPixels(){ return pixels; }
void Block::setPixels(std::vector<std::pair<int,int>> newPixels){ pixels = newPixels; }
char Block::getColor(){ return color; }
int Block::getLevelSpawned(){ return levelSpawned; }
int Block::getWeight(){ return weight; }
void Block::increaseWeight(int inc){ weight += inc; }

Block::~Block(){}