#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#include "ppm/ppm_rw.h"

using namespace std;

// TODO: read from header
#define X 320
#define Y 240

void test_ppm_write()
{
    size_t SIZE = X * Y * 3;				 // 3 is for the 3 colour channels; red, green, blue
    uint8_t *image_data = new uint8_t[SIZE]; // Allocating memory for image of size w: 256 & h: 256 pixels & 3 colour channels
    memset(image_data, 0, SIZE);			 // Setting all allocated memory to value of 0 (ie. black), this will be first 'painted' to image in the Body

    PPM_image ppm_image = PPM_image();
    if (ppm_image.write(image_data, X, Y, "P3"))
        cout << "ppm_write error" << endl;

    delete[] image_data;
    image_data = NULL;
}

void test_ppm_read(PPM_image &ppm_image, string file_name)
{
    if (ppm_image.read(file_name))
        cout << "read_ppm error" << endl;
}

void test_ppm_write_this(PPM_image &ppm_image, string file_name)
{
    ppm_image.write_this("o_" + file_name);
}

int main(int argc, char **argv)
{
    test_ppm_write();

    PPM_image ppm_image = PPM_image();
    test_ppm_read(ppm_image, argv[1]);
    test_ppm_write_this(ppm_image, argv[1]);

    return 0;
}
