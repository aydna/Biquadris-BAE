#ifndef BLOCK_H
#define BLOCK_H
#include <vector>
#include <utility>

class Block{
    protected:
        std::vector<std::pair<int,int>> pixels;
    private:
        char color;
        int levelSpawned;
        int weight;

    public:
        Block(std::vector<std::pair<int,int>> pixels, char color, int levelSpawned, int weight);
        std::vector<std::pair<int,int>> getPixels();
        void setPixels(std::vector<std::pair<int,int>> newPixels);
        char getColor();
        int getLevelSpawned();
        int getWeight();
        void increaseWeight(int inc);
        virtual ~Block()=0;
};

#endif