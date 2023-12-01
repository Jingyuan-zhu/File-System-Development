// definitions of basic display visitor here
#include "BasicDisplayVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <vector>
#include <iostream>

using namespace std;

void BasicDisplayVisitor::visitTextFile(TextFile* text) {
	vector<char> contents = text->read();
	for (unsigned int i = 0; i < contents.size(); ++i){
		cout << contents[i];
	}
	cout << endl;
	return;
}

void BasicDisplayVisitor::visitImageFile(ImageFile* image) {
	vector<char> contents = image->read();
	size_t dim = static_cast<size_t> (sqrt(image->getSize()));
	for (size_t h = dim - 1; h + 1 != 0; h--) {
		for (size_t w = 0; w < dim; ++w) {
			cout << contents[(dim * h) + w];
		}
		cout << endl;
	}
	return;


}

