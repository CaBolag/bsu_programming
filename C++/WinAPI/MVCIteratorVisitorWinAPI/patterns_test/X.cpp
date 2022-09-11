#include "X.h"

size_t X::Cardinality(CardinalityVisitor& visitor) const {
	XIterator iterator(*this);
	//for (iterator.First(); !iterator.IsDone(); iterator.Next()) {
	//	visitor.VisitBool(iterator.CurrentItem());
	//}
	
	this->Accept(visitor);
	size_t amount=visitor.GetTotal();
	return amount;
}


void X::Save(SaveVisitor& visitor, std::string filename) const {
	XIterator iterator(*this);
	//for (iterator.First(); !iterator.IsDone(); iterator.Next()) {
	//	visitor.VisitBool(iterator.CurrentItem());
	//}
	this->Accept(visitor);
	std::vector<int> elements=visitor.GetElements();
	std::ofstream output(filename);
	if (!output.is_open())
	{
		std::runtime_error("ERROR: file is not open");
	}

	std::ostream_iterator<int&> out(output);
	std::copy(elements.begin(), elements.end(), out);
}




std::ostream& operator <<(std::ostream& out, const X& x) {
	for (int i = 0; i < x.Size(); i++) {
		out << x.GetAt(i) << " ";
	}
	out << "\n";
	return out;
}
X::~X() {
	delete[] data_;
	size_ = 0;
}



size_t X::Size()const {
	return size_;
}

void X::Add(size_t element) {
	data_[element] = 1;
}
bool X::GetAt(int index) const {
	if (index >= size_)
	{
		throw std::out_of_range("(operator[]) index is too large");
	}
	return data_[index];
}


void X::Accept(Visitor& visitor) const {
	XIterator iterator(*this);
	for (iterator.First(); !iterator.IsDone(); iterator.Next()) {
		visitor.VisitBool(iterator.CurrentItem());
	}
}


std::string X::GetStringOfElements() const {
	std::string str;
	for (int i = 0; i < size_; i++) {
		if(data_[i])
		str+=std::to_string(i)+" ";
	}
	return str;
};
std::string X::GetStringOfData()const {
	std::string str;
	for (int i = 0; i < size_; i++) {
		str += std::to_string(data_[i]) + " ";
	}
	return str;
};
