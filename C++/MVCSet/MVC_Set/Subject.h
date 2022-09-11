#pragma once
#include<vector>
#include"Observer.h"

class Observer;

class Subject
{
public:

    // virtual ~Subject() = default;
    void Attach(Observer* observer);
    void Detach(const int index);
    void Notify();

private:
    std::vector<Observer*> observers;
};

