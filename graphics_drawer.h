#ifndef GRAPHICS_DISPLAY_H
#define GRAPHICS_DISPLAY_H
#include <vector>
#include <utility>
#include <memory>
#include <iostream>
#include <map>
#include "drawer.h"
#include "window.h"

class GraphicsDrawer: public Drawer {
    Xwindow w{1200,800};
    std::map<char,int> colors;
    Xwindow hs{400,400};

    void drawBoxes(int bs);
    void drawHeaders(int bs);
    void drawBlocks(int bs);
    void drawNextBlock(int bs);
    void drawHighScore();

    public:
    GraphicsDrawer(Game* game);
    std::ostream& print(std::ostream& out) override;
};

#endif
