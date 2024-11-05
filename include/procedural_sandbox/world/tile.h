#ifndef TILE_H
#define TILE_H
#include <stdint.h>
#include <vector>

namespace ProceduralSandbox::World {
    struct Tile {
        uint32_t id;
        uint64_t data;

        Tile();
    };
}
#endif