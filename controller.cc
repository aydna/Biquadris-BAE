
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <fstream>  //do I need this with IOstream?
#include <sstream>

#include "controller.h"
#include "game.h"
#include "display.h"

//helper so we can push the command names from a file for sanity
std::vector<std::string> push_commandNames(std::vector<std::string> list) {
    std::ifstream filein{"functionlist.txt"};
    std::string line;
    while (filein >> line) {
        list.push_back(line);
    }
    filein.close();
    return list;
}

//constrcutor (doesn't do a whole lot)
Controller::Controller() :
        game{std::make_unique<Game>()}, 
        display{std::make_unique<Display>()}, 
        currentMultiplicity{1}, 
        currentCommand{""}, 
        currentCommandArg{""},
        commandList{std::vector<std::string>{}} {
    commandList = push_commandNames(this->commandList);
}

//destructor
Controller::~Controller() {}

//only public method- main calls run() every time it reads input
bool Controller::run(std::string line) {
    if (readCommand(line)) {
        executeCommand();
        //display->update();
    }
    //return !(game->gameOver());
    return true;
}


bool Controller::readCommand(std::string line) {
    std::stringstream pants{line};
    currentMultiplicity = 1;
    pants >> currentMultiplicity;
    if (pants.fail()) pants.clear();

    std::string com;
    pants >> com;
    pants >> currentCommandArg;

    int inLength = com.length();
    for (auto &func : commandList) {
        if  (com == func.substr(0, inLength)) {
            std::cout << "Calling " << func << std::endl;
            currentCommand = func;
            return true;
        }
    }
    std::cout << "No command found" << std::endl;
    return false;
}

void Controller::executeCommand() { //need multiplicity functionality
    if (currentCommand == "left") {
        //game->moveLeft(currentMultiplicity);
        std::cout << "game.moveleft(" << currentMultiplicity << std::endl;
    } else if (currentCommand == "right") {
        //game->moveRight(currentMultiplicity);
        std::cout << "game.moveright" << std::endl;

    } else if (currentCommand == "down") {
        //game->moveDown(currentMultiplicity);
        std::cout << "movedown" << std::endl;

    } else if (currentCommand == "clockwise") {
        //game->rotateCW(currentMultiplicity);
        std::cout << "CW" << std::endl;

    } else if (currentCommand == "counterclockwise") {
        //game->rotateCCW(currentMultiplicity);
        std::cout << "CCW" << std::endl;

    } else if (currentCommand == "drop") {
        //game->drop(currentMultiplicity);
        std::cout << "drop" << std::endl;

    } else if (currentCommand == "levelup") {
        //game->levelup(currentMultiplicity);
        std::cout << "levelup" << std::endl;

    } else if (currentCommand == "leveldown") {
        //game->leveldown(currentMultiplicity);
        std::cout << "leveldown" << std::endl;

    } else if (currentCommand == "norandom") {
        // not sure
        // game->giveLevelBlockSequence(currentCommandArg);
        std::cout << "norandom " << currentCommandArg << std::endl;
    } else if (currentCommand == "random") {
        // game->removeLevelBlockSequence();
    } else if (currentCommand == "sequence") {
        // std::ifstream sequence{currentCommandArg.c_str()};
        // std::string line;
        // while (getline(sequence, line)) { 
        //     run(line);
        // }
        std::cout << "read input from file temporarily" << std::endl;
    } else if (currentCommand == "I") {
        // not sure
        // game->swapBlock("I");
    } else if (currentCommand == "J") {
    
    } else if (currentCommand == "L") {

    } else if (currentCommand == "O") {

    } else if (currentCommand == "S") {

    } else if (currentCommand == "T") {

    } else if (currentCommand == "restart") {
        //everything goes here, no method calls
        //game.reset(new Game{});
        std::cout << "restarting" << std::endl;
    }
}