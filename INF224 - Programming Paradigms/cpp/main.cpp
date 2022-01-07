//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "base_multimedia.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "group.h"
#include "objectmanager.h"
#include "cppsocket.h"
#include "tcpserver.h"

static const std::string HOST = "127.0.0.1";
static const int PORT = 3331;


using namespace std;

int main(int argc, const char* argv[])
{
    // Question 4: answer in readme

    cout<<"Question 4:"<<endl;
    Video * test1 = new Video();
    test1->setLength(12);
    test1->setName("alpes");
    test1->setFilepath("Home/movies/2018");
    test1->toString(std::cout);

    Photo * test2 = new Photo("ironman", "home/pictures/", 10, 12);
    test2->toString(std::cout);

    // Question 5: answer of question in readme
    cout<< endl <<"Question 5:"<<endl;
    Base_multimedia **medias = new Base_multimedia*[2];
    medias[0] = test1;
    medias[1] = test2;
    for (int i=0;i<1;i++){
        cout<<"Generic media loop, iteration: " << i << endl;
        medias[i]->toString(std::cout);
    }
    delete test1;
    delete test2;
    delete[] medias;

    // Question 6: answer of question in readme
    cout<< endl <<"Question 6:"<<endl;
    Film * test3 = new Film();
    test3->setLength(12);
    test3->setName("hawaii 5-0");
    test3->setFilepath("Home/movies/hollywood");
    int * duration = new int[3];
    duration[0] = 3;
    duration[1] = 1000;
    duration[2] = 300;
    test3->setDuration(duration, 3);
    test3->toString(std::cout);
    delete test3;

    // Question 7: answer of question in readme
    cout<< endl <<"Question 7:"<<endl;
    shared_ptr<Video> aux(new Video("ironman", "movies/2018", 1));
    shared_ptr<Photo> aux2 (new Photo("bahamas", "Pictures/2016", 12, 32));
    shared_ptr<Film> aux3(new Film("The little mermaid", "movies/1996", 18, 3, duration));
    shared_ptr<Group> test4(new Group("My memories"));

    test4->push_back(aux);
    test4->push_back(aux2);
    test4->push_back(aux3);
    test4->toString(std::cout);
    test4.reset();

    // Question 8: answer of question in readme

    // Question 10: answer of question in readme

    // Question 11:
    // cree le TCPServer

      shared_ptr<cppu::TCPServer> server(new cppu::TCPServer());

      // cree l'objet qui gère les données
      shared_ptr<ObjectManager> base(new ObjectManager());
      //example to test code. For some reason only the first line of the toString gets to the destination. :(. Didn't have time to fix this.
      //base->newPhoto("amsterdam.jpg", "home/pictures/2021/", 13, 24);

      // le serveur appelera cette méthode chaque fois qu'il y a une requête
      server->setCallback(*base, &ObjectManager::processRequest);

      // lance la boucle infinie du serveur

      cout << "Starting Server on port " << PORT << endl;
      int status = server->run(PORT);

      // en cas d'erreur
      if (status < 0) {
        cerr << "Could not start Server on port " << PORT << endl;
        return 1;
      }

      return 0;

}
