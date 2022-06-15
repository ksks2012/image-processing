#ifndef __COLOR_MODE_H__
#define __COLOR_MODE_H__

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>


using namespace std;

class ColorMode
{
public:
    ColorMode();
    ColorMode(int, int, string);
    ~ColorMode();

    virtual int read(string);
    virtual int write_this(const string & = "");
    virtual int write(uint8_t *, int, int, string = "");
    virtual void print();

protected:
    int _print_error_magic(string);

public:
    string mode;        /*!< color mode */
    size_t SIZE;        /*!< size of image */
    double *image_data; /*!< pointer to the begin of image data */

    int width;  /*!< width of iamge */
    int height; /*!< height of image */

protected:
    int POINT_EXTEND; /*!< size of a pixel  */
};

#endif