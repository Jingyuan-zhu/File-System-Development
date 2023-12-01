#pragma once
// declaration of BasicDisplayVisitor here

#include "AbstractFileVisitor.h"

class BasicDisplayVisitor : public AbstractFileVisitor {
public:
	virtual void visitTextFile(TextFile*) override;
	virtual void visitImageFile(ImageFile*) override;
};