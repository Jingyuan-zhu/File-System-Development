#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class CopyCommand : public AbstractCommand {
	
private:	
	AbstractFileSystem* fs;
	enum {success, fileDNE, failtoCopy};

public:
	CopyCommand(AbstractFileSystem* fs);
	virtual int execute(std::string s) override;
	virtual void displayInfo() override;
	virtual ~CopyCommand() = default;
};