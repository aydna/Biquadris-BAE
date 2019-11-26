
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
Controller::Controller(bool textOnly, int seed, std::string scriptfile1, std::string scriptfile2, int startLevel):
        game{std::make_unique<Game>(seed, scriptfile1, scriptfile2, startLevel)}, 
        display{std::make_unique<Display>(game.get())}, 
        currentMultiplicity{1}, 
        currentCommand{""}, 
        currentCommandArg{""},
        commandList{std::vector<std::string>{}} {
    commandList = push_commandNames(this->commandList);
    display->updateDisplay();
}

//destructor
Controller::~Controller() {}

//only public method- main calls run() every time it reads input
bool Controller::run(std::string line) {
    if (readCommand(line)) {
        executeCommand();
        display->updateDisplay();
    }
    return !(game->gameOver());
}


bool Controller::readCommand(std::string line) {
    std::stringstream pants{line};
    
    pants >> currentMultiplicity;
    if (pants.fail()) {
        pants.clear();
        currentMultiplicity = 1;
    }

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
        game->moveLeft(currentMultiplicity);
    } else if (currentCommand == "right") {
        game->moveRight(currentMultiplicity);
        //std::cout << currentMultiplicity << std::endl;

    } else if (currentCommand == "down") {
        game->moveDown(currentMultiplicity);

    } else if (currentCommand == "clockwise") {
        game->rotateCW(currentMultiplicity);

    } else if (currentCommand == "counterclockwise") {
        game->rotateCCW(currentMultiplicity);

    } else if (currentCommand == "drop") {
        // add mult piclid y 
        game->drop();

    } else if (currentCommand == "levelup") {
        game->levelUp(currentMultiplicity);

    } else if (currentCommand == "leveldown") {
        game->levelDown(currentMultiplicity);

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
        //game->restart();
    }
}


std::ostream &operator <<(std::ostream &out, const Controller &c){
    out << *c.display;
    return out;
}