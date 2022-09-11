#pragma once
#pragma once
#include <iostream>
#include <memory>
#include <algorithm>
#include <sstream>
#include <iterator>
#include<vector>
#include<fstream>
#include "CardinalityVisitor.h"
#include"SaveVisitor.h"
#include "XIterator.h"


class X
{
public:
	X(): size_{ 100 }, data_{ new bool[size_]}{
		//-----------
		for (int i = 0; i < size_; i++) {
			data_[i] = 0;
		}
	};
	~X();
	X(const X&)=default;
	X(X&&) = default;
	X& operator=(const X&) = default;
	X& operator=(X&&) = default;


	void Add(size_t element);
	size_t Cardinality(CardinalityVisitor& visitor) const;
	void Save(SaveVisitor& visitor, std::string filename) const;
	bool GetAt(int index) const;
	std::string GetStringOfElements()const;
	std::string GetStringOfData()const;

	void Swap(X& x);
	size_t Size() const;
	

	void Accept(Visitor& visitor) const;

private:
	size_t size_;;
	bool* data_;
	//-----------
	//X(const X&) {};
	//X(X&&) {};
	//X& operator=(const X&) {};
	//X& operator=(X&&) {};
};

std::ostream& operator <<(std::ostream& out, const X& x);
