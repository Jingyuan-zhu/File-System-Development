#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "AbstractParsingStrategy.h"

class MacroCommand : public AbstractCommand {
public:
	MacroCommand(AbstractFileSystem* file_system);
	virtual int execute(string input) override;
	virtual void displayInfo() override;
	void addCommand(AbstractCommand* command);
	void setParseStrategy(AbstractParsingStrategy* parser);
private:
	AbstractFileSystem* file_system;
	vector<AbstractCommand*> macrocommands;
	AbstractParsingStrategy* parser;
	enum { success, null_parser };
};
