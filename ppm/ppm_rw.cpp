#include "ppm_rw.h"

PPM_image::PPM_image()
{
    this->SIZE = X * Y * 3;
    this->image_data = new byte[SIZE];
}

PPM_image::~PPM_image()
{
    // if(image_data)
    //     delete []image_data;
}

// TODO:
int PPM_image::ppm_read(string) {
    return 0;
}

/*
 * @param image_data image file data to store
 * @param file_name name of file, default is unix time
 */
int PPM_image::ppm_write(byte *image_data, string file_name)
{
    
    if (file_name.size() == 0)
    {
        time_t result = time(nullptr);
        stringstream ss;
        ss << result;
        file_name = ss.str();
    }

    ofstream out_image; // output stream object
    out_image.open(file_name + ".ppm");

    if (out_image.fail())
    {
        cout << "Unable to create image.ppm" << endl;
        return 1;
    }

    const int width = X, height = Y;

    // TODO: header processor
    { //Image header - Need this to start the image properties
		out_image << "P3" << endl;						//Declare that you want to use ASCII colour values
		out_image << width << " " << height << endl;		//Declare w & h
		out_image << "255" << endl;						//Declare max colour ID
	}

    { // Image Body - outputs image_data array to the .ppm file, creating the image
        for (size_t x = 0; x < SIZE; x++)
        {
            int value = image_data[x]; // Sets value as an integer, not a character value
            out_image << value << " " << endl;		//Sets 3 bytes of colour to each pixel
        }
    }

    out_image.close();
    // delete []image_data;

    return 0;
}