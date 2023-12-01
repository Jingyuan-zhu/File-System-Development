#include "CommandPrompt.h"
#include <iostream>
#include <sstream> 

using namespace std;

//default constructor
CommandPrompt::CommandPrompt() : fs(nullptr), ff(nullptr) {}

void CommandPrompt::setFileSystem(AbstractFileSystem* filesystem) {
	this->fs = filesystem;
}

void CommandPrompt::setFileFactory(AbstractFileFactory* factory) {
	this->ff = factory;
}
int CommandPrompt::addCommand(string str, AbstractCommand* command) {
	auto insertion = commands.insert({ str,command });
	if (insertion.second) {
		return success;
	}
	else {
		return failToInsert;
	}
}

void CommandPrompt::listCommands() {
	for (auto it = commands.begin(); it != commands.end(); it++) {
		cout << it->first << endl;
	}
	
}

string CommandPrompt::prompt() {
	cout << "Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command." << endl;
	cout << "$  " << flush;
	string store;
	getline(cin, store);
	return store;
}

int CommandPrompt::run() {
	string input = prompt();

	if (input == "q") {
		return quit;
	}
	if (input == "help") {
		listCommands();
		return help;
	}

	//check to see if one word
	bool oneword = true;
	for (unsigned int i = 0; i < input.size(); ++i) {
		if (input[i] == ' ') {
			oneword = false;
		}
	}

	if (oneword) {
		auto mapcommands = commands.find(input);
		if (mapcommands != commands.end()) {
			int executeReturn = mapcommands->second->execute(""); // this returns the execution's fail or success
			if (executeReturn == success) {
				return commandSuccess;
			}
			else {
				cout << "Error: the command fails to execute" << endl;
			}
		}
		else {
			cout << "command does not exist" << endl;
			return commandDNE;
		}
	}

	// if more than one word exists

	//using istringstream to extract input
	istringstream iss;
	iss.str(input);

	string firstWord;
	iss >> firstWord;

	//if first word is help
	if (firstWord.compare("help") == 0) {
		string secondWord;
		iss >> secondWord;

		auto it= commands.find(secondWord);
		if (it != commands.end()) {
			it->second->displayInfo();
			return commandSuccess;
		}
		cout << "Command doesn't exist" << endl;
		return commandDNE;
	}

	//the situation where first word is not help

	string body= input.substr(input.find(' ') + 1, string::npos); // this extracts the string from the first space to the end

	auto execution = commands.find(firstWord);
	if (execution != commands.end()) {
		int executeReturn = execution->second->execute(body); //return execute's success or fail
		if (executeReturn == success) {
			return commandSuccess;
		}
		else {
			cout << "command fails to execute" << endl;
		}
	}
	cout << "The command dose not exist" << endl;
	return commandDNE;

}
