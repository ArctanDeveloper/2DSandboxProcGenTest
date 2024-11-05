#include <procedural_sandbox/world/world.h>
#include <procedural_sandbox/entity/player.h>
#include <random>
#include <fast_noise_lite/FastNoiseLite.h>
#include <sago/platform_folders.h>
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>

using ProceduralSandbox::World::World;

int main() {
    FastNoiseLite noise = FastNoiseLite();

    #pragma region Directories
    std::string dataDirectory = sago::getDataHome() + "/ProceduralSandbox/";
    std::string saveDirectory = sago::getSaveGamesFolder1() + "/ProceduralSandbox/";

    if (!std::filesystem::exists(dataDirectory)) {
        std::filesystem::create_directories(dataDirectory);
    }

    if (!std::filesystem::exists(saveDirectory)) {
        std::filesystem::create_directories(saveDirectory);
    }
    #pragma endregion

    bool quit = false;
    std::string line;

    World world;

    while (!quit) {
        std::getline(std::cin, line);

        if (line == "quit") {
            quit = true;
        } else if (line == "new") {
            world = World();
        }
    }

    std::cout << "Finished running." << std::endl;
    return 0;
}