#ifndef BLOCK_H
#define BLOCK_H
#include <vector>
#include <utility>

class Block{
    public:
        std::vector<std::pair<int,int>> pixels; // move this to private and make an accessor 
        Block(std::vector<std::pair<int,int>> pixels);
        void moveRight();
        void moveLeft();
        void drop(int distance);
};

#endif