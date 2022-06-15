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
    virtual int write(uint8_t *, int, int, string = "ASCII", string = "255", string = "");

protected:
    int _print_error_magic(string);

public:
    size_t SIZE;         /*!< size of image */
    uint8_t *image_data; /*!< pointer to the begin of image data */

    string magic;      /*!< magic string of image */
    int width;         /*!< width of iamge */
    int height;        /*!< height of image */
    string max_colour; /*!< max colour in image header */

protected:
    string ASCII_MAGIC;  /*!< for decided ascii magic number  */
    string BINARY_MAGIC; /*!< for decided binary magic number  */
    int POINT_EXTEND;    /*!< size of a pixel  */
};

#endif