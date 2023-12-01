#pragma once
// Image file class declaration here

#include "AbstractFile.h"

class ImageFile : public AbstractFile {
private:
	enum {success, cloneFile};
	string name;
	vector<char> contents;
	char size;
	// helper function
	size_t indexFunction(size_t x, size_t y);
	


public:
	ImageFile(string n);
	virtual unsigned int getSize() override;
	virtual string getName() override;
	virtual int append(vector<char>) override;
	virtual int write(vector<char>) override;
	virtual vector<char> read() override;
	

	//visitor pattern
	virtual void accept(AbstractFileVisitor*) override;

	//destructor
	virtual ~ImageFile() = default;

	// copy command
	virtual AbstractFile* clone(string newname) override;
};