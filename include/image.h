#ifndef IMAGE_H
#define IMAGE_H //IMAGE_H
#include <iostream>
#include <memory>
//--------------------------------------------------------------------------------------------------------------------------
/// @file Image.h
/// @brief This is the image class to store pixels.
/// @author Lloyd Phillips
/// @version 1.0
/// @date 29/11/2016
/// @class Image
/// @brief The class that stores pixel data.
/// @struct Colour
/// @brief colour structure, stores R,G,B value.
//--------------------------------------------------------------------------------------------------------------------------
struct Colour
{
    Colour():_r(0), _g(0), _b(0){}
    Colour(unsigned char r, unsigned char g, unsigned char b):_r(r), _g(g), _b(b){}
    unsigned char _r;
    unsigned char _g;
    unsigned char _b;
};


class Image{

public:
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief ctor for Image class
    //----------------------------------------------------------------------------------------------------------------------
    Image();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief overloaded ctor for Image class
    //----------------------------------------------------------------------------------------------------------------------
    Image(size_t _width, size_t _height, size_t _depth);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief dtor for turtle class
    //----------------------------------------------------------------------------------------------------------------------
    ~Image();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief sets a signle pixel by colour
    /// @param _x the X position of the pixel
    /// @param _y the Y position of the pixel
    /// @param _c the colour you want to set the pixel to.
    //----------------------------------------------------------------------------------------------------------------------
    void setPixel(size_t _x, size_t _y, Colour _c);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief clears the screen to specified colour
    /// @param _c the colour you want to change the screen too.
    //----------------------------------------------------------------------------------------------------------------------
    void clearScreen(Colour _c);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief returns the shared pointers data.
    //----------------------------------------------------------------------------------------------------------------------
    unsigned char* get();

    //----------------------------------------------------------------------------------------------------------------------
    /// @brief sets the width of the image
    /// @param _w the size that you want to set the images width too.
    //----------------------------------------------------------------------------------------------------------------------
    void setWidth(size_t const& _w)  {m_width = _w;}
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief sets the height of the image
    /// @param _h the size that you want to set the images height too.
    //----------------------------------------------------------------------------------------------------------------------
    void setHeight(size_t const& _h) {m_height = _h;}
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief sets the depth of the image
    /// @param _d the size that you want to set the images depth too.
    //----------------------------------------------------------------------------------------------------------------------
    void setPixelDepth(size_t const&  _d) {m_pixelDepth = _d;}

    //----------------------------------------------------------------------------------------------------------------------
    /// @brief retrieves the width of the image
    /// @return m_width the width of the image
    //----------------------------------------------------------------------------------------------------------------------
    const size_t &getWidth() const {return m_width;}
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief retrieves the height of the image
    /// @return m_height the height of the image
    //----------------------------------------------------------------------------------------------------------------------
    const size_t &getHeight() const {return m_height;}
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief retrieves the pixel depth of the image
    /// @return m_pixelDepth the pixel depth of the image
    //----------------------------------------------------------------------------------------------------------------------
    const size_t &getPixelDepth() const {return m_pixelDepth;}

private:
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief attribute of an Image
    //----------------------------------------------------------------------------------------------------------------------
    size_t m_width, m_height, m_pixelDepth;
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief storage pointer for image data.
    //----------------------------------------------------------------------------------------------------------------------
    std::unique_ptr<Colour[]> m_data;

};

#endif //!IMAGE_H
