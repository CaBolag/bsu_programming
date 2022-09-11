#pragma once

class Visitor {
public:
	virtual ~Visitor() = default;
	virtual void VisitInt(const int& element) = 0;

protected:
	Visitor() = default;
};