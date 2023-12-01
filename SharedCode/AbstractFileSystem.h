#pragma once
// declaration of the interface all file systems provide goes here

#include "AbstractFile.h"
#include <set>

class AbstractFileSystem {
	
public:	
	virtual int addFile(string filename, AbstractFile * a) = 0;
	virtual int deleteFile(string filenema) = 0 ;
	virtual AbstractFile* openFile(string filename) = 0;
	virtual int closeFile(AbstractFile *) = 0;
	virtual set<string> getFileNames() = 0;
};