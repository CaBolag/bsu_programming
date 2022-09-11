#pragma once
#include<string>
#include "Visitor.h"
class ToStringVisitor :
    public Visitor
{
public:
    ToStringVisitor() = default;
    ~ToStringVisitor() = default;
    virtual void VisitInt(const int& element) override;
    std::string GetString() const;
private:
    std::string str_="";
};

