#ifndef __PGM_RW_H__
#define __PGM_RW_H__

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>

#include "image_matrix.h"

using namespace std;

/*
 * @brief PGM_image class to process pgm file format
 */
class PGM_image : public ImageMatrix
{
public:
    PGM_image();
    PGM_image(int, int);
};

#endif