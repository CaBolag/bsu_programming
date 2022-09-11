#pragma once
#include "Visitor.h"
class CardinalityVisitor:public Visitor
{
public:
	CardinalityVisitor() = default;
	~CardinalityVisitor() = default;
	virtual void VisitBool(const bool& element) override;
	size_t GetTotal()const;
private:
	size_t total_ = 0;
};

