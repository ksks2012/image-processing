#include "pgm_rw.h"

PGM_image::PGM_image()
{
    this->image_data = nullptr;
    this->width = 0;
    this->height = 0;
    this->SIZE = 0;
}

PGM_image::PGM_image(int width, int height)
{
    this->magic = "P2";
    this->width = width;
    this->height = height;
    this->max_colour = "255";
    this->SIZE = this->width * this->height;
    this->image_data = new uint8_t[this->SIZE];
    memset(image_data, 0, this->SIZE);
}

PGM_image::~PGM_image()
{
    // if(image_data != NULL)
    //     delete []image_data;
}

/*
 * @brief read read pgm file with input file_name
 * @param file_name name of file to read
 * @return 0 -> success, 1 -> fail
 */
int PGM_image::read(const string file_name)
{
    ifstream input_image;
    input_image.open(file_name + ".pgm", ifstream::binary);

    if (input_image.fail())
    {
        cout << "Unable to read" + file_name + ".pgm" << endl;
        return 1;
    }
    // read header
    input_image >> this->magic;
    input_image.seekg(1, input_image.cur);
    input_image >> this->width >> this->height >> max_colour;

    this->SIZE = this->width * this->height;
    this->image_data = new uint8_t[SIZE];
    memset(image_data, 0, SIZE);
    { // Image Body - inputs image_data the .pgm file to array, creating the image
        for (size_t i = 0; i < SIZE; i++)
        {
            string pixel_str;
            input_image >> pixel_str;
            this->image_data[i] = static_cast<uint8_t>(stoi(pixel_str)); // Sets 3 bytes of colour to each pixel
        }
    }

    input_image.close();

    return 0;
}

/*
 * @brief write_this write class image_data
 * @param file_name name of file to write, default is ""
 * @return 0 -> success, 1 -> fail
 */
int PGM_image::write_this(const string &file_name)
{
    return write(this->image_data, this->width, this->height, this->magic, this->max_colour, file_name);
}

/*
 * @brief write write input image data
 * @param image_data image file data to store
 * @param file_name name of file to write, default is "" and will turn into unix time
 * @return 0 -> success, 1 -> fail
 */
int PGM_image::write(uint8_t *image_data, int width, int height, string magic, string max_colour, string file_name)
{

    if (file_name.size() == 0)
    {
        time_t result = time(nullptr);
        stringstream ss;
        ss << result;
        file_name = ss.str();
    }

    ofstream out_image; // output stream object
    out_image.open(file_name + ".pgm");

    if (out_image.fail())
    {
        cout << "Unable to create" + file_name + ".pgm" << endl;
        return 1;
    }

    // header processor
    {                                                // Image header - Need this to start the image properties
        out_image << magic << endl;                  // Declare that you want to use ASCII colour values
        out_image << width << " " << height << endl; // Declare w & h
        out_image << max_colour << endl;             // Declare max colour ID
    }

    { // Image Body - outputs image_data array to the .pgm file, creating the image
        for (int i = 0; i < height; i ++)
        {
            for (int j = 0; j < width; j ++)
            {
                out_image << std::to_string(static_cast<uint8_t>(image_data[i * width + j])) << endl;
            }
        }
    }

    out_image.close();

    return 0;
}