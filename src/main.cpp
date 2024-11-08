#include <procedural_sandbox/world/world.h>
#include <procedural_sandbox/entity/player.h>
#include <random>
#include <fast_noise_lite/FastNoiseLite.h>
#include <sago/platform_folders.h>
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <stack>
#include <procedural_sandbox/command/command.h>
#include <procedural_sandbox/command/command_handler.h>

using ProceduralSandbox::World::World;
using ProceduralSandbox::Entity::Player;
using ProceduralSandbox::Command::Command;
using ProceduralSandbox::Command::CommandHandler;
using ProceduralSandbox::Command::Parameter;
using ProceduralSandbox::Command::ParameterType;

enum ScreenType {
    MainMenu,
    Game,
    Inventory,
    Crafting,
    InspectionLog,
    ItemInspectionLog,
    TileInspectionLog,
    RecipeInspectionLog
};

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

    std::stack<ScreenType> screenStack;
    screenStack.push(MainMenu);

    World world;
    Player player;

    #pragma region Commands
    CommandHandler commandHandler = CommandHandler();
    commandHandler.AddCommand(Command("quit", "Quits the server.", [&](const CommandHandler& handler, const std::vector<Parameter>& parameters) {
        quit = true;
    }), {});

    commandHandler.AddCommand(Command("help", [&](const CommandHandler& handler, const std::vector<Parameter>& parameters) {
        std::cout << "Available commands:" << std::endl;
        for (Command command : handler.commands) {
            std::cout << "\t" << command.name << ": " << command.description << std::endl;
        }
    }), {});

    commandHandler.AddCommand(Command("back", [&](const CommandHandler& handler, const std::vector<Parameter>& parameters) {
        switch (screenStack.top()) {
            case ScreenType::Inventory:
            case ScreenType::Crafting:
            case ScreenType::InspectionLog:
            case ScreenType::ItemInspectionLog:
            case ScreenType::TileInspectionLog:
            case ScreenType::RecipeInspectionLog:
                screenStack.pop();
                break;
            default:
                std::cout << "Not a valid command for this screen." << std::endl;
                break;
        }
    }), {});

    commandHandler.AddCommand(Command("new", [&](const CommandHandler& handler, const std::vector<Parameter>& parameters) {
        switch (screenStack.top()) {
            case ScreenType::MainMenu:
                world = World();
                screenStack.push(ScreenType::Game);
                break;
            default:
                std::cout << "Not a valid command for this screen." << std::endl;
                break;
        }
    }), {});
    
    commandHandler.AddCommand(Command("open_inspection_log", [&](const CommandHandler& handler, const std::vector<Parameter>& parameters) {
        switch (screenStack.top()) {
            case ScreenType::Game:
                screenStack.push(ScreenType::InspectionLog);
                break;
            default:
                std::cout << "Not a valid command for this screen." << std::endl;
                break;
        }
    }), {});
    
    commandHandler.AddCommand(Command("open_inventory", [&](const CommandHandler& handler, const std::vector<Parameter>& parameters) {
        switch (screenStack.top()) {
            case ScreenType::Game:
                screenStack.push(ScreenType::Inventory);
                break;
            default:
                std::cout << "Not a valid command for this screen." << std::endl;
                break;
        }
    }), {});

    commandHandler.AddCommand(Command("open_crafting", [&](const CommandHandler& handler, const std::vector<Parameter>& parameters) {
        switch (screenStack.top()) {
            case ScreenType::Game:
                screenStack.push(ScreenType::Crafting);
                break;
            default:
                std::cout << "Not a valid command for this screen." << std::endl;
                break;
        }
    }), {});

    commandHandler.AddCommand(Command("open_item_log", [&](const CommandHandler& handler, const std::vector<Parameter>& parameters) {
        switch (screenStack.top()) {
            case ScreenType::InspectionLog:
                screenStack.push(ScreenType::ItemInspectionLog);
                    
                for (int i = 0; i < world.ItemTypes.size(); i++) {
                    std::cout << std::to_string(i) << " - " << world.ItemTypes[i]->name << std::endl;
                }
                break;
            default:
                std::cout << "Not a valid command for this screen." << std::endl;
                break;
        }
    }), {});

    commandHandler.AddCommand(Command("open_tile_log", [&](const CommandHandler& handler, const std::vector<Parameter>& parameters) {
        switch (screenStack.top()) {
            case ScreenType::InspectionLog:
                screenStack.push(ScreenType::TileInspectionLog);
                
                for (int i = 0; i < world.TileTypes.size(); i++) {
                    std::cout << std::to_string(i) << " - " << world.TileTypes[i]->name << std::endl;
                }
                break;
            default:
                std::cout << "Not a valid command for this screen." << std::endl;
                break;
        }
    }), {});

    commandHandler.AddCommand(Command("open_recipe_log", [&](const CommandHandler& handler, const std::vector<Parameter>& parameters) {
        switch (screenStack.top()) {
            case ScreenType::InspectionLog:
                screenStack.push(ScreenType::RecipeInspectionLog);
                    
                for (int i = 0; i < world.Recipes.size(); i++) {
                    std::cout << std::to_string(i) << " - " << std::endl;
                }
                break;
            default:
                std::cout << "Not a valid command for this screen." << std::endl;
                break;
        }
    }), {});

    //commandHandler.AddCommand(Command("", [&](const CommandHandler& handler, const std::vector<Parameter>& parameters) {}), {});
    #pragma endregion

    std::cout << "Begining running." << std::endl;

    while (!quit) {
        std::getline(std::cin, line);

        // Process the command
        // Trim leading and trailing whitespace
        line = line.substr(line.find_first_not_of(" \t\r\n"));
        if (line.length() == 0) {
            continue;
        }
        line = line.substr(0, line.find_last_not_of(" \t\r\n") + 1);

        // Split the command by whitespace
        std::vector<Parameter> tokens;
        std::string token;
        std::istringstream tokenStream(line);
        Command::Tokenize(tokenStream, tokens);

        // Process the initializer
        std::string initializer = std::get<std::string>(tokens[0]);
        tokens.erase(tokens.begin());

        commandHandler.ExecuteCommand(initializer, tokens);

        if (line == "quit_game") {
            quit = true;
        }
    }

    std::cout << "Finished running." << std::endl;
    return 0;
}