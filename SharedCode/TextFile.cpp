//  Define the TextFile class here

#include "AbstractFile.h"
#include "TextFile.h"
#include "AbstractFileVisitor.h"
#include <iostream>

using namespace std;
TextFile::TextFile(string s) : name(s) {};

unsigned int TextFile::getSize() {
	return static_cast<unsigned int>(contents.size());
}

string TextFile::getName() {
	return name;
}

int TextFile::write(vector<char> copy) {
	/*for (size_t i = 0; i < data.size(); ++i) {
		contents[i] = data[i];
	}*/
	contents = copy;
	return 0;
}

int TextFile::append(vector<char> copy) {
	for (size_t i = 0; i < copy.size() ; ++i)
		contents.push_back(copy[i]);
	return 0;
}

vector<char> TextFile ::read() {
	return contents;
}


void TextFile::accept(AbstractFileVisitor* v) {
	v->visitTextFile(this);
}

//copy command

AbstractFile* TextFile::clone(string newname) {
	AbstractFile* cloneFile = new TextFile(newname);
	cloneFile->write(this->read());

	return cloneFile;
}


