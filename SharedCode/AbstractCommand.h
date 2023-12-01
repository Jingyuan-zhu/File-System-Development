#pragma once

#include <string>

class AbstractCommand {
public :
	virtual int execute(std::string) = 0; // this function will hold any information that is passed to the command
	virtual void displayInfo() = 0; //a usage message for the command, it will display to the user how the command should be invoked
	virtual ~AbstractCommand() = default; 
};