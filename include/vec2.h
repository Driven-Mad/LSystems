#ifndef VEC2_H
#define VEC2_H
//------------------------------------------------------------------
/// \file    Vec2.h
/// \author  Lloyd Phillips
/// \brief   This is the Vec2 struct
//------------------------------------------------------------------

struct Vec2{
public:
    /// \brief Vector2 Constructors, takes 0,2,3 arg
    Vec2() : x(0.0f), y(0.0f), w(1.0f) {}
    Vec2(float a, float b) : x(a), y(b), w(1.0f){}
    Vec2(float a, float b, float c) : x(a), y(b), w(c) {}
    ~Vec2(){}
    /// \brief Vector Co-ords x,y, (sometimes w)
    float x;
    float y;
    float w;
    /// \brief += operator
    const Vec2& operator +=(const Vec2& v);
    /// \brief -= operator
    const Vec2& operator -=(const Vec2& v);
    /// \brief *= operator
    const Vec2& operator *=(const Vec2& v);
    /// \brief /= operator
    const Vec2& operator /=(const Vec2& v);
    /// \brief += operator with floats
    const Vec2& operator +=(const float& f);
    /// \brief -= operator with floats
    const Vec2& operator -=(const float& f);
    /// \brief *= operator with floats
    const Vec2& operator *=(const float& f);
    /// \brief /= operator with floats
    const Vec2& operator /=(const float& f);
    /// \brief == operator
    const bool operator ==(const Vec2& v);
    /// \brief dot product calculations

private:
};
/// \brief Addition Operations for Vec 2's
inline const Vec2 operator + (const Vec2 &a, const Vec2 &b)
{
    return Vec2(a.x + b.x,a.y + b.y);
}
/// \brief Addition Operations for Floats
inline const Vec2 operator + (const Vec2 &v, const float &f)
{
    return Vec2(v.x + f,v.y + f);
}
/// \brief Subtraction Operations for Vec 2's
inline const Vec2 operator - (const Vec2 &a, const Vec2 &b)
{
    return Vec2(a.x + -b.x,a.y + -b.y);
}
/// \brief Subtraction Operations for Floats
inline const Vec2 operator - (const Vec2 &v, const float &f)
{
    return Vec2(v.x + -f,v.y + -f);
}
/// \brief Multiplication Operations for Vec 2's
inline const Vec2 operator * (const Vec2 &a, const Vec2 &b)
{
    return Vec2(a.x * b.x,a.y * b.y);
}
/// \brief Multiplication Operations for Floats
inline const Vec2 operator * (const Vec2 &v, const float &f)
{
    return Vec2(v.x * f,v.y * f);
}
/// \brief Divide Operations for Vec 2's
inline const Vec2 operator / (const Vec2 &a, const Vec2 &b)
{
    return Vec2(a.x / b.x,a.y / b.y);
}
/// \brief Divide operator with floats and Vec2's
inline const Vec2 operator / (const Vec2 &v, const float &f)
{
    return Vec2(v.x / f,v.y / f);
}
/// \brief Negate Operations for Vec 2's
inline const Vec2 operator -(const Vec2 v)
{
    return Vec2(-v.x,-v.y);
}
#endif ///!VEC2_H
