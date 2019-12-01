
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <fstream> 
#include <sstream>

#include "controller.h"
#include "game.h"
#include "drawer.h"
#include "text_drawer.h"
#include "graphics_drawer.h"

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
        textOnly{textOnly},
        seed{seed},
        scriptfile1{scriptfile1},
        scriptfile2{scriptfile2},
        startLevel{startLevel},
        game{std::make_unique<Game>(seed, scriptfile1, scriptfile2, startLevel)}, 
        currentMultiplicity{1}, 
        currentCommand{""}, 
        currentCommandArg{""},
        commandList{std::vector<std::string>{}} {
    commandList = push_commandNames(this->commandList);
    std::make_unique<TextDrawer>(game.get());
    displays.emplace_back(std::make_unique<TextDrawer>(game.get()));
    if (!textOnly) displays.emplace_back(std::make_unique<GraphicsDrawer>(game.get()));
    for(auto &d : displays) d->updateDisplay();
}

//only public method- main calls run() every time it reads input
bool Controller::run(std::string line) {
    if (readCommand(line)) {
        executeCommand();
        for(auto &d : displays) d->updateDisplay();
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
    } else if (currentCommand == "down") {
        game->moveDown(currentMultiplicity);

    } else if (currentCommand == "clockwise") {
        game->rotateCW(currentMultiplicity);

    } else if (currentCommand == "counterclockwise") {
        game->rotateCCW(currentMultiplicity);

    } else if (currentCommand == "drop") {
        for (int i = 0; i < currentMultiplicity; ++i) {
            
            bool clearTwoRows = game->drop();
            game->clearSpecial();

            if (clearTwoRows == true) { //prompt for special action
                std::cout << "Please enter a special action: 'blind', 'heavy', or 'force'" << std::endl;
                std::string action;
                std::cin >> action;
                if (action == "force") {
                    std::cout << "Which block would you like to spawn on your opponents board?" << std::endl;
                    std::string forceBlockType;
                    std::cin >> forceBlockType;
                    if (! ((forceBlockType == "J")
                        || (forceBlockType == "L")
                        || (forceBlockType == "T")
                        || (forceBlockType == "O")
                        || (forceBlockType == "I")
                        || (forceBlockType == "S")
                        || (forceBlockType == "Z"))) {
                            std::cerr << "Bad block type." << std::endl;
                            return;
                            //add while loop to give player benefit of doubt
                        }

                    game->makeSpecial(action, forceBlockType);
                } else {
                    game->makeSpecial(action);
                }
            }
        }

    } else if (currentCommand == "levelup") {
        game->levelUp(currentMultiplicity);

    } else if (currentCommand == "leveldown") {
        game->levelDown(currentMultiplicity);

    } else if (currentCommand == "norandom") {
        // not sure
        game->giveLevelBlockSeq(currentCommandArg);
    } else if (currentCommand == "random") {
        game->removeLevelBlockSeq();
    } else if (currentCommand == "sequence") {
        std::ifstream sequence{currentCommandArg.c_str()};
        std::string input;
        while (sequence >> input) { 
            run(input);
        }
        
    } else if (currentCommand == "I") {
        game->swapBlock("I");
    } else if (currentCommand == "J") {
        game->swapBlock("J");
    } else if (currentCommand == "L") {
        game->swapBlock("L");
    } else if (currentCommand == "O") {
        game->swapBlock("O");
    } else if (currentCommand == "S") {
        game->swapBlock("S");
    } else if (currentCommand == "Z") {
        game->swapBlock("Z");
    } else if (currentCommand == "T") {
        game->swapBlock("T");
    } else if (currentCommand == "restart") {
        displays.clear();
        game.reset();
        game = std::make_unique<Game>(seed, scriptfile1, scriptfile2, startLevel);
        displays.emplace_back(std::make_unique<TextDrawer>(game.get()));
        if (!textOnly) displays.emplace_back(std::make_unique<GraphicsDrawer>(game.get()));
        for(auto &d : displays) d->updateDisplay();
    }
}


std::ostream &operator <<(std::ostream &out, const Controller &c){
    for (auto &d : c.displays) d->print(out);    
    return out;
}