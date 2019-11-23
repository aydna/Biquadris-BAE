#ifndef DISPLAY_H
#define DISPLAY_H
#include <vector>
#include <utility>
#include <memory>
#include <iostream>
#include "block.h"

class Display{
    // also figure out the 3 reserve rows problem
    std::pair<int,int> boardSize= std::pair<int,int>(18,10); // (rows, cols)
    std::vector<std::vector<char>> grid1;
    std::vector<std::vector<char>> grid2;
    
    public:
        Display();
        void update(const std::vector<std::unique_ptr<Block>> &blocks1, const std::vector<std::unique_ptr<Block>> &blocks2);
        friend std::ostream &operator <<(std::ostream &out , const Display &d); //controller should use this to print to stdout
};

#endif