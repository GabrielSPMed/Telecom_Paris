#include "group.h"

Group::Group()
{
    this->name = "";
}
Group::Group(string name)
{
    this->name=name;
}
void Group::setName(string name)
{
    this->name = name;
}
string Group::getName()
{
    return this->name;
}
void Group::toString(std::ostream &s){
    s << "Group " << this->name << "\n";
    for (auto &iterator : *this){
        if (iterator){
            iterator->toString(s);
        }
    }
}
