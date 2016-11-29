#ifndef IMAGE_H_
#define IMAGE_H_
#include <iostream>
#include <memory>

struct Colour
{
    Colour():_r(0), _g(0), _b(0){};
    Colour(unsigned char r, unsigned char g, unsigned char b):_r(r), _g(g), _b(b){};
    unsigned char _r;
    unsigned char _g;
    unsigned char _b;
};


class Image{

public:

    Image(); //Default Const
    Image(size_t _width, size_t _height, size_t _depth);
    ~Image(); //Default Destruct

    void setPixel(size_t _x, size_t _y, Colour c);
    void clearScreen(Colour c);

    unsigned char* get();

    void setWidth(size_t _w)  {m_width = _w;};
    void setHeight(size_t _h) {m_height = _h;};
    void setPixelDepth(size_t _pD) {m_pixelDepth = _pD;};

    size_t getWidth() const {return m_width;};
    size_t getHeight() const {return m_height;};
    size_t getPixelDepth() const {return m_pixelDepth;};

private:
    size_t m_width, m_height, m_pixelDepth;
    std::unique_ptr<Colour[]> m_data; //RGB

};

#endif
