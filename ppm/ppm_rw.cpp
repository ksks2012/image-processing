#include "ppm_rw.h"

PPM_image::PPM_image()
{
    ASCII_MAGIC = "P3";
    BINARY_MAGIC = "P6";
    POINT_EXTEND = 3;

    this->image_data = nullptr;
    this->width = 0;
    this->height = 0;
    this->SIZE = 0;
}

PPM_image::PPM_image(int width, int height)
{
    ASCII_MAGIC = "P3";
    BINARY_MAGIC = "P6";
    POINT_EXTEND = 3;

    this->magic = "P3";
    this->width = width;
    this->height = height;
    this->max_colour = "255";
    this->SIZE = this->width * this->height * POINT_EXTEND;
    this->image_data = new uint8_t[this->SIZE];
    memset(image_data, 0, this->SIZE);
}