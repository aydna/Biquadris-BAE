
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <fstream>  //do I need this with IOstream?
#include <sstream>

#include "controller.h"
// #include "game.h"
// #include "display.h"

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
        game{std::unique_ptr<Game>{}}, 
        display{std::unique_ptr<Display>{}}, 
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
        display->update();
    }
    return !(game->gameOver());
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
        game->moveLeft(-1 * currentMultiplicity);
    } else if (currentCommand == "right") {
        game->moveRight(currentMultiplicity);

    } else if (currentCommand == "down") {
        game->moveDown(currentMultiplicity);

    } else if (currentCommand == "clockwise") {
        game->rotateCW(currentMultiplicity);

    } else if (currentCommand == "counterclockwise") {
        game->rotateCCW(currentMultiplicity);

    } else if (currentCommand == "drop") {
        game->drop(currentMultiplicity);

    } else if (currentCommand == "levelup") {
        game->levelup(currentMultiplicity);

    } else if (currentCommand == "leveldown") {
        game->leveldown(currentMultiplicity);

    } else if (currentCommand == "norandom") {
        // not sure
        // game->giveLevelBlockSequence(currentCommandArg);
    } else if (currentCommand == "random") {
        // game->removeLevelBlockSequence();
    } else if (currentCommand == "sequence") {
        // std::ifstream sequence{currentCommandArg.c_str()};
        // std::string line;
        // while (getline(sequence, line)) { 
        //     run(line);
        // }
    } else if (currentCommand == "I") {
        // not sure
        // game->swapBlock("I");
    } else if (currentCommand == "J") {
    
    } else if (currentCommand == "L") {

    } else if (currentCommand == "O") {

    } else if (currentCommand == "S") {

    } else if (currentCommand == "T") {

    } else if (currentCommand == "restart") {
        game->restart();
    }
}