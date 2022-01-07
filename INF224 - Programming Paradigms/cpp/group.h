#ifndef GROUP_H
#define GROUP_H
#include "base_multimedia.h"
#include <list>
#include <memory>

using namespace std;

class Group: public list<shared_ptr<Base_multimedia>>
{
private:
    string name;
public:
    Group();
    Group(string name);
    string getName();
    void setName(string name);
    void toString(std::ostream & s);
    ~Group(){}
};

#endif // GROUP_H
