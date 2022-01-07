#include "video.h"


Video::Video():Base_multimedia ()
{
    this->length = 0;
}

Video::Video(string name, string filepath, int length):Base_multimedia (name, filepath)
{
    this->length = length;
}

void Video::setLength(int length)
{
    this->length = length;
}

int Video::getLength(){return this->length;}

void Video::toString(std::ostream &s)
{
    s << "File name: " << this->getName() << "\n"
      << "Path: " << this->getFilepath() << "\n"
      << "Length: " << this->getLength()<< std::endl;

}

void Video::play()
{
    system(("mpv" + this->getFilepath() + "&").c_str());
}
