#pragma once

class Visitor {
public:
	virtual ~Visitor() = default;
	virtual void VisitBool(const bool& element) = 0;

protected:
	Visitor() = default;
};