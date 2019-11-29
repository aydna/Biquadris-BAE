#include "level1.h"
#include <string>
#include <cstdlib>



Level1::Level1(int seed, std::string file, bool useRandom): 
        Level{seed, file, useRandom, 1, 0} {}

Level1::~Level1() {}



std::string Level1::spawnRandom() {
    int gen = rand() % 12;
    if (gen < 1) {
        return "S";

    } else if (gen < 2) {
        return "Z";

    } else if (gen < 4) {
        return "I";

    } else if (gen < 6) {
        return "J";

    } else if (gen < 8) {
        return "L";

    } else if (gen < 10) {
        return "O";

    } else {
        return "T";
    }
}
