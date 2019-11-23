#ifndef CONTROLLER_H
#define CONTROLLER_H

//inclusions
#include <string>
#include <vector>
#include <memory>

//forward declarations
class Game;
class Display;


class Controller final{
    std::unique_ptr<Game> game;
    std::unique_ptr<Display> display;
    int currentMultiplicity;    //number of times a command is executed
    std::string currentCommand; //command name, related to that in the list
    std::vector<std::string> &commandList;

  public:
    Controller(); 
    ~Controller();

    void run();
  
  private:
    bool readCommand(std::string com);
    void executeCommand();

};

#endif