#include "objectmanager.h"

shared_ptr<Base_multimedia> ObjectManager:: newPhoto(string name, string filepath, int height, int width){
    auto iterator = this->om.find(name);
    if(iterator != this->om.end()){
        std::cout<<"There already exists a photo with the same name, try again";
        return this->om[name];
    }
    shared_ptr<Photo> aux (new Photo(name, filepath, height, width));
    this->om[name] = aux;
    return this->om[name];
}

shared_ptr<Base_multimedia> ObjectManager:: newVideo(string name, string filepath, int length){
    auto iterator = this->om.find(name);
    if(iterator != this->om.end()){
        std::cout<<"There already exists a video with the same name, try again";
        return this->om[name];
    }
    shared_ptr<Video> aux (new Video(name, filepath, length));
    this->om[name] = aux;
    return this->om[name];
}

shared_ptr<Base_multimedia> ObjectManager:: newFilm(string name, string filepath, int length, int numChapters, int * duration){
    auto iterator = this->om.find(name);
    if(iterator != this->om.end()){
        std::cout<<"There already exists a film with the same name, try again";
        return this->om[name];
    }
    shared_ptr<Film> aux (new Film(name, filepath, length, numChapters, duration));
    this->om[name] = aux;
    return this->om[name];
}
shared_ptr<Group> ObjectManager:: newGroup(string name){
    auto iterator = this->gm.find(name);
    if(iterator != this->gm.end()){
        std::cout<<"There already exists a film with the same name, try again";
        return this->gm[name];
    }
    shared_ptr<Group> aux (new Group(name));
    this->gm[name] = aux;
    return this->gm[name];
}
shared_ptr<Base_multimedia> ObjectManager::findObject(string name, bool print){
    auto iterator = this->om.find(name);
    if(iterator == this->om.end()){
        std::cout<<"Multimedia object not found!\n";
        return nullptr;
    }
    if (print) iterator->second->toString(std::cout);
    return iterator->second;
}
shared_ptr<Group> ObjectManager::findGroup(string name, bool print){
    auto iterator = this->gm.find(name);
    if(iterator==this->gm.end()){
        std::cout<<"Group not found!\n";
        return nullptr;
    }
    if(print) iterator->second->toString(std::cout);
    return iterator->second;
}
void ObjectManager::playObject(string name){
    shared_ptr<Base_multimedia> aux = this->findObject(name, false);
    if (aux!=nullptr) aux->play();
}
bool ObjectManager::processRequest(cppu::TCPConnection& cnx, const string& request, string& response)
  {
    cerr << "\nRequest: '" << request << "'" << endl;

    // 1) pour decouper la requête:
    // on peut par exemple utiliser stringstream et getline()
    string action, name;
    std::stringstream aux;
    aux << request;
    aux >> action;
    aux >> name;


    // 2) faire le traitement:
    // - si le traitement modifie les donnees inclure: TCPLock lock(cnx, true);
    // - sinon juste: TCPLock lock(cnx);
    cppu::TCPLock lock(cnx);


    // 3) retourner la reponse au client:
    // - pour l'instant ca retourne juste OK suivi de la requête
    // - pour retourner quelque chose de plus utile on peut appeler la methode print()
    //   des objets ou des groupes en lui passant en argument un stringstream
    // - attention, la requête NE DOIT PAS contenir les caractères \n ou \r car
    //   ils servent à délimiter les messages entre le serveur et le client
    std::stringstream response_stream;
    bool task_completed = false;
    if(action=="search"){
        shared_ptr<Group> grp = this->findGroup(name, false);
        if (grp!= nullptr){
            grp->toString(response_stream);
            task_completed = true;
        }
        shared_ptr<Base_multimedia> bas = this->findObject(name, false);
        if (bas!= nullptr){
            bas->toString(response_stream);
            //bas->toString(std::cout);
            task_completed = true;
        }
    } else if (action=="play"){
        this->playObject(name);
    }
    if (task_completed){
        response = response_stream.str();
        return true;
    }

    //response = "OK: " + request;
    //cerr << "response: " << response << endl;

    // renvoyer false si on veut clore la connexion avec le client
    response = "Error: requested file not found";
    return true;
  }
