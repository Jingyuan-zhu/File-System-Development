#include "DisplayCommand.h"
#include "AbstractFileFactory.h"
#include "BasicDisplayVisitor.h"
#include <iostream>
#include <sstream>
#include <set>
using namespace std;

// constructor 

DisplayCommand::DisplayCommand(AbstractFileSystem* fs) : fs(fs) { }

//  displays the information about the ds command 
void DisplayCommand::displayInfo() {
	cout << "ds command displays the content of the given input file. The format is ds <filename> [-d]" << endl;
}


int DisplayCommand::execute(string input) {

	// wrap the input into a istringstream
	istringstream iss(input);
	string filename;
	string checkd;

	iss >> filename;
	iss >> checkd;

	// now check if the file actually exists
	set<string> fileset = fs-> getFileNames();
	if (fileset.find(filename) == fileset.end()) {
		cout << "The file does not exist" << endl;
	 return failtoDisplay;
	}

	AbstractFile* file = fs->openFile(filename);

	if (file == nullptr) {
		return nullpointer;
	}

	// now check -d to decide the display format
	else if (checkd == "-d") {
		vector<char> contents = file->read();
		for (unsigned int i = 0; i < contents.size(); i++) {
			cout << contents[i];
		}
		cout << endl;
		fs->closeFile(file);
		return success;

	}

	else { // use the visitor to show the formated display

		AbstractFileVisitor* visitor = new BasicDisplayVisitor();
		file->accept(visitor);
		fs->closeFile(file);
		return success;
	}


}
