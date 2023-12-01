#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class RemoveCommand : public AbstractCommand {
public:
	RemoveCommand(AbstractFileSystem* file_system);
	virtual int execute(string input);
	virtual void displayInfo();
private:
	AbstractFileSystem* file_system;
	enum { success, cannot_remove };
};
