#include "Model.h"


size_t Model::Size() const {
	return x_.Size();
}

void Model::Accept(Visitor& visitor) const {
	x_.Accept(visitor);
}

void Model::Add(size_t element) {
	x_.Add(element);
	this->Notify();
}

size_t Model::Cardinality(CardinalityVisitor& visitor) const {
	return x_.Cardinality(visitor);
}
void Model::Save(SaveVisitor& visitor, std::string filename) const {
	x_.Save(visitor, filename);
}


std::string Model::GetStringOfElements()const {
	return x_.GetStringOfElements();
};

std::string Model::GetStringOfData()const {
	return x_.GetStringOfData();
};