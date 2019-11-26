#include "level.h"

Level::Level(int seed, std::string file, bool useRandom):
    seed{seed}, sequenceFile{file}, useRandom{useRandom} {}


Level::~Level(){}