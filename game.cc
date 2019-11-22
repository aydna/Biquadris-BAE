#include <memory>
#include <iostream>
#include <utility>
#include "game.h"
#include "board.h"
#include "display.h"


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
