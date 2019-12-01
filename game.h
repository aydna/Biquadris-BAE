#ifndef GAME_H
#define GAME_H
#include <memory>
#include <utility>
#include <iostream>
#include "board.h"
#include <string>


class Game {
    // Private fields
    std::pair<int,int> boardSize;
    int playerTurn;
    std::unique_ptr<Board> b1;
    std::unique_ptr<Board> b2;
    public:
    // Ctor v1.0 (accomodates for multiple players (2 for phase0))

    Game(int seed, std::string scriptfile1, std::string scriptfile2, int startLevel);
    int getPlayer(); //gets curr player's turn
    bool gameOver();
    std::unique_ptr<Board>& getBoard(int player);
    void levelUp(int lvl);
    void levelDown(int lvl);
    void drop();
    void rotateCW(int mult);
    void rotateCCW(int mult);
    void moveRight(int mult);
    void moveLeft(int mult);
    void moveDown(int mult);
    void swapBlock(std::string type);
    void makeSpecial(std::string type); //special effects
    void clearSpecial(); //clears special effects
    void giveLevelBlockSeq(std::string fname);
    void removeLevelBlockSeq(std::string fname);
};



/*
class Game{
    Display *d;
    // also figure out the 3 reserve rows problem
    std::pair<int,int> boardSize = std::pair<int,int>(18,11); // change to solid numbers
    int playerTurn;
    std::unique_ptr<Board> b1;
    std::unique_ptr<Board> b2;
    //next block???? Display needs to know before it spawns? Level should do something i think? queue the next block or something
    public:
        Game(Display *d);
        void spawnBlock();
        void moveLeft();
        void moveRight();
        void drop();
};
*/


#endif