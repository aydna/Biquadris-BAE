#ifndef BLOCK_DIAG_H
#define BLOCK_DIAG_H
#include "block.h"

class BlockDiag: public Block{
    public:
        BlockDiag(int levelSpawned, int weight);
};

#endif
