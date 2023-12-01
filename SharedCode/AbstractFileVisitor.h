#pragma once
// declaration of the file visitor interface here
// we create an interface for visitor 

#include "TextFile.h"
#include "ImageFile.h"

class AbstractFileVisitor {
public:
	virtual void visitTextFile(TextFile*) = 0;
	virtual void visitImageFile(ImageFile*) = 0;
};