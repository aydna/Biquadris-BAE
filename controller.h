#ifndef CONTROLLER_H
#define CONTROLLER_H

//inclusions
#include <string>
#include <vector>
#include <memory>

//forward declarations
class Game;
class Drawer;


class Controller final{
    std::unique_ptr<Game> game;
    std::vector<std::unique_ptr<Drawer>> displays;
    int currentMultiplicity;    //number of times a command is executed
    std::string currentCommand; //command name, related to that in the list
    std::string currentCommandArg;  //file name for norandom and sequence
    std::vector<std::string> commandList;

  public:
    Controller(bool textOnly, int seed, std::string scriptfile1, std::string scriptfile2, int startLevel); 
    ~Controller();

    bool run(std::string line);
  
  private:
    bool readCommand(std::string line);
    void executeCommand();
  
  friend std::ostream &operator <<(std::ostream &out, const Controller &c); //a friend

};

#endif