#include"Subject.h"

void Subject::Attach(Observer* observer)
{
    observers.push_back(observer);
}

void Subject::Detach(const int index)
{
    observers.erase(observers.begin() + index);
}

void Subject::Notify()
{
    for (unsigned int i = 0; i < observers.size(); i++)
    {
        observers.at(i)->Update();
    }
}

