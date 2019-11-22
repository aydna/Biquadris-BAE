#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <memory>
#include "display.h"
#include "game.h"

class Controller{
    std::unique_ptr<Display> d;
    std::unique_ptr<Game> g;
    
    public:
        Controller();
        void run();
};

#endif