#include "PasswordProxy.h"
#include <iostream>

using namespace std;

// constructor 
PasswordProxy::PasswordProxy(AbstractFile* file, std::string password) : file(file), password(password) {}

// destructor
PasswordProxy::~PasswordProxy() {
	delete file;
}


string PasswordProxy::passwordPrompt() {
	cout << "Enter Password: " << endl;
	string pass;
	getline(cin, pass);
	return pass;
}

bool PasswordProxy::passwordMatch(string s) {
	if (s.compare(password)== 0) {
		return true;
	}
	return false;
}

vector<char> PasswordProxy::read() {
	if (passwordMatch(passwordPrompt())) {
		return file->read();
	}

	else {
	//return an emptry vector
		vector<char> empty;
		return empty;
	}
}

int PasswordProxy::write(vector<char> v) {
	if (passwordMatch(passwordPrompt())) {
		return file->write(v); // call write on the actual file 
	}
	else {
		return wrongPassword;
	}
}

int PasswordProxy::append(vector<char> v) {
	if (passwordMatch(passwordPrompt())) {
		return file->append(v); // call append on the actual file 
	}
	else {
		return wrongPassword;
	}

}

string PasswordProxy::getName() {
	return file->getName();
}

unsigned int PasswordProxy::getSize() {
	return file->getSize();
}

void PasswordProxy::accept(AbstractFileVisitor* visitor) {
	if (passwordMatch(passwordPrompt())) {
		file->accept(visitor);
	}
}

AbstractFile* PasswordProxy::clone(string newname) {

		
		AbstractFile* newFile = file->clone(newname);
		AbstractFile* cloneFile = new PasswordProxy(newFile, password);

		return cloneFile;
	
}
