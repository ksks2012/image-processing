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

/*
 * @brief PPM_image class to process ppm file format
 */
class PPM_image
{
public:
    PPM_image();
    ~PPM_image();

    int read_ppm(const string);
    int write_this_ppm(const string & = "");
    int write_ppm(uint8_t *, int , int, string = "P3", string = "255", string = "");

public:
    size_t SIZE;
    uint8_t* image_data;

    string magic; 
    int width;
    int height;
    string max_colour;
};

#endif