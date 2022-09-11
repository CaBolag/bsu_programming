#pragma once
#include <iostream>
#include "Iterator.h"

class X;

class XIterator :
    public Iterator
{
public:
	XIterator(const X& x) :x_{ x }, currentIndex_{ 0 }{};
	virtual void First();
	virtual void Next();
	virtual bool IsDone() const;
	virtual bool CurrentItem() const;

private:
	const X& x_;
	int currentIndex_;
};

