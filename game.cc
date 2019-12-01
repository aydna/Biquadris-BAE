#include <memory>
#include <iostream>
#include <utility>
#include "game.h"
#include "board.h"


Game::Game(int seed, std::string scriptfile1, std::string scriptfile2, int startLevel) :
    boardSize{std::pair<int,int>(18,11)}, 
    playerTurn{1}, 
    b1{std::make_unique<Board>(seed, scriptfile1, startLevel)}, 
    b2{std::make_unique<Board>(seed, scriptfile2, startLevel)} {
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

void Game::makeSpecial(std::string type) {
    
    if (playerTurn == 1) {
        std::unique_ptr<Board>& curr_board = b2;
        //b2->makeSpecial(mult); // apply special board to opponent's board
    }
    else {
        std::unique_ptr<Board>& curr_board = b1;
        //b1->makeSpecial(mult);
    }

    if (type == "blind") {
        curr_board{BlindBoard{std::move{curr_board}}};
    }
    else if (type == "force") {
        curr_board{ForceBoard{std::move{curr_board}}};
    }
    else if (type == "heavy") {
        curr_board{HeavyBoard{std::move{curr_board}}};
    }

    if (playerTurn == 1) {
        playerTurn == 2;
        b2->spawnBlock();
    }
    else {
        playerTurn == 1;
        b1->spawnBlock();
    }
}


void Game::clearSpecial() {
    if (playerTurn == 1) {
        b2{std::move{b2->clearSpecial()}};
    }
    else {
        b1{std::move{b1->clearSpecial()}};
    }
}


void Game::giveLevelBlockSeq(std::string fname) {}

void removeLevelBlockSeq() {}





/*

//these methods are gabage, ill FIX IT later -Botao
Game::Game(Display *d): 
    d{d},
    playerTurn{0}, 
    b1{std::make_unique<Board>(0)},
    b2{std::make_unique<Board>(1)}
    {}

void Game::spawnBlock(){
    if (playerTurn == 0){
        b1->spawnBlock();
    }
    else if (playerTurn == 1){
        b2->spawnBlock();
    }
    d->update(b1->getBlocks(),b2->getBlocks());
}

void Game::moveLeft(){
    if (playerTurn == 0){
        b1->moveLeft();
    }
    else if (playerTurn == 1){
        b2->moveLeft();
    }
    d->update(b1->getBlocks(),b2->getBlocks());
}

void Game::moveRight(){
    if (playerTurn == 0){
        b1->moveRight();
    }
    else if (playerTurn == 1){
        b2->moveRight();
    }
    d->update(b1->getBlocks(),b2->getBlocks());
}

void Game::drop(){
    if (playerTurn == 0){
        b1->drop();
        playerTurn = 1;
    }
    else if (playerTurn == 1){
        b2->drop();
        playerTurn = 0;
    }
    d->update(b1->getBlocks(),b2->getBlocks());
}

*/