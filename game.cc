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
    {b1->spawnBlock();}

void Game::spawnBlock(){
    if (playerTurn == 0){
        b1->spawnBlock();
    }
    else if (playerTurn == 1){
        b2->spawnBlock();
    }
    d->update(b1->getBlocks(),b2->getBlocks());
}

void Game::moveRight(int distance){
    if (playerTurn == 0){
        b1->moveRight(distance);
    }
    else if (playerTurn == 1){
        b2->moveRight(distance);
    }
    d->update(b1->getBlocks(),b2->getBlocks());
}

void Game::moveLeft(int distance){
    if (playerTurn == 0){
        b1->moveLeft(distance);
    }
    else if (playerTurn == 1){
        b2->moveLeft(distance);
    }
    d->update(b1->getBlocks(),b2->getBlocks());
}

void Game::moveDown(int distance){
    if (playerTurn == 0){
        b1->moveDown(distance);
    }
    else if (playerTurn == 1){
         b2->moveDown(distance);
    }
    d->update(b1->getBlocks(),b2->getBlocks());
}


void Game::rotateCW(int times){
    if (playerTurn == 0){
        b1->rotateCW(times);
    }
    else if (playerTurn == 1){
         b2->rotateCW(times);
    }
    d->update(b1->getBlocks(),b2->getBlocks());
}


void Game::rotateCCW(int times){
    if (playerTurn == 0){
        b1->rotateCCW(times);
    }
    else if (playerTurn == 1){
         b2->rotateCCW(times);
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
    spawnBlock();
}
