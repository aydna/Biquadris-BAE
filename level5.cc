#include "level5.h"
#include <string>
#include <cstdlib>



Level5::Level5(int seed, std::string file, bool useRandom): 
        Level{seed, file, useRandom, 5, 1} {}

Level5::~Level5() {}



std::string Level5::spawnRandom() {
    int gen = rand() % 11;
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

    } else if (gen < 7) {
        return "T";

    } else if (gen < 8) {
        return "X";

    } else if (gen < 9) {
        return "diag";

    } else if (gen < 10) {
        return "branch";

    } else {
        return "doughnut";

    }
}
