#include <procedural_sandbox/command/command_handler.h>

using namespace ProceduralSandbox::Command;

void CommandHandler::AddCommand(Command command, std::vector<ParameterValue> parameters) {
    commands.push_back(command);

    for (ParameterValue parameter : parameters) {
        command.AddParameter(std::get<0>(parameter), std::get<1>(parameter));
    }
}

void CommandHandler::ExecuteCommand(std::string initializer, const std::vector<Parameter>& parameters) {
    for (Command command : commands) {
        if (command.IsValid(initializer, parameters)) {
            command.function(*this, parameters);
        }
    }
}