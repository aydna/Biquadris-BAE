#include <memory>
#include <iostream>
#include <utility>
#include <exception>
#include "game.h"
#include "board.h"
#include "board_normal.h"
#include "board_blind.h"
#include "board_heavy.h"
#include "board_force.h"
#include "board_special.h"

#include <iostream>

Game::Game(int seed, std::string scriptfile1, std::string scriptfile2, int startLevel) :
    boardSize{std::pair<int,int>(18,11)}, 
    playerTurn{1}, 
    b1{std::make_unique<BoardNormal>(seed, scriptfile1, startLevel)}, 
    b2{std::make_unique<BoardNormal>(seed, scriptfile2, startLevel)} {
        b1->spawnBlock();
    }


int Game::getPlayer() {
    return playerTurn;
}
    
bool Game::gameOver() {
    if (playerTurn == 1) {
        return b1->gameOver();
    }
    return b2->gameOver();
}

std::unique_ptr<Board>& Game::getBoard(int player) {
    if (player == 1) {
        return b1;
    }
    else {
        return b2;
    }
}

void Game::levelUp(int lvl) {
    if (playerTurn == 1) {
        b1->levelUp(lvl);
    }
    else {
        b2->levelUp(lvl);
    }
}

void Game::levelDown(int lvl) {
    if (playerTurn == 1) {
        b1->levelDown(lvl);
    }
    else {
        b2->levelDown(lvl);
    }
}


bool Game::drop() {
    if (playerTurn == 1) {
        if (b1->drop() >= 2) {
            return true;
        }
        //check whether 2 rows were cleared, if so prompt player for special action
        else {
            playerTurn = 2;
            b2->spawnBlock();
            return false;
        }
    }
    else {
        if (b2->drop() >= 2) {
            return true;
        }
        else {
            playerTurn = 1;
            b1->spawnBlock();
            return false;
        }
    }
}


void Game::rotateCW(int mult) {
    if (playerTurn == 1) {
        b1->rotateCW(mult);
    }
    else {
        b2->rotateCW(mult);
    }
}

void Game::rotateCCW(int mult) {
    if (playerTurn == 1) {
        b1->rotateCCW(mult);
    }
    else {
        b2->rotateCCW(mult);
    }
}
    
void Game::moveRight(int mult) {
    if (playerTurn == 1) {
        b1->moveRight(mult);
    }
    else {
        b2->moveRight(mult);
    }
}

void Game::moveLeft(int mult) {
    if (playerTurn == 1) {
        b1->moveLeft(mult);
    }
    else {
        b2->moveLeft(mult);
    }
}

void Game::moveDown(int mult) {
    if (playerTurn == 1) {
        b1->moveDown(mult);
    }
    else {
        b2->moveDown(mult);
    }
}


void Game::swapBlock(std::string type){
    if (playerTurn == 1) {
        b1->swapBlock(type);
    }
    else {
        b2->swapBlock(type);
    }
}

void Game::makeSpecial(std::string type, std::string forceBlockType) {

    if (playerTurn == 1) {
        if (type == "blind") {
            b2 = std::make_unique<BoardBlind>(std::move(b2));
         }
        else if (type == "force") {
            b2 = std::make_unique<BoardForce>(std::move(b2));
        }
        else if (type == "heavy") {
            b2 = std::make_unique<BoardHeavy>(std::move(b2));
        }
    }
    else {
        if (type == "blind") {
            b1 = std::make_unique<BoardBlind>(std::move(b1));
         }
        else if (type == "force") {
            b1 = std::make_unique<BoardForce>(std::move(b1));
        }
        else if (type == "heavy") {
            b1 = std::make_unique<BoardHeavy>(std::move(b1));
        }
    }

    if (playerTurn == 1) {
        playerTurn = 2;
        b2->spawnBlock(forceBlockType);
    }
    else {
        playerTurn = 1;
        b1->spawnBlock(forceBlockType);
    }
}


void Game::clearSpecial() {
    if (playerTurn == 1) {
        try {b2 = std::move(b2->clearSpecial()); }
        catch (int e) {}
    }
    else {
        try {b1 = std::move(b1->clearSpecial()); }
        catch (int e) {}
    }
}


void Game::giveLevelBlockSeq(std::string filename) {
    if (playerTurn == 1) {
        b1->giveLevelBlockSeq(filename);
    }
    else {
        b2->giveLevelBlockSeq(filename);
    }
}

void Game::removeLevelBlockSeq() {
    if (playerTurn == 1) {
        b1->removeLevelBlockSeq();
    }
    else {
        b2->removeLevelBlockSeq();
    }
}
