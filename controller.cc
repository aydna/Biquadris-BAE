
#include <string>
#include <vector>
#include <memeory>
#include <iostream>
#include <fstream>  //do I need this with IOstream?
#include "controller.h"


//helper so we can push the command names from a file for sanity
void push_commandNames(std::vector<std::string> &list) {
    std::ifstream filein{"functionlist.txt"};
    std::string line;
    while (filein >> line) {
        list.push_back(line)
    }
    filein.close();
}


Controller::Controller()
    :   game{std::uniqe_ptr<Game>{}}, 
        display{std::unique_ptr<Display>{}}, 
        currentMultiplicity{1}, 
        currentCommand{""}, 
        commandList{} {
    push_commandNames(this->commandList);
}

Controller::~Controller() {
    // // fix this
    // delete game;
    // delete display;
}

void Controller::run() {
    std::string input;
    while (std::cin >> input) {
        if (readCommand(input)) {
            executeCommand();
            //update display
        }
    }
}


bool Controller::readCommand(std::string com) {
    int inLength = com.length();
    for (auto &func : commandList) {
        if  (com == (*func).substr(0, inLength)) {
            std::cout << "Calling " << *func << endl;
            currentCommand = *func;
            return true;
        }
    }
    return false;
}

void executeCommand() { //need multiplicity functionality
    if (currentCommand == "left") {
        game->moveLeft();
    } else if (currentCommand == "right") {
        game->moveRight();
    } else if (currentCommand == "down") {
        game->moveDown();
    } else if (currentCommand == "clockwise") {
        game->rotateCW();
    } else if (currentCommand == "counterclockwise") {
        game->rotateCCW();
    } else if (currentCommand == "drop") {
        game->drop();
    } else if (currentCommand == "levelup") {
        game->levelup();
    } else if (currentCommand == "leveldown") {
        game->leveldown();
    } else if (currentCommand == "norandom") {
        // not sure
        // std::string filename;
        // std::cin >> filename;
        // game->giveLevelSequence(filename);
    } else if (currentCommand == "random") {
        // game->removeLevelSequence();
    } else if (currentCommand == "sequence") {
        // std::string filename;
        // std::cin >> filename;
        // std::ifstream sequence{filename.c_str()};
        // std::string command;
        // while (sequence >> command) {
        //     if (readCommand(input)) {
        //         executeCommand();
        //     }
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