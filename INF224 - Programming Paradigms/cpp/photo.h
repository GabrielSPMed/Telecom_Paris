#ifndef PHOTO_H
#define PHOTO_H
#include "base_multimedia.h"


class Photo : public Base_multimedia
{
private:
    int height, width;
public:
    Photo();
    Photo(string name, string filepath, int height, int width);
    void setHeight(int height);
    int getHeight();
    void setWidth(int length);
    int getWidth();
    void toString(std::ostream & s) override;
    void play() override;
    ~Photo() override {}

};

#endif // PHOTO_H
