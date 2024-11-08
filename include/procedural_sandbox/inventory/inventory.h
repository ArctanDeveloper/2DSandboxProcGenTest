#ifndef INVENTORY_H
#define INVENTORY_H
#include <procedural_sandbox/inventory/item.h>
#include <vector>

namespace ProceduralSandbox::Inventory {
    struct Inventory {
        std::vector<Item> items;
    };
}
#endif