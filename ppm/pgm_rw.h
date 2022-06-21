#ifndef __PGM_RW_H__
#define __PGM_RW_H__

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>

#include "image_matrix.h"

using namespace std;

#define set_bit(x, n) (x |= (1 << n))
#define clear_bit(x, n) (x &= ~(1 << n))

/*
 * @brief PGM_image class to process pgm file format
 */
class PGM_image : public ImageMatrix
{
public:
    PGM_image();
    PGM_image(int, int);
    PGM_image(const PGM_image &);

    PGM_image gen_bit_flat(int);
};

#endif