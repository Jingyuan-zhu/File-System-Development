#include "CopyCommand.h"
#include "AbstractFileFactory.h"
#include <iostream>
#include <sstream>
#include <set>
using namespace std;


// constructor for the copy command
CopyCommand::CopyCommand(AbstractFileSystem* fs) : fs(fs) {}

// the information display function
void CopyCommand::displayInfo() {
	cout << "copy command will copy a file that exists in the file system and add the copy to the file system with a different name." << endl;
	cout << "It is invoked with the following command structure :cp <file_to_copy> < new_name_with_no_extension>" << endl;
}

int CopyCommand::execute(string filename) {

	// wrap the input string into istringstream
	istringstream iss(filename);
	string input;
	string newinput;

	iss >> input;
	iss >> newinput;

	// first, check if the file already exists
	set<string> fileset;
	fileset = fs->getFileNames();
	if (fileset.find(input) == fileset.end()) {
		cout << "file does not exist" << endl;
		return fileDNE;
	}

	// next, check if the new file name already exists
	string newinputname = newinput + input.substr(input.find('.'), string::npos);
	if (fileset.find(newinputname) != fileset.end()) {
		cout << "file name repeats!" << endl;
		return failtoCopy;
	}

	// create the copy file
	AbstractFile* file = fs->openFile(input);
	AbstractFile* copy = file->clone(newinputname);
	fs->closeFile(file);
	return fs->addFile(copy->getName(), copy);


}