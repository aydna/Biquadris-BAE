#include "level4.h"
#include <string>
#include <cstdlib>



Level4::Level4(int seed, std::string file, bool useRandom): 
        Level{seed, file, useRandom, 4, 1} {}

Level4::~Level4() {}

std::string Level4::spawnRandom() {
    int gen = rand() % 9;
    if (gen < 2) {
        return "S";

    } else if (gen < 4) {
        return "Z";

    } else if (gen < 5) {
        return "I";

    } else if (gen < 6) {
        return "J";

    } else if (gen < 7) {
        return "L";

    } else if (gen < 8) {
        return "O";

    } else {
        return "T";
    }
}
