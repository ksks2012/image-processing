#include "transform.h"

double NTSC_YIQ[9] = {0.299, 0.587, 0.114, 0.596, -0.275, -0.321, 0.212, -0.523, 0.311};
double PI = 3.1415926;

/*
* @brief trans_gray_image trans RGB ppm to gray image pgm
* @param ppm_image input ppm file
* @return gray_image the calculate result
*/
ImageMatrix trans_gray_image(ImageMatrix & ppm_image)
{
    ImageMatrix gray_image = PGM_image(ppm_image.width, ppm_image.height);

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

/*
 * @brief trans_HSV_image trans RGB ppm to HSV image
 * @param ppm_image input ppm file
 * @return hsv_vector the calculate result of HSV
 */
double * trans_HSV_image(ImageMatrix &ppm_image)
{
    int w = ppm_image.width, h = ppm_image.width;
    
    double *hsv_vector = new double[w * h * 3];

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w * 3; j++)
        {
            int r_idx = i * w * 3 + j;
            int R = ppm_image.image_data[r_idx];
            int G = ppm_image.image_data[r_idx + 1];
            int B = ppm_image.image_data[r_idx + 2];

            double H1 = acos(0.5 * ((R - G) + (R - B)) / (double)sqrt((R - G) * (R - G) + (R - B) * (G - B)));
            // B <= G
            double H = H1;
            if (B > G)
            {
                H = 2 * PI - H1;
            }

            int rgb_max = R;
            rgb_max = rgb_max > G ? rgb_max : G;
            rgb_max = rgb_max > B ? rgb_max : B;
            int rgb_min = R;
            rgb_min = rgb_min < G ? rgb_min : G;
            rgb_min = rgb_min < B ? rgb_min : B;

            double S = (rgb_max - rgb_min) / double(rgb_max);
            double V = double(rgb_max) / 255;
            
            hsv_vector[r_idx] = (int)H;
            hsv_vector[r_idx + 1] = (int)S;
            hsv_vector[r_idx + 2] = (int)V;
        }
    }
    return hsv_vector;
}