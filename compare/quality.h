#ifndef __QUALITY_H__
#define __QUALITY_H__

#include <cmath>

#include "../ppm/image_matrix.h"

double cal_PSNR(const ImageMatrix &, const ImageMatrix &);
double cal_SSIM(const ImageMatrix &, const ImageMatrix &);

#endif