#include "Image.h"


Image::Image()
{

}

Image::Image(size_t _width, size_t _height, size_t _depth)
{
    m_pixelDepth = _depth;
    m_width = _width;
    m_height = _height;
    m_data.reset(new Colour [m_width*m_height]);
    // m_data = std::move(t_data);
    clearScreen(Colour(0.5,0.5,0.5));

}

Image::~Image()
{

}

void Image::setPixel(size_t _x, size_t _y, Colour c)
{
    m_data[_x + (_y * m_width)] = c;
}

void Image::clearScreen(Colour c)
{
    for(auto w = 0; w < m_width; w++)
    {
        for (auto h = 0; h < m_height; h++)
        {
           setPixel(w,h,c);
        }
    }
}


unsigned char* Image::get()
{
    //return m_data.get();
    return &m_data.get()->_r;
}
