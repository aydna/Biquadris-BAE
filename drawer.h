#ifndef DRAWER_H
#define DRAWER_H
#include <vector>
#include <utility>
#include <memory>
#include <iostream>
//#include "game.h"

class Game;

struct playerImpl{
    std::pair<int,int> boardSize;
    std::vector<std::vector<char>> oldGrid;
    std::vector<std::vector<char>> grid;
    std::vector<std::vector<char>> nextBlock;
    int score;
    int level;
};

class Drawer {
    protected:
    // can exchange this for array of however many players
    Game* my_game;
    std::unique_ptr<playerImpl> p1; //pImpl idiom
    std::unique_ptr<playerImpl> p2; 
    


    public:
    Drawer(Game* game);
    virtual std::ostream& print(std::ostream& out)=0;
    void updateDisplay();
    void makeBlind();
    virtual ~Drawer()=0;
};


#endif
