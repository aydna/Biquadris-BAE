#ifndef CONTROLLER_H
#define CONTROLLER_H

//inclusions
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "game.h"
#include "drawer.h"


class Controller{
    bool textOnly;  // run graphics or not
    int seed;       // random seed
    std::string scriptfile1;  // the block files initialized in level 0
    std::string scriptfile2;
    int startLevel;

    std::unique_ptr<Game> game;   //controller points at a game and all the displays
    std::vector<std::unique_ptr<Drawer>> displays;
    int currentMultiplicity;    //number of times a command is executed
    std::string currentCommand; //command name, related to that in the list
    std::string currentCommandArg;  //file name for norandom and sequence
    std::vector<std::string> commandList; //list of valid commands

  public:
    Controller(bool textOnly, int seed, std::string scriptfile1, std::string scriptfile2, int startLevel); 
    bool run(std::string line);
  
  private:
    bool readCommand(std::string line);   // checks if a command is valid
    void executeCommand();                // exucutes the command specified
  
  friend std::ostream &operator <<(std::ostream &out, const Controller &c); //a friend

};

#endif