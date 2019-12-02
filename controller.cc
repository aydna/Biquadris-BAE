
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


//helper so we don't have all this hardcoded shit in the ctor
std::vector<std::string> push_commandNames(std::vector<std::string> list) {
    list.push_back("left");
    list.push_back("right");
    list.push_back("down");
    list.push_back("clockwise");
    list.push_back("counterclockwise");
    list.push_back("drop");
    list.push_back("levelup");
    list.push_back("leveldown");
    list.push_back("norandom");
    list.push_back("random");
    list.push_back("sequence");
    list.push_back("I");
    list.push_back("J");
    list.push_back("L");
    list.push_back("O");
    list.push_back("S");
    list.push_back("T");
    list.push_back("Z");
    list.push_back("restart");
    return list;
}

// constrcutor 
// ctors the displays and initiates the first render
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


// only public method- main calls run() every time it reads input
bool Controller::run(std::string line) {
    if (readCommand(line)) {
        executeCommand();
        for(auto &d : displays) d->updateDisplay();
    }
    return !(game->gameOver());
}


// takes the user input and figures out which command to call
// provides some ultra-shortcuts (ie "d" calls "down", not "drop")
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


//the main command handler
//------------------------
void Controller::executeCommand() { 
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
        // if 6drop is called, this drops 3 blocks on each player
            
            bool clearTwoRows = game->drop();
            game->clearSpecial();

            if (clearTwoRows == true) { //prompt for special action
                std::cout << "Please enter a special action: 'blind', 'heavy', or 'force'" << std::endl;
                std::string action;

                while (std::cin >> action) {    // checks for invalid input
                    if (action == "blind" || action == "heavy" || action == "force") {
                        break;
                    } else  {
                        std::cout << "Invalid special action. Try again." << std::endl;
                    }
                }

                if (action == "force") {    // force requires a second input to determine the block type to be forced
                    std::cout << "Which block would you like to spawn on your opponents board?" << std::endl;
                    std::string forceBlockType;
                    while (std::cin >> forceBlockType) {
                        if ((forceBlockType == "J")
                                || (forceBlockType == "L")
                                || (forceBlockType == "T")
                                || (forceBlockType == "O")
                                || (forceBlockType == "I")
                                || (forceBlockType == "S")
                                || (forceBlockType == "Z")) {
                            break;
                        } else {
                            std::cout << "Bad block type. Try again." << std::endl;
                        }
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

// ouput operator wrapping the display print operations
std::ostream &operator <<(std::ostream &out, const Controller &c){
    for (auto &d : c.displays) d->print(out);    
    return out;
}
