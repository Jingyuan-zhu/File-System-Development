// define methods of SimpleFileSystem class here


#include "SimpleFileSystem.h"
#include "ImageFile.h"
#include "TextFile.h"

int SimpleFileSystem::addFile(string filename, AbstractFile* a) {
	// first ensure that the file does not already exist 
	if (files.find(filename) != files.end()) {
		return fileExists;
	}

	else {
	// check the AbstractFile pointer passed to the function is not a nullptr
		if (a == nullptr) {
			return nullPointer;
		}
		files.insert({ filename,a });
		return success;
	}
}



int SimpleFileSystem::deleteFile(string filename) {
	auto it = files.find(filename);
	// if the file exists
	if (it != files.end()) {
		AbstractFile* checkDelete = it->second;
		// check if the file is already open
		if (openFiles.find(checkDelete) == openFiles.end()) { // file is not open
			files.erase(it);
			delete checkDelete;
			return success;
		}
		else{
			return fileExists;
		}
	}
	else {
		return fileDNE;
	}
}

AbstractFile* SimpleFileSystem::openFile(string filename) {
	//first check if the file is already open
	auto it = files.find(filename);
	if (it != files.end()) { // this indicates that file does exist
		// then check if the file does not already open
		AbstractFile* checkOpen = it->second;
		if (openFiles.find(checkOpen) == openFiles.end()) { // the input file is not already open
			openFiles.insert(checkOpen);
			return checkOpen;
		}
		else {
			return nullptr;
		}

	}
	else { // file does not exist
		return nullptr;
	}
}

int SimpleFileSystem::closeFile(AbstractFile* filename) {
	auto it = openFiles.find(filename);
	if (it != openFiles.end()) { // the file is open
		openFiles.erase(it);
		return success;
	}
	else {
		return fileNotOpen;
	}
}

SimpleFileSystem :: ~SimpleFileSystem() {
	for (auto it = files.begin(); it != files.end(); ++it) {
		delete it->second;
	}
}

set<string> SimpleFileSystem::getFileNames() {
	set<string> fileName;

	for (auto it = files.begin(); it != files.end(); ++it) {
		fileName.insert(it->first);
	}

	return fileName;
}