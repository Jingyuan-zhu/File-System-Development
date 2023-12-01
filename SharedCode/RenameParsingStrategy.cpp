#include "RenameParsingStrategy.h"
#include <iostream>
#include <sstream>

// Tells the user how to invoke the rename command and describes the command.
void RenameParsingStrategy::displayInfo() {
	cout << "rn renames a file, rn can be invoked with command: rn <existing_file> <new_name_with_no_extension>" << endl;
}

// rn renames a file
vector<string> RenameParsingStrategy::parse(string parse_input) {
	string existing_file;
	string new_file;
	istringstream iss(parse_input);
	iss >> existing_file;
	iss >> new_file;
	vector<string> parse_output;
	parse_output.push_back(parse_input);
	parse_output.push_back(existing_file);
	return parse_output;
}