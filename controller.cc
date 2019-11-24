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
    int n;
    while (std::cin >> input){
        if (input == "right"){
            std::cin >> n;
            g->moveRight(n);
        }
        else if (input == "left"){
            std::cin >> n;
            g->moveLeft(n);
        }
        else if (input == "down"){
            std::cin >> n;
            g->moveDown(n);
        }
        else if (input == "cw"){
            std::cin >> n;
            g->rotateCW(n);
        }
        else if (input == "ccw"){
            std::cin >> n;
            g->rotateCCW(n);
        }
        else if (input == "drop"){
            g->drop();
        }
        std::cout << *d << std::endl; 
    }
}