#include "ppm/ppm_rw.h"
#include "compare//quality.h"

using namespace std;

void test_cal_PSNR(string std_filename, string compared_filename)
{
    PPM_image std_ppm_image = PPM_image();
    if (std_ppm_image.read(std_filename))
        cout << "read_ppm error" << endl;

    PPM_image compared_ppm_image = PPM_image();
    if (compared_ppm_image.read(compared_filename))
        cout << "read_ppm error" << endl;

    cout << "PSNR: " << cal_PSNR(std_ppm_image, compared_ppm_image) << endl;
}

void test_cal_SSIM(string std_filename, string compared_filename)
{
    PPM_image std_ppm_image = PPM_image();
    if (std_ppm_image.read(std_filename))
        cout << "read_ppm error" << endl;

    PPM_image compared_ppm_image = PPM_image();
    if (compared_ppm_image.read(compared_filename))
        cout << "read_ppm error" << endl;

    cout << "SSIM: " << cal_SSIM(std_ppm_image, compared_ppm_image) << endl;
}

int main(int argc, char **argv)
{
    // test_trans_gray_image(argv[1]);
    test_cal_PSNR(argv[1], argv[2]);
    test_cal_SSIM(argv[1], argv[2]);

    return 0;
}
