#pragma once

#include <vector>
#include <string>

using namespace std;

class AbstractParsingStrategy {
public:
	virtual std::vector<string> parse(std::string parse_input) = 0;
	virtual void displayInfo() = 0;
}; 

