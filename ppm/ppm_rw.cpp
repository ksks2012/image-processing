#include "ppm_rw.h"

PPM_image::PPM_image()
{
    this->image_data = nullptr;
    this->width = 0;
    this->height = 0;
    this->SIZE = 0;
}

PPM_image::PPM_image(int width, int height)
{
    this->magic = "P3";
    this->width = width;
    this->height = height;
    this->max_colour = "255";
    this->SIZE = this->width * this->height;
    this->image_data = new uint8_t[this->SIZE];
    memset(image_data, 0, this->SIZE);
}

PPM_image::~PPM_image()
{
    // if(image_data != NULL)
    //     delete []image_data;
}

/*
 * @brief read read ppm file with input file_name
 * @param file_name name of file to read
 * @return 0 -> success, 1 -> fail
 */
int PPM_image::read(const string file_name)
{
    ifstream input_image;
    input_image.open(file_name + ".ppm", ifstream::binary);

    if (input_image.fail())
    {
        cout << "Unable to read" + file_name + ".ppm" << endl;
        return 1;
    }
    // read header
    input_image >> this->magic;
    input_image.seekg(1, input_image.cur);
    input_image >> this->width >> this->height >> max_colour;

    this->SIZE = this->width * this->height * 3;
    this->image_data = new uint8_t[SIZE];
    if (magic == "P3")
    { // Image Body - inputs image_data the .ppm file to array, creating the image
        for (size_t i = 0; i < SIZE; i++)
        {
            string pixel_str;
            input_image >> pixel_str;
            this->image_data[i] = static_cast<uint8_t>(stoi(pixel_str)); // Sets 3 bytes of colour to each pixel
        }
    }
    else if (magic == "P6")
    {
        input_image.seekg(1, input_image.cur);
        input_image.read(reinterpret_cast<char *>(image_data), SIZE);
    }
    else
    {
        return _print_error_magic(magic);
    }

    input_image.close();

    return 0;
}

/*
 * @brief write_this write class image_data
 * @param file_name name of file to write, default is ""
 * @return 0 -> success, 1 -> fail
 */
int PPM_image::write_this(const string &file_name)
{
    return write(this->image_data, this->width, this->height, this->magic, this->max_colour, file_name);
}

/*
 * @brief write write input image data
 * @param image_data image file data to store
 * @param file_name name of file to write, default is "" and will turn into unix time
 * @return 0 -> success, 1 -> fail
 */
int PPM_image::write(uint8_t *image_data, int width, int height, string magic, string max_colour, string file_name)
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
        cout << "Unable to create" + file_name + ".ppm" << endl;
        return 1;
    }

    // header processor
    {                                                // Image header - Need this to start the image properties
        out_image << magic << endl;                  // Declare that you want to use ASCII colour values
        out_image << width << " " << height << endl; // Declare w & h
        out_image << max_colour << endl;             // Declare max colour ID
    }

    if (magic == "P3")
    { // Image Body - outputs image_data array to the .ppm file, creating the image
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width * 3; j++)
            {
                out_image << to_string(static_cast<uint8_t>(image_data[i * width * 3 + j])) << endl;
            }
        }
    }
    else if (magic == "P6")
    {
        out_image.write(reinterpret_cast<char *>(image_data), SIZE);
    }
    else
    {
        return _print_error_magic(magic);
    }

    out_image.close();

    return 0;
}

/*
 * @brief _print_error_magic print error magic header
 * @param magic error magic header
 * @return 0 -> success, 1 -> fail
 */
int PPM_image::_print_error_magic(string magic) {
    cout << "Unrecognized PPM format" << endl;
    cout << "Got PPM magic number: " << magic << endl;
    cout << "PPM magic number should be either P3 or P6" << endl;
    return 1;
}