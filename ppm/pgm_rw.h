#ifndef __PGM_RW_H__
#define __PGM_RW_H__

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>

#include "ppm_rw.h"

using namespace std;

/*
 * @brief PGM_image class to process pgm file format
 */
class PGM_image : public PPM_image
{
public:
    PGM_image();
    PGM_image(int, int);
    ~PGM_image();

    int read(const string);
    int write_this(const string &);
    int write(uint8_t *, int , int, string = "P2", string = "255", string = "");

public:
};

#endif