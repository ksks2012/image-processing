#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>

#include "ppm/color_mode.h"
#include "ppm/image_matrix.h"
#include "ppm/ppm_rw.h"
#include "ppm/pgm_rw.h"
#include "transform/transform.h"

using namespace std;

void test_trans_gray_image(string file_name)
{
    PPM_image ppm_image = PPM_image();
    if (ppm_image.read(file_name))
        cout << "read_ppm error" << endl;

    ImageMatrix pgm_image = trans_PPM2PGM(ppm_image);
    pgm_image.write_this("gray_" + file_name);
}

void test_trans_RGB2HSV(string file_name)
{
    PPM_image ppm_image = PPM_image();
    if (ppm_image.read(file_name))
        cout << "read_ppm error" << endl;

    double *hsv_image = trans_RGB2HSV(ppm_image);
    // hsv_ppm_image.write_this("hsv_" + file_name);
}

void test_trans_RGB2YIQ(string file_name)
{
    uint8_t test_data[12] = {10, 20, 40, 40, 30, 20, 100, 150, 200, 50, 250, 120};
    PPM_image ppm_image = PPM_image(2, 2);
    ppm_image.image_data = test_data;

    ColorMode yiq_image = trans_RGB2YIQ(ppm_image);
    yiq_image.print();

    int ans[12] = {19, -12, 4, 32, 9, -1, 141, -46, 5, 175, -77, -83};

    for (size_t i = 0; i < sizeof(ans) / sizeof(int); i++)
    {
        if (round(yiq_image.image_data[i]) != ans[i])
        {
            cout << "error value " + to_string(round(yiq_image.image_data[i])) + " != " + to_string(ans[i]) << endl;
        }
    }
}

void test_trans_RGB2YUV(string file_name)
{
    cout << "test_trans_RGB2YUV:" << endl;
    uint8_t test_data[12] = {10, 20, 40, 40, 30, 20, 100, 150, 200, 50, 250, 120};
    PPM_image ppm_image = PPM_image(2, 2);
    ppm_image.image_data = test_data;

    ColorMode yuv_image = trans_RGB2YUV(ppm_image);
    yuv_image.print();

    int ans[12] = {19, 140, 121, 32, 121, 134, 141, 161, 99, 175, 97, 39};

    for (size_t i = 0; i < sizeof(ans) / sizeof(int); i++)
    {
        if (round(yuv_image.image_data[i]) != ans[i])
        {
            cout << "error value " + to_string(round(yuv_image.image_data[i])) + " != " + to_string(ans[i]) << endl;
        }
    }
}

void test_trans_YUV2RGB(string file_name)
{
    cout << "test_trans_YUV2RGB:" << endl;
    uint8_t test_data[12] = {10, 20, 40, 40, 30, 20, 100, 150, 200, 50, 250, 120};
    PPM_image ppm_image = PPM_image(2, 2);
    ppm_image.image_data = test_data;

    ColorMode yuv_image = trans_RGB2YUV(ppm_image);
    PPM_image new_ppm_image = trans_YUV2RGB(yuv_image);
    new_ppm_image.print();
    int ans[12] = {11, 18, 43, 38, 31, 18, 107, 144, 208, 73, 240, 111};

    for (size_t i = 0; i < sizeof(test_data) / sizeof(int); i++)
    {
        if (new_ppm_image.image_data[i] != ans[i])
        {
            cout << "error value " + to_string(new_ppm_image.image_data[i]) + " != " + to_string(ans[i]) << endl;
        }
    }
}

void test_trans_RGB2YCbCr(string file_name)
{
    cout << "test_trans_RGB2YCbCr:" << endl;
    uint8_t test_data[12] = {10, 20, 40, 40, 30, 20, 100, 150, 200, 50, 250, 120};
    PPM_image ppm_image = PPM_image(2, 2);
    ppm_image.image_data = test_data;

    ColorMode ycbcr_image = trans_RGB2YCbCr(ppm_image);
    ycbcr_image.print();
    int ans[12] = {19, 11, -4, 32, 15, 5, 141, 30, -20, 175, -27, -62};

    for (size_t i = 0; i < sizeof(test_data) / sizeof(int); i++)
    {
        if (round(ycbcr_image.image_data[i]) != ans[i])
        {
            cout << "error value " + to_string(round(ycbcr_image.image_data[i])) + " != " + to_string(ans[i]) << endl;
        }
    }
}

int main(int argc, char **argv)
{
    test_trans_gray_image(argv[1]);
    test_trans_RGB2HSV(argv[1]);
    test_trans_RGB2YIQ(argv[1]);
    test_trans_RGB2YUV(argv[1]);
    test_trans_YUV2RGB(argv[1]);
    test_trans_RGB2YCbCr(argv[1]);

    return 0;
}
