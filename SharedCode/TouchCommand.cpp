#include "TouchCommand.h"
#include "AbstractFile.h"
#include "PasswordProxy.h"
#include <iostream>
#include <sstream>

using namespace std;

// Constructor
TouchCommand::TouchCommand(AbstractFileSystem* fs, AbstractFileFactory* ff ) : ff(ff), fs(fs) {}

// Tells the user how to invoke the touch command and describes the command.
void TouchCommand::displayInfo() {
	cout << "“touch creates a file, touch can be invoked with the command : touch <filename>" << endl;
}

// Ask the file factory to create a file with the provided filename.
int TouchCommand::execute(string fileName) {
	
	// use istringstream to parse the input string
	string filename;
	string checkp;
	istringstream iss(fileName);
	iss >> filename;
	iss >> checkp;


	// the case where the password is needed 
	if (checkp == "-p") {
	// now prompt the use to input password and get the password
		cout << "What is the passowrd?" << endl;
		string password;
		getline(cin, password);
		AbstractFile* file = ff->createFile(filename);
		PasswordProxy* p = new PasswordProxy(file, password);
		int result = fs->addFile(filename, p);
		if (file == nullptr) {    // fail to create file
			delete file;
			cout << "fail to create file" << endl;
			return failtocreatefile;
		}
		else if (result != success) {
			cout << "fail to add the file" << endl;
			return failtoadd;
		}
		if (result == success) {
			cout << "Successfully added the file" << endl;
			return result;
		}
	}
	else {
		// create the file without password 
		AbstractFile* file = ff->createFile(fileName);
		int result = fs->addFile(fileName, file);
		if (file == nullptr) {    // fail to create file
			delete file;
			cout << "fail to create file" << endl;
			return failtocreatefile;
		}
		else if (result != success) {
			cout << "fail to add the file" << endl;
			return failtoadd;
		}
		if (result == success) {
			cout << "Successfully added the file" << endl;
			return result;
		}
	}
	/*if (file == nullptr) {
		delete file;
		cout << "fail to create file" << endl;
		return failtocreatefile;
	}

	else {
		if (fs->addFile(fileName,file)) {
			return success;
		}
		else {
			return failtoadd;
		}
	}*/
}