// definitions of metadata visitor here

#include "MetadataDisplayVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

// the display method will display the file's name, size, and type
void MetadataDisplayVisitor::visitTextFile(TextFile* text) {
	cout << text->getName() << setw(7) << "text" << setw(7) << text->getSize() << endl;
}

void MetadataDisplayVisitor::visitImageFile(ImageFile* image) {
	cout << image->getName() << setw(7) << "image" << setw(7) << image->getSize() << endl;
}
