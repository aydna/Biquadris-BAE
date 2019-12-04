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

    Game(int seed, std::string scriptfile1, std::string scriptfile2, int startLevel);
    int getPlayer(); //gets curr player's turn
    bool gameOver();
    std::unique_ptr<Board>& getBoard(int player);
    void levelUp(int lvl);
    void levelDown(int lvl);
    bool drop(); //ends turn
    void rotateCW(int mult);
    void rotateCCW(int mult);
    void moveRight(int mult);
    void moveLeft(int mult);
    void moveDown(int mult);
    void swapBlock(std::string type); // swaps next block to be of type 'type'
    void makeSpecial(std::string type, std::string forceBlockType = ""); //special effects
    void clearSpecial(); //clears special effects
    void giveLevelBlockSeq(std::string filename); 
    void removeLevelBlockSeq();

};

#endif
