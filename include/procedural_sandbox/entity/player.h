#ifndef PLAYER_H
#define PLAYER_H
#include <procedural_sandbox/entity/entity.h>
#include <procedural_sandbox/inventory/inventory.h>

using ProceduralSandbox::Inventory::Inventory;

namespace ProceduralSandbox::Entity {
    class Player: public Entity {
    public:
        Inventory::Inventory inventory;
    };
}
#endif