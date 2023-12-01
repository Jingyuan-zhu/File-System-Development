#pragma once
#include "../SharedCode/AbstractFileSystem.h"
#include "../SharedCode/AbstractFileFactory.h"
#include "../SharedCode/AbstractCommand.h"
#include <map>

//The command prompt handles user input / output
// he command prompt will be configured with concrete commands and will invoke them when requested by the user

class CommandPrompt {

private:
	enum results {success, failToInsert, quit=10, help, commandDNE, commandSuccess};
	std::map<std::string, AbstractCommand*> commands; //This map will store the command objects the CommandPrompt is configured with
	AbstractFileSystem* fs; // store the file system object the command prompt is configured with
	AbstractFileFactory* ff;// store the file factory object the command prompt is configured with

public:
	CommandPrompt(); // default constructor
	void setFileSystem(AbstractFileSystem*); // sets the AbstractFileSystem pointer member variable equal to the parameter passed to this method
	void setFileFactory(AbstractFileFactory*); // sets the AbstractFileFactory pointer member variable equal to the parameter passed to this method
	int addCommand(std::string, AbstractCommand*); // inserts the parameters passed to this function as a pair into the map of commands, return success if the insertion was successful, returns a non zero value otherwise
	int run();

protected:
	void listCommands();
	std::string prompt();
};