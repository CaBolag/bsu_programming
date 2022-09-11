#pragma once
#include"Set.h"
#include "Subject.h"

class Model : public Subject {
public:

	Model() {};
	void UpdateSet(Set& set);
	void Clear();
	size_t Size() const;
	void Accept(Visitor& visitor) const;
private:
	Set set_;
};
