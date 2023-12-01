#include "RemoveCommand.h"
#include <iostream>

// Constructer
RemoveCommand::RemoveCommand(AbstractFileSystem* file_system) : file_system(file_system) {}

// Tells the user how to invoke the remove command and describes the command.
void RemoveCommand::displayInfo() {
	cout << "Remove command removes a file from the file system by the file's name, remove can be invoked with the command: rm <filename>" << endl;
}

// Remove command removes a file from the file system by the file's name.
int RemoveCommand::execute(string input) {
	int result = success;
	result = file_system->deleteFile(input);
	return result;
}