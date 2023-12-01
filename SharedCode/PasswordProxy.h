#pragma once
#include "AbstractFile.h"

class PasswordProxy : public AbstractFile {

private:
	enum { success, wrongPassword };
	AbstractFile* file; // this will point to the file that is to be password protected 
	std::string password; // password for the real file


public:
	//constructor
	PasswordProxy(AbstractFile* file, std::string password);
	//destructor
	~PasswordProxy();
	// public methods that inherit from the AbstractFile
	int write(std::vector<char>) override;
	virtual std::vector<char> read() override;
	int append(std::vector<char>) override;
	unsigned int getSize() override;
	std::string getName() override;
	void accept(AbstractFileVisitor*) override;

	//copy command
	virtual AbstractFile* clone(string newname) override;

protected:
	std::string passwordPrompt();
	bool passwordMatch(std::string); // helper function that checks to see whether a string matches the password member variable


	
};