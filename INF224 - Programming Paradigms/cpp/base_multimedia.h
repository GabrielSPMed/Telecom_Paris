#ifndef BASE_MULTIMEDIA_H
#define BASE_MULTIMEDIA_H
#include <iostream>
using namespace std;

class Base_multimedia
{
private:
    string name;
    string filepath;
public:
    Base_multimedia();
    Base_multimedia(string name, string filepath);
    void setName(string name);
    string getName();
    void setFilepath(string filepath);
    string getFilepath();
    virtual void toString(std::ostream & s);
    virtual ~Base_multimedia() {}
    virtual void play() =0;
};

#endif // BASE_MULTIMEDIA_H


