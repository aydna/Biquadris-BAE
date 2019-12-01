#ifndef BOARD_H
#define BOARD_H

class Board{
    /*
    int level;
    int seed;
    std::string file;
    int score;
    std::vector<std::unique_ptr<Block>> blocks;
    std::unique_ptr<Block> nextBlock;
    std::unique_ptr<Level> currLevel;
    bool gameOverSwitch;
    */

    public:
        virtual void spawnBlock();
        virtual ~Board();
};

#endif