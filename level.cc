#include <string>
#include "level.h"

Level::Level(std::string file, bool useRandom): 
        sequenceFile{file}, useRandom{useRandom} {}

Level::~Level() {}

