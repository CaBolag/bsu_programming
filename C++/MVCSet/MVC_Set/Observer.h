#pragma once
//#include"Subject.h"
class Observer
{
public:
	virtual ~Observer() = default;
	virtual void Update() = 0;

};

