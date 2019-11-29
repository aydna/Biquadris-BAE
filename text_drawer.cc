
#include "drawer.h"
#include "text_drawer.h"


TextDrawer::TextDrawer(Game* game): Drawer{game}{}

std::ostream& TextDrawer::print(std::ostream& out){
    out << std::endl << std::endl;
    out << " Level:    " << p1.level << "      "; // 6 spaces between the boards
    out << "Level:    " << p2.level << std::endl;
    out << " Score:    " << p1.score << "      ";
    out << "Score:    " << p2.score << std::endl;
    out << " -----------      -----------" << std::endl;

    for (int row = 0; row < p1.boardSize.first; row++) {
        out << "|";
        for (int col = 0; col < p1.boardSize.second; col++) {
            out << p1.grid[row][col];
        }
        out << "|    |";
        for (int col = 0; col < p2.boardSize.second; col++) {
            out << p2.grid[row][col];
        }
        out << "|";
        out << std::endl;
    }
    out << " -----------      -----------" << std::endl;
    out << "Next:            Next:" << std::endl;
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            out << p1.nextBlock[row][col];
        }
        out << "            ";
        for (int col = 0; col < 4; col++) {
            out << p2.nextBlock[row][col];
        }
        out << std::endl;
    }
    return out;
}