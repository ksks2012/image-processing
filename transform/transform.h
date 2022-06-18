#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__

#include <cmath>
#include "../ppm/ppm_rw.h"
#include "../ppm/pgm_rw.h"
#include "../ppm/color_mode.h"
#include "../ppm/image_matrix.h"

ImageMatrix trans_PPM2PGM(const ImageMatrix &);
double * trans_RGB2HSV(const ImageMatrix &);
ColorMode trans_RGB2YIQ(const PPM_image &);
ColorMode trans_RGB2YUV(const PPM_image &);
PPM_image trans_YUV2RGB(const ColorMode &);

#endif