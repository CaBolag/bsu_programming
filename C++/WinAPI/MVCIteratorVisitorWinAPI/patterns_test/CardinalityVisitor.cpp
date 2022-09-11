#include "CardinalityVisitor.h"
void CardinalityVisitor::VisitBool(const bool& element) {
	if (element) {
		total_++;;
	}
}

size_t  CardinalityVisitor::GetTotal() const {
	return total_;
}