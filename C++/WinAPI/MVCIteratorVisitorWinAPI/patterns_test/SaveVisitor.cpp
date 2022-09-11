#include "SaveVisitor.h"
void SaveVisitor::VisitBool(const bool& element) {
	if (element) {
		elements_.push_back(index_);
		
	}
	//--------------------
	index_++;
}

std::vector<int> SaveVisitor::GetElements() const {
	return elements_;
}