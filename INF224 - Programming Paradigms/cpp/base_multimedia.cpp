#include "base_multimedia.h"

Base_multimedia::Base_multimedia()
{
    name = "";
    filepath = "";
}

Base_multimedia::Base_multimedia(string name, string filepath)
{
    this->name = name;
    this->filepath = filepath;
}

void Base_multimedia::setName(string name)
{
    this->name = name;
}

string Base_multimedia::getName()
{
    return this->name;
}

void Base_multimedia::setFilepath(string filepath)
{
    this->filepath = filepath;
}

string Base_multimedia::getFilepath()
{
    return this->filepath;
}

void Base_multimedia::toString(std::ostream &s)
{
    s << "File name: " << name << "\n"
      << "Path: " << filepath << std::endl;
}
//void Base_multimedia::play(){}
