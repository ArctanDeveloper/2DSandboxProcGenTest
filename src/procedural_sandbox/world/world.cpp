#include <procedural_sandbox/world/world.h>
#include <algorithm>

using namespace ProceduralSandbox::World;

Chunk World::GetChunk(int x, int y) {
    return GetChunk(Vec2i(x, y));
}

Chunk World::GetChunk(Vec2i position) {
    if (chunks.find(position) == chunks.end()) {
        chunks[position] = Chunk();
    }
    return chunks[position];
}

Tile World::GetTile(int x, int y) {
    return GetTile(Vec2i(x, y));
}

Tile World::GetTile(Vec2i position) {
    Vec2i chunkPos = position / Chunk::CHUNK_SIZE;
    Vec2i tilePos = position % Chunk::CHUNK_SIZE;

    return GetChunk(chunkPos).GetTile(tilePos);
}

World::World() {
    for (int i = 0; i < World::TILE_TYPES; i++) {
        TileTypes.push_back(std::make_unique<TileType>());

        TileType* tileType = TileTypes.back().get();
        tileType->name = "Tile " + i;
    }

    for (int i = 0; i < World::ITEM_TYPES; i++) {
        ItemTypes.push_back(std::make_unique<ItemType>());

        ItemType* itemType = ItemTypes.back().get();
        itemType->name = "Item " + i;
    }

    for (int i = 0; i < World::RECIPE_TYPES; i++) {
        Recipes.push_back(std::make_unique<Recipe>());

        Recipe* recipe = Recipes.back().get();
    }
}