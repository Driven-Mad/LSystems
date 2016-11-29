#ifndef Vec3_H
#define Vec3_H
//------------------------------------------------------------------
/// \file    Vec3.h
/// \author  Lloyd Phillips
/// \brief   This is the Vec3 struct
//------------------------------------------------------------------

struct Vec3{
public:
    /// \brief Vector3 Constructors, takes 0,1,3,4 arg
    Vec3() : x(0.0f), y(0.0f), z(0.0f), w(1.0f) {}
    Vec3(float a) : x(a), y(a), z(a), w(1.0f) {}
    Vec3(float a, float b, float c) : x(a), y(b),z(c), w(1.0f){}
    Vec3(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
    ~Vec3(){}
    /// \brief Vector Co-ords x,y,z (sometimes w)
    float x;
    float y;
    float z;
    float w;
    /// \brief += operator
    const Vec3& operator +=(const Vec3& v);
    /// \brief -= operator
    const Vec3& operator -=(const Vec3& v);
    /// \brief *= operator
    const Vec3& operator *=(const Vec3& v);
    /// \brief /= operator
    const Vec3& operator /=(const Vec3& v);
    /// \brief += operator with floats
    const Vec3& operator +=(const float& f);
    /// \brief -= operator with floats
    const Vec3& operator -=(const float& f);
    /// \brief *= operator with floats
    const Vec3& operator *=(const float& f);
    /// \brief /= operator with floats
    const Vec3& operator /=(const float& f);
    /// \brief == operator
    const bool operator ==(const Vec3& v);

private:
};
/// \brief Addition Operations for Vec 3's
inline const Vec3 operator + (const Vec3 &a, const Vec3 &b)
{
    return Vec3(a.x + b.x,a.y + b.y,a.z + b.z);
}
/// \brief Addition Operations for Floats
inline const Vec3 operator + (const Vec3 &v, const float &f)
{
    return Vec3(v.x + f,v.y + f,v.z + f);
}
/// \brief Subtraction Operations for Vec 3's
inline const Vec3 operator - (const Vec3 &a, const Vec3 &b)
{
    return Vec3(a.x + -b.x,a.y + -b.y, a.z + -b.z);
}
/// \brief Subtraction Operations for Floats
inline const Vec3 operator - (const Vec3 &v, const float &f)
{
    return Vec3(v.x + -f,v.y + -f,v.z + -f);
}
/// \brief Multiplication Operations for Vec 3's
inline const Vec3 operator * (const Vec3 &a, const Vec3 &b)
{
    return Vec3(a.x * b.x,a.y * b.y,a.z * b.z);
}
/// \brief Multiplication Operations for Floats
inline const Vec3 operator * (const Vec3 &v, const float &f)
{
    return Vec3(v.x * f,v.y * f,v.z * f);
}
/// \brief Divide Operations for Vec 2's
inline const Vec3 operator / (const Vec3 &a, const Vec3 &b)
{
    return Vec3(a.x / b.x,a.y / b.y,a.z / b.z);
}
/// \brief Divide operator with floats and Vec3's
inline const Vec3 operator / (const Vec3 &v, const float &f)
{
    return Vec3(v.x / f,v.y / f, v.z / f);
}
/// \brief Negate Operations for Vec 3's
inline const Vec3 operator -(const Vec3 v)
{
    return Vec3(-v.x,-v.y, -v.z);
}
#endif ///!Vec3_H
