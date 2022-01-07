#ifndef FILM_H
#define FILM_H
#include "video.h"

class Film : public Video
{
    int numChapters;
    int * duration;
public:
    Film();
    Film(string name, string filepath, int length, int numChapters, int * duration);
    int getNumChapters();
    void setDuration(int *duration, int numChapters);
    int * getDuration();
    void toString(std::ostream & s) override;
    ~Film() override;

};

#endif // FILM_H
