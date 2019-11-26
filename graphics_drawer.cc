#include <vector>
#include <utility>
#include <memory>
#include <iostream>
#include <map>
#include "window.h"
#include "drawer.h"
#include "graphics_drawer.h"

GraphicsDrawer::GraphicsDrawer(Game* game): Drawer::Drawer{game}{
    colors['I'] = Xwindow::Cyan;
    colors['J'] = Xwindow::Blue;
    colors['L'] = Xwindow::Orange;
    colors['O'] = Xwindow::Yellow;
    colors['S'] = Xwindow::Green;
    colors['Z'] = Xwindow::Red;
    colors['T'] = Xwindow::Magenta;
    colors['*'] = Xwindow::Brown;

    drawBoxes(30);
}

void GraphicsDrawer::drawBoxes(int bs){
    w.drawLine(200-1,150-1,200-1,150+bs*18-1);
    w.drawLine(200+bs*11+1,150-1,200+bs*11+1,150+bs*18-1);
    w.drawLine(200-1,150-1,200+bs*11+1,150-1);
    w.drawLine(200-1,150+bs*18-1,200+bs*11+1,150+bs*18-1);

    w.drawLine(700-1,150-1,700-1,150+bs*18-1);
    w.drawLine(700+bs*11+1,150-1,700+bs*11+1,150+bs*18-1);
    w.drawLine(700-1,150-1,700+bs*11+1,150-1);
    w.drawLine(700-1,150+bs*18-1,700+bs*11+1,150+bs*18-1);
}

void GraphicsDrawer::drawBlocks(int bs){
    //super slow, draws too many rectangles? 
    for (int row = 0; row < p1.boardSize.first; row++){
        for (int col = 0; col < p1.boardSize.second; col++) {
            if ((p1.grid[row][col] != ' ') && (p1.grid[row][col] != p1.oldGrid[row][col])){
                w.fillRectangle(200 + (col * bs), 150 + (row * bs), bs, bs, colors[p1.grid[row][col]]);
            }           
            if ((p2.grid[row][col] != ' ') && (p2.grid[row][col] != p2.oldGrid[row][col])){
                w.fillRectangle(700 + (col * bs), 150 + (row * bs), bs, bs, colors[p2.grid[row][col]]);
            }
        }
    }
}

void GraphicsDrawer::drawHeaders(int bs){
    //fuck
}

std::ostream& GraphicsDrawer::print(std::ostream& out){
    int bs = 30;
    drawBoxes(bs);
    drawHeaders(bs);
    drawBlocks(bs);
}