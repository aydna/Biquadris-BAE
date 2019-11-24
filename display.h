#ifndef DISPLAY_H
#define DISPLAY_H
#include <vector>
#include <utility>
#include <memory>
#include <iostream>
//#include "game.h"

class Game;

struct Player {
    std::pair<int,int> boardSize;
    std::vector<std::vector<char>> grid;
    int score;
    int level;
};

class Display {
    protected:
    // can exchange this for array of however many players
    Player p1;
    Player p2;
    Game* my_game;

    public:
    Display(Game* game);
    void updateDisplay();

    friend std::ostream &operator <<(std::ostream &out, const Display &d); //a friend
};




/*
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
*/


#endif