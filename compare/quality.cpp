#include "quality.h"

/*
 * @brief cal_PSNR calculate Peak Signal-to-Noise Ratio (PSNR) between std_image and compared_image
 * @param std_image input standard image
 * @param compared_image input compared image
 * @return psnr_value the result of PSNR value, -1 means two image are same
 */
double cal_PSNR(const ImageMatrix &std_image, const ImageMatrix &compared_image)
{
    // TODO: operator
    if (std_image.width != compared_image.width || std_image.height != compared_image.height)
    {
        return 0;
    }

    double MSE = 0;
    double psnr_value = 0;

    int w = std_image.width, h = std_image.height;
    int point_extend = std_image.get_point_extend();
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            int base = i * w * 3 + j * 3;
            for (int k = 0; k < point_extend; k++) {
                int tmp = (compared_image.image_data[base + k] - std_image.image_data[base + k]);
                MSE += tmp * tmp;
            }
        }
    }
    MSE = MSE / (w * h * point_extend);

    if (MSE == 0)
    {
        return -1;
    }

    psnr_value = 10 * log10(255 * 255 / MSE);

    return psnr_value;
}

/*
 * @brief cal_PSNR calculate Structural SIMilarity Index (SSIM Index) between std_image and compared_image
 * @param std_image input standard image
 * @param compared_image input compared image
 * @return ssim_value the result of SSIM value
 */
double cal_SSIM(const ImageMatrix &std_image, const ImageMatrix &compared_image)
{
    double ssim_value = 0;
    return ssim_value;
}
