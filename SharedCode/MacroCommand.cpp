#include "MacroCommand.h"
#include <iostream>

// Constructer
MacroCommand::MacroCommand(AbstractFileSystem* file_system) : file_system(file_system), parser(nullptr) {}

// Tells the user how to invoke the macrocommand and describes the command.
void MacroCommand::displayInfo() {
    cout << "Macrocommand allows us to construct commands out of other commands, " << endl;
    if (parser != nullptr) {
        parser->displayInfo();
    }
    else {
        cout << "no macrocommands exist" << endl;
    }
}

// Macrocommand allows us to construct commands out of other commands
int MacroCommand::execute(string input) {
    int result = success;
    if (parser == nullptr) {   // If parser is a nullptr, returns a nonzero value indicating error.
        result = null_parser;
        return result;
    }
    // Initialize our parser
    vector<string> command_arguments = parser->parse(input);
    if (command_arguments.size() == macrocommands.size()) {
        for (int i = 0; i < command_arguments.size(); ++i) {
            int sub_command_result = macrocommands[i]->execute(command_arguments[i]); // parse through subcommands
            if (sub_command_result != success) {
                cout << "Subcommand failed" << endl;
                return result = sub_command_result;
            }
        }
    }
    return result;
}

void MacroCommand::addCommand(AbstractCommand* command) {
    macrocommands.push_back(command);
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* strategy)
{
    this->parser = strategy;
}