// studio 18 - simple file factory definitions

#include "AbstractFileFactory.h"
#include "ImageFile.h"
#include "TextFile.h"
#include "SimpleFileFactory.h"


AbstractFile * SimpleFileFactory::createFile(string filename) {

		string str = filename.substr(filename.length() - 3, 3);
		if (str == "txt") {
			AbstractFile* text = new TextFile(filename);
			return text;
		}

		else if (str == "img") {
			AbstractFile* image = new ImageFile(filename);
			return image;
		}

		else {
			return nullptr;
		}
	
}
