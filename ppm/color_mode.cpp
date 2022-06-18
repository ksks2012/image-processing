#include "color_mode.h"

ColorMode::ColorMode()
{
    POINT_EXTEND = 3;
}

ColorMode::ColorMode(int width, int height, string mode)
{
    POINT_EXTEND = 3;

    this->width = width;
    this->height = height;
    this->mode = mode;
    this->SIZE = this->width * this->height * POINT_EXTEND;
    this->image_data = new double[this->SIZE];
    fill_n(image_data, this->SIZE, 0);
}

ColorMode::~ColorMode()
{
    if (image_data != nullptr)
        delete image_data;
}

int ColorMode::read(string file_name)
{
    return 0;
}

int ColorMode::write_this(const string &file_name)
{
    return 0;
}

int ColorMode::write(uint8_t *image_data, int width, int height, string file_name)
{
    return 0;
}

void ColorMode::print()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
           for (int k = 0; k < POINT_EXTEND; k++)
            {
                cout << round(image_data[i * width * POINT_EXTEND + j * POINT_EXTEND + k]) << " ";
            }
            cout << "| ";
        }
        cout << endl;
    }
}