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

/*
 * @brief cut_color_flat cut image to R, G, B flat
 * @return 0 -> success, 1 -> fail
 */
int PPM_image::cut_color_flat(const string &file_name)
{
    PPM_image R_flat = PPM_image(width, height);
    PPM_image G_flat = PPM_image(width, height);
    PPM_image B_flat = PPM_image(width, height);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int base = i * width * 3 + j * 3; // base -> RGB      
            R_flat.image_data[base] = image_data[base];
            G_flat.image_data[base + 1] = image_data[base + 1];
            B_flat.image_data[base + 2] = image_data[base + 2];
        }
    }

    R_flat.write_this("R_flat" + file_name + ".ppm");
    G_flat.write_this("G_flat" + file_name + ".ppm");
    B_flat.write_this("B_flat" + file_name + ".ppm");

    return 0;
}