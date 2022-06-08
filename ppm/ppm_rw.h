#ifndef __PPM_RW_H__
#define __PPM_RW_H__

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

/*
 * @brief PPM_image class to process ppm file format
 */
class PPM_image
{
public:
    PPM_image();
    ~PPM_image();

    int read(const string);
    int write_this(const string & = "");
    int write(uint8_t *, int , int, string = "P3", string = "255", string = "");

public:
    size_t SIZE;
    uint8_t* image_data;

    string magic; 
    int width;
    int height;
    string max_colour;
};

#endif