#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__

#include <cmath>
#include "../ppm/pgm_rw.h"
#include "../ppm/image_matrix.h"

ImageMatrix trans_gray_image(ImageMatrix &);
double * trans_HSV_image(ImageMatrix &);

#endif