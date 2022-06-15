#include "pgm_rw.h"

PGM_image::PGM_image()
{
    ASCII_MAGIC = "P2";
    BINARY_MAGIC = "P5";
    POINT_EXTEND = 1;

    this->image_data = nullptr;
    this->width = 0;
    this->height = 0;
    this->SIZE = 0;
}

PGM_image::PGM_image(int width, int height)
{
    ASCII_MAGIC = "P2";
    BINARY_MAGIC = "P5";
    POINT_EXTEND = 1;

    this->magic = "P2";
    this->width = width;
    this->height = height;
    this->max_colour = "255";
    this->SIZE = this->width * this->height;
    this->image_data = new uint8_t[this->SIZE];
    memset(image_data, 0, this->SIZE);
}