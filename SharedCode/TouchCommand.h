#pragma once
#include "../SharedCode/AbstractCommand.h"
#include "../SharedCode/AbstractFileFactory.h"
#include "../SharedCode/AbstractFileSystem.h"

class TouchCommand : public AbstractCommand {
	AbstractFileSystem* fs;
	AbstractFileFactory* ff;

private:
	enum {success, failtoadd, failtocreatefile};


public:
	TouchCommand(AbstractFileSystem* fs, AbstractFileFactory*ff);
	virtual int execute(std::string fileName) override;
	virtual void displayInfo() override;
	virtual ~TouchCommand() = default;

};
