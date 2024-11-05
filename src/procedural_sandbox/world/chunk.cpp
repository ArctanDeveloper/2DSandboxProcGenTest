#include <procedural_sandbox/world/chunk.h>

using namespace ProceduralSandbox::World;

Tile Chunk::GetTile(int x, int y) {
    return tiles[y * CHUNK_SIZE + x];
}

Tile Chunk::GetTile(Vec2i position) {
    return GetTile(position.x, position.y);
}