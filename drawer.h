#ifndef DRAWER_H
#define DRAWER_H
#include <vector>
#include <utility>
#include <memory>
#include <iostream>
//#include "game.h"

class Game;

/*
struct Player {
    std::pair<int,int> boardSize;
    std::vector<std::vector<char>> oldGrid;
    std::vector<std::vector<char>> grid;
    std::vector<std::vector<char>> nextBlock;
    int score;
    int level;
};
*/

class Drawer {
    protected:
    // can exchange this for array of however many players
    class playerImpl;

    unique-ptr<playerImpl> p1; //pImpl idiom
    unique-ptr<playerImpl> p2; 
    
    Game* my_game;

    public:
    Drawer(Game* game);
    virtual std::ostream& print(std::ostream& out)=0;
    void updateDisplay();
    void makeBlind();
    ~Drawer(); // need explicit def
};




/*
class Drawer{
    // also figure out the 3 reserve rows problem
    std::pair<int,int> boardSize= std::pair<int,int>(18,10); // (rows, cols)
    std::vector<std::vector<char>> grid1;
    std::vector<std::vector<char>> grid2;
    
    public:
        Drawer();
        void update(const std::vector<std::unique_ptr<Block>> &blocks1, const std::vector<std::unique_ptr<Block>> &blocks2);
        friend std::ostream &operator <<(std::ostream &out , const Drawer &d); //controller should use this to print to stdout
};
*/


#endif