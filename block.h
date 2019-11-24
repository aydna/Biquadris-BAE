#ifndef BLOCK_H
#define BLOCK_H
#include <vector>
#include <utility>

class Block{
    std::vector<std::pair<int,int>> pixels;
    char color;
    public:
        Block(std::vector<std::pair<int,int>> pixels, char color);
        std::vector<std::pair<int,int>> getPixels();
        void setPixels(std::vector<std::pair<int,int>> newPixels);
        char getColor();
};

#endif