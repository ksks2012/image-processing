#include "quality.h"

bool _isComparable(const ImageMatrix &std_image, const ImageMatrix &compared_image)
{
    if (std_image.width != compared_image.width || std_image.height != compared_image.height)
    {
        return false;
    }
    return true;
}

/*
 * @brief cal_PSNR calculate Peak Signal-to-Noise Ratio (PSNR) between std_image and compared_image
 * @param std_image input standard image
 * @param compared_image input compared image
 * @return psnr_value the result of PSNR value, -1 means two image are same
 */
double cal_PSNR(const ImageMatrix &std_image, const ImageMatrix &compared_image)
{
    // TODO: operator
    if (!_isComparable(std_image, compared_image))
    {
        return 0;
    }

    double MSE = 0;
    double psnr_value = 0;

    int w = std_image.width, h = std_image.height;
    int point_extend = std_image.get_point_extend();
    int total_size = w * h * point_extend;
    for (int i = 0; i < total_size; i++)
    {
        int tmp = (compared_image.image_data[i] - std_image.image_data[i]);
        MSE += tmp * tmp;
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
 * @brief cal_SSIM calculate Structural SIMilarity Index (SSIM Index) between std_image and compared_image
 * @param std_image input standard image
 * @param compared_image input compared image
 * @return ssim_value the result of SSIM value
 */
double cal_SSIM(const ImageMatrix &std_image, const ImageMatrix &compared_image)
{
    if (!_isComparable(std_image, compared_image))
    {
        return 0;
    }

    // NOTE: const value (changed)
    const int alpha = 1, beta = 1, gamma = 1, C_1 = 1, C_2 = 1, C_3 = 1;
    double ssim_value = 0;
    double std_avg = 0, compared_avg = 0;
    double std_sd = 0, compared_sd = 0;
    double std_square = 0, compared_square = 0;

    // avg
    int w = std_image.width, h = std_image.height;
    int point_extend = std_image.get_point_extend();
    double std_sum = 0, compared_sum = 0;
    int total_size = w * h * point_extend;
    for (int i = 0; i < total_size; i++)
    {
        std_sum += std_image.image_data[i];
        compared_sum += compared_image.image_data[i];

        std_square += std_image.image_data[i] * std_image.image_data[i];
        compared_square += compared_image.image_data[i] * compared_image.image_data[i];
    }
    std_avg = std_sum / total_size;
    compared_avg = compared_sum / total_size;

    // sd
    std_sd = sqrt(std_square / total_size - std_avg * std_avg);
    compared_sd = sqrt(compared_square / total_size - compared_avg * compared_avg);

    // convariance
    double convariance = 0;
    for (int i = 0; i < total_size; i++)
    {
        convariance += (std_image.image_data[i] - std_avg) * (compared_image.image_data[i] - compared_avg);
    }
    convariance /= (h * w * point_extend - 1);

    // calculate brightness, contrast and structure
    double brightness = (2 * std_avg * compared_avg + C_1) / (std_avg * std_avg + compared_avg * compared_avg + C_1);
    double contrast = (2 * std_sd * compared_sd + C_2) / (std_sd * std_sd + compared_sd * compared_sd + C_2);
    double structure = (convariance + C_3) / (std_sd * compared_sd + C_3);

    ssim_value = pow(brightness, alpha) * pow(contrast, beta) * pow(structure, gamma);

    return ssim_value;
}
