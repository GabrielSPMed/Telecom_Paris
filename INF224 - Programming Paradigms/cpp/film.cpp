#include "film.h"

Film::Film():Video()
{
    this->duration = nullptr;
    this->numChapters = 0;
}
Film::Film(string name, string filepath, int length, int numChapters, int * duration):
            Video(name,filepath,length)
{
    this->duration = duration;
    this->numChapters = numChapters;
}
int *Film::getDuration()
{
    return this->duration;
}
void Film::setDuration(int * duration, int numChapters)
{
    delete[] this->duration;
    if (numChapters == 0){
        this->numChapters=0;
        this->duration = nullptr;
        return;
    }
    this->numChapters = numChapters;
    this->duration = new int[unsigned(this->numChapters)];
    for(int i=0; i<this->numChapters;i++){
        this->duration[i]=duration[i];
    }
    this->duration = duration;
}
int Film::getNumChapters()
{
    return this->numChapters;
}
void Film::toString(std::ostream &s)
{
    s << "File name: " << this->getName() << "\n"
      << "Path: " << this->getFilepath() << "\n"
      << "Length: " << this->getLength() << "\n"
      << "Number of Chapters: "<< this->numChapters << '\n';
    for (int i=0; i<this->numChapters;i++) s << "Chapter " << i << ": "<< duration[i]<<'\n';
    s << std::endl;
}
Film::~Film(){
    delete duration;
    this-> numChapters=0;
}
