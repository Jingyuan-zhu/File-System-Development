#pragma once
// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary

#include <string>
#include <vector>

using namespace std;

class AbstractFileVisitor; // forward declaration

// abstract file interface 
class AbstractFile {

public:
	enum results {success, cannotAppend, sizeMismatch, invalidPixle};
	virtual vector<char> read() = 0;
	virtual int write(vector<char>) = 0;
	virtual int append(vector<char>) = 0;
	virtual unsigned int getSize() = 0;
	virtual string getName() = 0;


	// destructor
	virtual ~AbstractFile() = default;

	//visitor pattern function
	virtual void accept(AbstractFileVisitor*) = 0;

	//copy command
	virtual AbstractFile* clone(string newname) = 0;
};
