#include "photo.h"

Photo::Photo():Base_multimedia(){
    this->width = 0;
    this->height = 0;
}

Photo::Photo(string name, string filepath, int height, int width):Base_multimedia (name, filepath){
    this->width = width;
    this->height = height;
}

void Photo::setHeight(int height){this->height = height;}
int Photo::getHeight(){return this->height;}
void Photo::setWidth(int width){this->width = width;}
int Photo::getWidth(){return this->width;}

void Photo::toString(std::ostream &s)
{
    s << "File name: " << this->getName() << "\n"
      << "Path: " << this->getFilepath() <<"\n"
      << "Width: " << this->getWidth()<< "\n"
      << "Height: " << this->getHeight()<< std::endl;
}

void Photo::play(){
    system(("imagej" + this->getFilepath() + "&").c_str());
}
