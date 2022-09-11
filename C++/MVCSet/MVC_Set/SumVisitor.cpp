#include "SumVisitor.h"

void SumVisitor::VisitInt(const int& element) {
	total_ += element;
}

int SumVisitor::GetTotal() const {
	return total_;
}