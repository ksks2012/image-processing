#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__

#include <cmath>
#include "../ppm/pgm_rw.h"

PGM_image trans_gray_image(PPM_image &);
double * trans_HSV_image(PPM_image &);

#endif