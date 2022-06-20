#include "transform.h"

double NTSC_YIQ[9] = {0.299, 0.587, 0.114, 0.596, -0.275, -0.321, 0.212, -0.523, 0.311};
double NTSC_YUV[9] = {0.299, 0.587, 0.114, -0.169, -0.331, 0.500, 0.500, -0.419, -0.081};
double NTSC_YUV2RGB[9] = {1, -0.00093, 1.401687, 1, -0.3437, -0.71417, 1, 1.77216, 0.000099};
double PI = 3.1415926;

/*
 * @brief trans_PPM2PGM trans RGB ppm to gray image pgm
 * @param ppm_image input ppm file
 * @return gray_image the calculate result
 */
ImageMatrix trans_PPM2PGM(const ImageMatrix &ppm_image)
{
    ImageMatrix gray_image = PGM_image(ppm_image.width, ppm_image.height);

    int w = ppm_image.width, h = ppm_image.height;
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
 * @brief trans_RGB2HSV trans RGB ppm to HSV image
 * @param ppm_image input ppm file
 * @return hsv_vector the calculate result of HSV
 */
// TODO: double -> ColorMode
double *trans_RGB2HSV(const ImageMatrix &ppm_image)
{
    int w = ppm_image.width, h = ppm_image.height;

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

/*
 * @brief trans_RGB2YIQ trans RGB ppm to YIQ image
 * @param ppm_image input ppm file
 * @return yiq_vector the calculate result of YIQ
 */
ColorMode trans_RGB2YIQ(const PPM_image &ppm_image)
{
    ColorMode yiq_image = ColorMode(ppm_image.width, ppm_image.height, "YIQ");

    int w = ppm_image.width, h = ppm_image.height;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            int base = i * w * 3 + j * 3; // base -> RGB
            // Y = 0.299 * R + 0.587 * G + 0.114 * B
            // I = 0.596 * R + (-0.275) * G + (-0.321) * B
            // Q = 0.212 * R + (-0.523) * G + 0.311 * B
            for (int m = 0; m < 3; m++)
            {
                for (int n = 0; n < 3; n++)
                {
                    yiq_image.image_data[base + m] += NTSC_YIQ[m * 3 + n] * ppm_image.image_data[base + n];
                }
            }
        }
    }
    return yiq_image;
}

/*
 * @brief trans_YUV_image trans RGB ppm to YUV image
 * @param ppm_image input ppm file
 * @return yuv_vector the calculate result of YUV
 */
ColorMode trans_RGB2YUV(const PPM_image &ppm_image)
{
    ColorMode yuv_image = ColorMode(ppm_image.width, ppm_image.height, "YUV");

    int w = ppm_image.width, h = ppm_image.height;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            int base = i * w * 3 + j * 3; // base -> RGB
            // Y = 0.299 * R + 0.587 * G + 0.114 * B
            // U = (-0.169) * R + (-0.332) * G + 0.500 * B + 128
            // V = 0.500 * R + (-0.419) * G + (-0.813) * B + 128
            for (int m = 0; m < 3; m++)
            {
                for (int n = 0; n < 3; n++)
                {
                    yuv_image.image_data[base + m] += NTSC_YUV[m * 3 + n] * ppm_image.image_data[base + n];
                }
                if (m >= 1)
                {
                    yuv_image.image_data[base + m] += 128;
                }
            }
        }
    }
    return yuv_image;
}

/*
 * @brief trans_YUV2RGB trans YUV image to RGB image
 * @param yuv_image input yuv file
 * @return ppm_image the calculate result of RGB PPM
 */
// TODO: other math function
PPM_image trans_YUV2RGB(const ColorMode &yuv_image)
{
    PPM_image ppm_image = PPM_image(yuv_image.width, yuv_image.height);
    // check color mode
    if (yuv_image.mode != "YUV")
        return ppm_image;

    int w = yuv_image.width, h = yuv_image.height;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            int base = i * w * 3 + j * 3; // base -> RGB

            double Y = yuv_image.image_data[base];
            double U = yuv_image.image_data[base + 1] - 128;
            double V = yuv_image.image_data[base + 2] - 128;
            // R = Y + 1.13983 * (V - 128)
            ppm_image.image_data[base] = Y + 1.13983 * V;
            // G = Y - 0.39465 * (U - 128) - 0.59060 * (V - 128)
            ppm_image.image_data[base + 1] = Y - 0.39465 * U - 0.59060 * V;
            // B = Y + 2.03211 * (U - 128)
            ppm_image.image_data[base + 2] = Y + 2.03211 * U;
        }
    }
    return ppm_image;
}

/*
 * @brief trans_RGB2YCbCr trans RGB image to YC_bC_r image
 * @param ppm_image input RGB file
 * @return ycbcr_image the calculate result of YC_bC_r image
 */
ColorMode trans_RGB2YCbCr(const PPM_image &ppm_image)
{
    ColorMode ycbcr_image = ColorMode(ppm_image.width, ppm_image.height, "YCbCr");

    int w = ppm_image.width, h = ppm_image.height;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            int base = i * w * 3 + j * 3; // base -> RGB

            int R = ppm_image.image_data[base];
            int G = ppm_image.image_data[base + 1];
            int B = ppm_image.image_data[base + 2];
            // Y
            double Y = ycbcr_image.image_data[base] = 0.299 * R + 0.587 * G + 0.114 * B;
            // C_b = (B - Y) / 2 + 0.58
            ycbcr_image.image_data[base + 1] = (B - Y) / 2 + 0.58;
            // C_r = (R - Y) / 2 + 0.58
            ycbcr_image.image_data[base + 2] = (R - Y) / 2 + 0.58;
        }
    }
    return ycbcr_image;
}