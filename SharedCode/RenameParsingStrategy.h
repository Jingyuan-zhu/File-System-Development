#pragma once
#include "AbstractParsingStrategy.h"

class RenameParsingStrategy : public AbstractParsingStrategy {
public:
	virtual std::vector<string> parse(std::string parse_input) override;
	virtual void displayInfo() override;
};