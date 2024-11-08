#ifndef TILE_H
#define TILE_H
#include <stdint.h>
#include <vector>

namespace ProceduralSandbox::World {
    struct Tile {
        uint64_t id;
        uint64_t data;

        Tile();
    };
}
#endif