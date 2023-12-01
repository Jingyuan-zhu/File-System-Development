#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class CatCommand : public AbstractCommand {
public:
	CatCommand(AbstractFileSystem* file_system);
	virtual int execute(string input);
	virtual void displayInfo();
private:
	AbstractFileSystem* file_system;
	enum { success, wrong_argument_number, cannot_open_file, save };
};
