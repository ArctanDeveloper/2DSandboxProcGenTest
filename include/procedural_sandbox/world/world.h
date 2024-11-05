#ifndef WORLD_H
#define WORLD_H
#include <procedural_sandbox/world/chunk.h>
#include <unordered_map>
#include <procedural_sandbox/util/vec.h>
#include <procedural_sandbox/world/tile_type.h>
#include <procedural_sandbox/inventory/item_type.h>
#include <procedural_sandbox/crafting/recipe.h>

using ProceduralSandbox::Util::Vec2i;
using ProceduralSandbox::World::Chunk;
using ProceduralSandbox::Inventory::ItemType;
using ProceduralSandbox::Crafting::Recipe;

namespace ProceduralSandbox::World {
    class World {
    public:
        const static int TILE_TYPES = 5;
        const static int ITEM_TYPES = 5;
        const static int RECIPE_TYPES = 5;

        std::vector<std::unique_ptr<TileType>> TileTypes;
        std::vector<std::unique_ptr<ItemType>> ItemTypes;
        std::vector<std::unique_ptr<Recipe>> Recipes;

        Chunk GetChunk(int x, int y);
        Chunk GetChunk(Vec2i position);
        Tile GetTile(int x, int y);
        Tile GetTile(Vec2i position);

        World();
    private:
        std::unordered_map<Vec2i, Chunk, Vec2i::Hash> chunks;
    };
}
#endif