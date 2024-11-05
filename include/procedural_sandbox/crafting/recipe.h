#ifndef RECIPE_H
#define RECIPE_H
#include <procedural_sandbox/crafting/ingredient.h>
#include <vector>

namespace ProceduralSandbox::Crafting {
    struct Recipe {
        std::vector<Ingredient> inputs;
        std::vector<Ingredient> outputs;
    };
}
#endif