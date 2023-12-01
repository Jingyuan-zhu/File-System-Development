#pragma once
// TextFile declaration goes here

#include "AbstractFile.h"

class TextFile : public AbstractFile {

private:
	// member variables
	vector<char> contents;
	string name;

public:
	TextFile(string s);
	virtual vector<char> read() override;
	virtual int write(vector<char>) override;
	virtual int append(vector<char>) override;
	virtual unsigned int getSize() override;
	virtual string getName() override;

	//visitor pattern
	virtual void accept(AbstractFileVisitor*) override;

	//copy command
	virtual AbstractFile* clone(string newname) override;
};

//enum results {
//	Success
//};