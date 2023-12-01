#pragma once
// declaration of MetadataDisplayVisitor here

#include "AbstractFileVisitor.h"

class MetadataDisplayVisitor : public AbstractFileVisitor {

public:
	virtual void visitTextFile(TextFile*) override;
	virtual void visitImageFile(ImageFile*) override;
	
};