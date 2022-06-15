#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#include "ppm/pgm_rw.h"

using namespace std;

// TODO: read from header
#define X 320
#define Y 240

void test_pgm_write() {
	size_t SIZE = X * Y;		   // 1 is for the 1 colour channels; red, green, blue
	uint8_t *image_data = new uint8_t[SIZE]; // Allocating memory for image of size w: 256 & h: 256 pixels & 3 colour channels
	memset(image_data, 0, SIZE); // Setting all allocated memory to value of 0 (ie. black), this will be first 'painted' to image in the Body

	PGM_image pgm_image = PGM_image();
	if(pgm_image.write(image_data, X, Y, "P2"))
		cout << "pgm_write error" << endl;

	delete[] image_data;
	image_data = NULL;
}

void test_pgm_read(PGM_image &pgm_image, string file_name) {
	if(pgm_image.read(file_name))
		cout << "read_pgm error" << endl;
}

void test_pgm_write_this(PGM_image &pgm_image, string file_name) {
	pgm_image.write_this("o_" + file_name);
}

int main(int argc, char ** argv)
{
	test_pgm_write();
	
	PGM_image pgm_image = PGM_image();
	test_pgm_read(pgm_image, argv[1]);
	test_pgm_write_this(pgm_image, argv[1]);

	return 0;
}
