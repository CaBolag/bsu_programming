#pragma once
#include "Visitor.h"

class SumVisitor : public Visitor {
public:
	SumVisitor() = default;
	~SumVisitor() = default;
	virtual void VisitInt(const int& element) override;
	int GetTotal()const;
private:
	int total_ = 0;
};
