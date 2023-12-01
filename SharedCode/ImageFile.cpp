// definition of ImageFile class here

#include "AbstractFile.h"
#include "AbstractFileVisitor.h"
#include "ImageFile.h"
#include <iostream>

//constructor
ImageFile::ImageFile(string n) : name(n), size(0) {}

unsigned int ImageFile::getSize() {
	return contents.size();
}

string ImageFile::getName() {
	return name;
}

int ImageFile::append(vector<char> input) {
	return cannotAppend;
}

vector<char> ImageFile::read() {
	return contents;
}

int ImageFile::write(vector<char> input) {
	int dim = input[input.size() - 1] - '0';
	if (dim >= 0 && dim * dim == input.size() - 1) {
		contents.clear();
		for (size_t i = 0; i < input.size() - 1; ++i) {
			if (input[i] == 'X') {
				contents.push_back(input[i]);
			}
			else if (input[i] == ' ') {
				contents.push_back(' ');
			}
			else {
				size = 0;
				contents.clear();
				return invalidPixle;

			}
		}
		size = dim;
		return success;
	
	}
	else {
		size = 0;
		contents.clear();
		return sizeMismatch;
	}

}

size_t ImageFile::indexFunction(size_t x, size_t y) {
	size_t index = size * y + x;
	return index;
}

void ImageFile::accept(AbstractFileVisitor* v) {
	v->visitImageFile(this);
}

AbstractFile* ImageFile::clone(string newname) {
	AbstractFile* cloneFile = new ImageFile(newname);
	cloneFile->write(this->read());

	return cloneFile;
}