#include "image.h"


Image::Image()
{
    //default @ 1080 x 720 cleared out to grey.
    m_pixelDepth = 3;
    m_width = 1080;
    m_height = 720;
    m_data.reset(new Colour [m_width*m_height]);
    clearScreen(Colour(0.5,0.5,0.5));

}

Image::Image(size_t _width, size_t _height, size_t _depth)
{
    //width x height cleared out to grey.
    m_pixelDepth = _depth;
    m_width = _width;
    m_height = _height;
    m_data.reset(new Colour [m_width*m_height]);
    clearScreen(Colour(0.5,0.5,0.5));
}

Image::~Image()
{

    m_data.release();
}

void Image::setPixel(size_t _x, size_t _y, Colour _c)
{
    //set a single pixel to colour provided at X,Y position
    m_data[_x + (_y * m_width)] = _c;
}

void Image::clearScreen(Colour _c)
{
    //clears out the entire array of pixels to a single colour.
    for(size_t w = 0; w < m_width; w++)
    {
        for (size_t h = 0; h < m_height; h++)
        {
           setPixel(w,h,_c);
        }
    }
}


unsigned char* Image::get()
{
    //returns our array of colours.
    return &m_data.get()->_r;
}
