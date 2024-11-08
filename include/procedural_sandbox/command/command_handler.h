#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H
namespace ProceduralSandbox::Command {
    class CommandHandler;
}
#include <procedural_sandbox/command/command.h>
#include <vector>
#include <string>

namespace ProceduralSandbox::Command {
    /**
     * @class CommandHandler
     * @brief Manages the addition and execution of commands.
     *
     * CommandHandler provides functionality to register commands and execute them by name,
     * handling associated parameters and executing the corresponding function.
     */
    class CommandHandler {
    public:
        std::vector<Command> commands; ///< A collection of available commands.

        /**
         * @brief Adds a new command to the CommandHandler.
         * @param command The command to add, including its name, description, parameters, and function.
         * @param parameters The parameters of the command.
         */
        void AddCommand(Command command, std::vector<ParameterValue> parameters);

        /**
         * @brief Executes a command based on its name and parameters.
         * @param initializer The name of the command to execute.
         * @param parameters The parameters to pass to the command's function.
         *
         * Searches for the command by name and, if found, executes the command's function
         * with the provided parameters.
         */
        void ExecuteCommand(std::string initializer, const std::vector<Parameter>& parameters);
    };
}
#endif