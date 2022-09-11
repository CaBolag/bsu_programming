#pragma once
#include"X.h"
#include "Subject.h"

class Model : public Subject {
public:
	Model() {};
	void Add(size_t element);
	size_t Cardinality(CardinalityVisitor& visitor) const;
	void Save(SaveVisitor& visitor, std::string filename) const;
	size_t Size() const;
	void Accept(Visitor& visitor) const;
	std::string GetStringOfElements()const;
	std::string GetStringOfData()const;
private:
	X x_;
};
