#include "level0.h"
#include <string>

Level0::Level0(int seed, std::string file, bool useRandom): 
        Level{seed, file, useRandom} {}

Level0::~Level0() {}

// lol
std::string Level0::spawnRandom() {
    return spawnNorandom();
}

