#ifndef INGREDIENT_H
#define INGREDIENT_H
#include <stdint.h>

namespace ProceduralSandbox::Crafting {
    struct Ingredient {
        uint32_t count;
        uint32_t item;
    };
}
#endif