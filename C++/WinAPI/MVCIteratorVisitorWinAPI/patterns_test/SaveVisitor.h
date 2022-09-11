#pragma once
#include "Visitor.h"
#include<vector>
class SaveVisitor :
    public Visitor
{
public:
	SaveVisitor() = default;
	~SaveVisitor() = default;
	virtual void VisitBool(const bool& element) override;
	std::vector<int> GetElements() const;
private:
	int index_ = 0;
	std::vector<int> elements_;
};

