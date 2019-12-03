#include <vector>
#include <utility>
#include <memory>
#include <iostream>
#include <fstream>
#include <map>
#include "window.h"
#include "drawer.h"
#include "graphics_drawer.h"

GraphicsDrawer::GraphicsDrawer(Game* game): Drawer::Drawer{game}{
    colors['#'] = Xwindow::DarkGreen;
    colors['I'] = Xwindow::Cyan;
    colors['J'] = Xwindow::Blue;
    colors['L'] = Xwindow::Orange;
    colors['O'] = Xwindow::Yellow;
    colors['S'] = Xwindow::Green;
    colors['Z'] = Xwindow::Red;
    colors['T'] = Xwindow::Magenta;
    colors['*'] = Xwindow::Brown;
    colors['?'] = Xwindow::Black;

    drawBoxes(30);
}

void GraphicsDrawer::drawBoxes(int bs){
    //just draw a 4 sided polygon you fuck face
    w.drawLine(200-1,150-1,200-1,150+bs*18-1);
    w.drawLine(200+bs*11+1,150-1,200+bs*11+1,150+bs*18-1);
    w.drawLine(200-1,150-1,200+bs*11+1,150-1);
    w.drawLine(200-1,150+bs*18-1,200+bs*11+1,150+bs*18-1);

    w.drawLine(700-1,150-1,700-1,150+bs*18-1);
    w.drawLine(700+bs*11+1,150-1,700+bs*11+1,150+bs*18-1);
    w.drawLine(700-1,150-1,700+bs*11+1,150-1);
    w.drawLine(700-1,150+bs*18-1,700+bs*11+1,150+bs*18-1);
}

int color = 0;
void GraphicsDrawer::drawBlocks(int bs){
    //super slow, draws too many rectangles? 
    for (int row = 0; row < p1->boardSize.first; row++){
        for (int col = 0; col < p1->boardSize.second; col++) {
            if (p1->grid[row][col] != p1->oldGrid[row][col]){
                color = (p1->grid[row][col] == ' ') ? Xwindow::White : colors[p1->grid[row][col]];
                w.fillRectangle(200 + (col * bs), 150 + (row * bs), bs, bs, color);
            }          
            if (p2->grid[row][col] != p2->oldGrid[row][col]){
                color = (p2->grid[row][col] == ' ') ? Xwindow::White : colors[p2->grid[row][col]];
                w.fillRectangle(700 + (col * bs), 150 + (row * bs), bs, bs, color);
            }      
        }
    }
}

void GraphicsDrawer::drawNextBlock(int bs){
    w.drawString(50, 150, "Next:");
    w.drawString(550, 150, "Next:");
    for (int row = 0; row < 4; row++){
        for (int col = 0; col < 4; col++) {
            color = (p1->nextBlock[row][col] == ' ') ? Xwindow::White : colors[p1->nextBlock[row][col]];
            w.fillRectangle(50 + (col * bs), 200 + (row * bs), bs, bs, colors[p1->nextBlock[row][col]]);
            color = (p2->nextBlock[row][col] == ' ') ? Xwindow::White : colors[p2->nextBlock[row][col]];
            w.fillRectangle(550 + (col * bs), 200 + (row * bs), bs, bs, colors[p2->nextBlock[row][col]]);
        }
    }
}

void GraphicsDrawer::drawHeaders(int bs){
    w.fillRectangle(200, 50, 300, 50, Xwindow::White);
    w.fillRectangle(700, 50, 300, 50, Xwindow::White);
    w.drawString(200, 50,  "Player1 SCORE:  " + std::to_string(p1->score));
    w.drawString(200, 100, "Player1 LEVEL:  " + std::to_string(p1->level));
    w.drawString(700, 50,  "Player2 SCORE:  " + std::to_string(p2->score));
    w.drawString(700, 100, "Player2 LEVEL:  " + std::to_string(p2->level));
}


void GraphicsDrawer::drawHighScore(){
    std::ifstream highScores{"high_score.txt"};
    std::vector<int> scoreList;
    int num;
    while(highScores >> num) scoreList.emplace_back(num);
    highScores.close();
    int counter = 1;
    hs.drawString(20, 20,  "HIGH SCORE TABLE:");
    for (auto score : scoreList){
        hs.drawString(40, 20 + (counter) * 30, "HIGH SCORE " + std::to_string(counter) + ": " + std::to_string(score));
        counter++;
    }
}

std::ostream& GraphicsDrawer::print(std::ostream& out){
    int bs = 30;
    drawBoxes(bs);
    drawHeaders(bs);
    drawBlocks(bs);
    drawNextBlock(bs);
    drawHighScore();
    return out;
}
