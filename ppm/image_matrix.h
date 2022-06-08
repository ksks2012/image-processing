#ifndef __IMAGE_MATRIX_H__
#define __IMAGE_MATRIX_H__

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

class ImageMatrix
{
public:
    ImageMatrix();
    ~ImageMatrix();

    virtual int read(string);
    virtual int write_this(const string & = "");
    virtual int write(uint8_t *, int , int, string = "ASCII", string = "255", string = "");

protected:
    int _print_error_magic(string);

public:
    size_t SIZE;
    uint8_t* image_data;

    string magic;
    int width;
    int height;
    string max_colour;

protected:
    string ASCII_MAGIC;
    string BINARY_MAGIC;
    int POINT_EXTEND;
};

#endif