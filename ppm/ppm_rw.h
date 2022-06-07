#ifndef __PNG_RW_H__
#define __PNG_RW_H__

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

#define X 320
#define Y 240

typedef unsigned char byte;

class PPM_image
{
public:
    PPM_image();
    ~PPM_image();

    int ppm_read(string);
    int ppm_write(byte *, string = "");

public:
    size_t SIZE;
    byte* image_data;
};

#endif