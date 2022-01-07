#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H
#include "photo.h"
#include "film.h"
#include "group.h"
#include "tcpserver.h"

#include <map>
#include <sstream>

using ObjectMap = map<string, shared_ptr<Base_multimedia>>;
using GroupMap = map<string, shared_ptr<Group>>;
class ObjectManager
{
private:
    ObjectMap om;
    GroupMap gm;
public:
    ObjectManager():om(), gm(){}
    shared_ptr<Base_multimedia> newPhoto(string name, string filepath, int height, int width);
    shared_ptr<Base_multimedia> newVideo(string name, string filepath, int length);
    shared_ptr<Base_multimedia> newFilm(string name, string filepath, int length, int numChapters, int * duration);
    shared_ptr<Group> newGroup(string name);
    shared_ptr<Base_multimedia> findObject(string name, bool print=true);
    shared_ptr<Group> findGroup(string name, bool print=true);
    void playObject(string name);
    bool processRequest(cppu::TCPConnection& cnx, const string& request, string& response);

};

#endif // OBJECTMANAGER_H
