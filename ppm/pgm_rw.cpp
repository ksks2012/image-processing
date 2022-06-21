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

/*
 * @brief PGM_image copy constructor for deep copy
 * @param copied_image image to be copied
 */
PGM_image::PGM_image(const PGM_image &copied_image)
{
    ASCII_MAGIC = copied_image.ASCII_MAGIC;
    BINARY_MAGIC = copied_image.BINARY_MAGIC;
    POINT_EXTEND = copied_image.POINT_EXTEND;

    this->magic = copied_image.magic;
    this->width = copied_image.width;
    this->height = copied_image.height;
    this->max_colour = copied_image.max_colour;
    this->SIZE = copied_image.SIZE;
    this->image_data = new uint8_t[this->SIZE];
    memcpy(image_data, copied_image.image_data, this->SIZE);
}

/*
 * @brief gen_bit_flat mask the bit flat
 * @param bit specify bit
 * @return bit_flat specify bit flat
 */
PGM_image PGM_image::gen_bit_flat(int bit)
{
    PGM_image bit_flat = PGM_image(*this);
    int mask = 0;
    set_bit(mask, bit);
    for (int i = 0; i < SIZE; i++)
    {
        bit_flat.image_data[i] = (int)bit_flat.image_data[i] & mask;
    }
    return bit_flat;
}