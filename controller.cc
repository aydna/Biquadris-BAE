#include <string>
#include <iostream>
#include <memory>
#include "controller.h"
#include "display.h"
#include "game.h"


Controller::Controller(): 
    d{std::make_unique<Display>()}, 
    g{std::make_unique<Game>(d.get())}{}

void Controller::run(){
    std::string input;

    /*
    //version 1 of Controller class
    Controller ctrl = new Controller{};
    stringstream command = ctrl->getCommand();
    
    while (command >> input) .......
    */

    //simple commands
    while (std::cin >> input){
        if (input == "spawn"){
            g->spawnBlock();
        }
        else if (input == "right"){
            g->moveRight();
        }
        else if (input == "left"){
            g->moveLeft();
        }
        else if (input == "drop"){
            g->drop();
        }
        std::cout << *d << std::endl; 
    }
}