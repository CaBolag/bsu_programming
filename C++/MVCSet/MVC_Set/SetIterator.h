#pragma once

#include <iostream>
#include "Iterator.h"

class Set;

class SetIterator : public Iterator {
public:
	SetIterator(const Set& set) :set_{ set }, currentIndex_{ 0 }{};
	virtual void First();
	virtual void Next();
	virtual bool IsDone() const;
	virtual int CurrentItem() const;

private:
	const Set& set_;
	int currentIndex_;

};