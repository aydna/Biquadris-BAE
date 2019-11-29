#ifndef BLOCK_H
#define BLOCK_H
#include <vector>
#include <utility>

class Block{
    std::vector<std::pair<int,int>> pixels;
    char color;
    int levelSpawned;
    int weight;

    public:
        Block(std::vector<std::pair<int,int>> pixels, char color, int levelSpawned, int weight);
        std::vector<std::pair<int,int>> getPixels();
        void setPixels(std::vector<std::pair<int,int>> newPixels);
        char getColor();
        int getLevelSpawned();
        int getWeight();
};

#endif