#include <memory>
#include <iostream>
#include <utility>
#include "game.h"
#include "board.h"


Game::Game() :
    boardSize{std::pair<int,int>(18,11)}, currPlayerTurn{1}, b1{new Board}, b2{new Board} {
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

Board* Game::getBoard(int player) {
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


void Game::drop() {
    if (playerTurn == 1) {
        b1->drop();
        playerTurn = 2;
        b2->spawnBlock();
    }
    else {
        b2->drop();
        playerTurn = 1;
        b1->spawnBlock();
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

void Game::makeSpecial(std::string type, int mult) {
    if (playerTurn == 1) {
        b2->makeSpecial(mult); // apply special board to opponent's board
    }
    else {
        b1->makeSpecial(mult);
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