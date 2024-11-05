#ifndef TILE_TYPE_H
#define TILE_TYPE_H
#include <stdint.h>
#include <vector>
#include <string>
#include <memory>
#include <procedural_sandbox/world/tile.h>

namespace ProceduralSandbox::World {
    struct TileType {
        std::string name;
    };
}
#endif