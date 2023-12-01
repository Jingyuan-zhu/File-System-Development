#pragma once
// declaration of SimpleFileSystem class goes here

#include "AbstractFile.h"
#include "AbstractFileSystem.h"
#include <map>
#include <set>


class SimpleFileSystem : public AbstractFileSystem {

private:
	map<string, AbstractFile*> files;
	set<AbstractFile*> openFiles;
	enum results { success, fileExists = 1, nullPointer = 2, fileDNE = 3, fileNotOpen = 4 };

public:
	virtual int addFile(string filename, AbstractFile* a) override;
	virtual int deleteFile(string filename) override;
	virtual AbstractFile* openFile(string filename) override;
	virtual int closeFile(AbstractFile*) override;
	virtual set<string> getFileNames() override;

	virtual ~SimpleFileSystem();

};