#ifndef CHUNK_H
#define CHUNK_H
#include <procedural_sandbox/world/tile.h>
#include <procedural_sandbox/util/vec.h>
#include <array>
#include <vector>

using ProceduralSandbox::World::Tile;
using ProceduralSandbox::Util::Vec2i;

namespace ProceduralSandbox::World {
    struct Chunk {
        const static uint16_t CHUNK_SIZE = 128;
        const static uint64_t CHUNK_SIZE_SQUARED = CHUNK_SIZE * CHUNK_SIZE;

        std::array<Tile, CHUNK_SIZE_SQUARED> tiles;

        Tile GetTile(int x, int y);
        Tile GetTile(Vec2i position);
    };
}
#endif