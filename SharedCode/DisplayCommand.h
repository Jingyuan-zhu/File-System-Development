#pragma once

#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"

class DisplayCommand : public AbstractCommand {

private:
	enum {success, failtoDisplay, nullpointer};
	AbstractFileSystem* fs;

public:
	DisplayCommand(AbstractFileSystem* fd);
	virtual int execute(std::string filename) override;
	virtual void displayInfo() override;
	virtual ~DisplayCommand() = default;
};