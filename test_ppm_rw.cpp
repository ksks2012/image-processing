#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#include "ppm/ppm_rw.h"

using namespace std;

typedef unsigned char byte;

// TODO: read from header
#define X 320
#define Y 240

int main()
{
	size_t SIZE = X * Y * 3;		   // 3 is for the 3 colour channels; red, green, blue
	byte *image_data = new byte[SIZE]; // Allocating memory for image of size w: 256 & h: 256 pixels & 3 colour channels
	memset(image_data, 0, SIZE); // Setting all allocated memory to value of 0 (ie. black), this will be first 'painted' to image in the Body
	const int width = X, height = Y;

	PPM_image ppm_image = PPM_image();
	if(!ppm_image.ppm_write(image_data))
		cout << "ppm_write error" << endl;

	delete[] image_data;
	image_data = NULL;

	return 0;
}
