#ifndef TEXT_DISPLAY_H
#define TEXT_DISPLAY_H
#include <vector>
#include <utility>
#include <memory>
#include <iostream>
#include "drawer.h"

class TextDrawer: public Drawer {
    
    public:
    TextDrawer(Game* game);
    std::ostream& print(std::ostream& out) override;
};

#endif