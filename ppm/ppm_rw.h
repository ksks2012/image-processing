#ifndef __PPM_RW_H__
#define __PPM_RW_H__

#include "image_matrix.h"

using namespace std;

/*
 * @brief PPM_image class to process ppm file format
 */
class PPM_image : public ImageMatrix
{
public:
    PPM_image();
    PPM_image(int, int);
};

#endif