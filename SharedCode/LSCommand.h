#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class LSCommand : public AbstractCommand {
public:
	LSCommand(AbstractFileSystem* file_system);
	virtual int execute(string input);
	virtual void displayInfo();
private:
	AbstractFileSystem* file_system;
	enum { success, wrong_argument_number };
};