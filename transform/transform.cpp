#include "transform.h"

double NTSC_YIQ[9] = {0.299, 0.587, 0.114, 0.596, -0.275, -0.321, 0.212, -0.523, 0.311};

/*
 * @brief trans_gray_image trans RGB ppm to gray image pgm
 * @param ppm_image input ppm file
 */
PGM_image trans_gray_image(PPM_image &ppm_image)
{
    PGM_image gray_image = PGM_image(ppm_image.width, ppm_image.height);

    int w = ppm_image.width, h = ppm_image.width;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            // Y = 0.299 * R + 0.587 * G + 0.114 * B
            for (int k = 0; k < 3; k++)
            {
                gray_image.image_data[i * w + j] += NTSC_YIQ[k] * ppm_image.image_data[i * w * 3 + j * 3 + k];
            }
        }
    }

    return gray_image;
}
