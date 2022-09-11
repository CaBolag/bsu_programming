#include "ToStringVisitor.h"
void ToStringVisitor::VisitInt(const int& element) {
	str_ += std::to_string(element) + " ";
}

std::string ToStringVisitor::GetString() const {
	return str_;
}