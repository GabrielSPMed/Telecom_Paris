#ifndef VIDEO_H
#define VIDEO_H
#include "base_multimedia.h"


class Video : public Base_multimedia
{
private:
    int length;
public:
    Video();
    Video(string name, string filepath, int length);
    void setLength(int length);
    int getLength();
    void toString(std::ostream & s) override;
    void play() override;
    ~Video() override {}
};

#endif // VIDEO_H
