#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#include "ppm/image_matrix.h"
#include "ppm/ppm_rw.h"
#include "ppm/pgm_rw.h"
#include "transform/transform.h"

using namespace std;

void test_trans_gray_image(string file_name) {
	PPM_image ppm_image = PPM_image();
	if(ppm_image.read(file_name))
		cout << "read_ppm error" << endl;

	ImageMatrix pgm_image = trans_gray_image(ppm_image);
	pgm_image.write_this("gray_" + file_name);
}

void test_trans_HSV_image(string file_name) {
	PPM_image ppm_image = PPM_image();
	if(ppm_image.read(file_name))
		cout << "read_ppm error" << endl;

	double *hsv_image = trans_HSV_image(ppm_image);
	// hsv_ppm_image.write_this("hsv_" + file_name);
}

int main(int argc, char ** argv)
{
	// test_trans_gray_image(argv[1]);
	test_trans_HSV_image(argv[1]);

	return 0;
}
