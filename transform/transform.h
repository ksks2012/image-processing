#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__

#include <cmath>
#include "../ppm/ppm_rw.h"
#include "../ppm/pgm_rw.h"
#include "../ppm/color_mode.h"
#include "../ppm/image_matrix.h"

ImageMatrix trans_PPM2PGM(ImageMatrix &);
double * trans_RGB2HSV(ImageMatrix &);
ColorMode trans_RGB2YIQ(PPM_image &);
ColorMode trans_RGB2YUV(PPM_image &);

#endif