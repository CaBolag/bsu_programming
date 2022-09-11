#include "Model.h"
void Model::UpdateSet(Set& set) {
	set_ = std::move(set);
	this->Notify();
}

void Model::Clear() {
	set_.Clear();
	this->Notify();
}

size_t Model::Size() const {
	return set_.Size();
}

void Model::Accept(Visitor& visitor) const {
	set_.Accept(visitor);
}