#include "level3.h"
#include <string>
#include <cstdlib>



Level3::Level3(int seed, std::string file, bool useRandom): 
        Level{seed, file, useRandom, 3, 1} {}   // note levels 3+ have weight 1

Level3::~Level3() {}


// random block generation
std::string Level3::spawnRandom() {
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
