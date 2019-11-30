#include "level2.h"
#include <string>
#include <cstdlib>



Level2::Level2(int seed, std::string file, bool useRandom): 
        Level{seed, file, useRandom, 2, 0} {}

Level2::~Level2() {}



std::string Level2::spawnRandom() {
    int gen = rand() % 7;
    if (gen < 1) {
        return "S";

    } else if (gen < 2) {
        return "Z";

    } else if (gen < 3) {
        return "I";

    } else if (gen < 4) {
        return "J";

    } else if (gen < 5) {
        return "L";

    } else if (gen < 6) {
        return "O";

    } else {
        return "T";
    }
}
