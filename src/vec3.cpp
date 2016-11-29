#include "vec3.h"
#include <math.h>
//Vector2 Constructors, takes 0,2,3 arg


//== opertion for Vec3
const bool Vec3::operator ==(const Vec3& v)
{
    (x == v.x && y == v.y && z == v.z && w == v.w ) ? true : false;
}
//+= operation for Vec3
const Vec3& Vec3::operator +=(const Vec3& v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    w = 1.0f;
    return *this;
}
//-= operation for Vec3
const Vec3& Vec3::operator -=(const Vec3& v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    w = 1.0f;
    return *this;
}
//*= operation for Vec3
const Vec3& Vec3::operator *=(const Vec3& v)
{
    x *= v.x;
    y *= v.y;
    z *= v.z;
    w = 1.0f;
    return *this;
}
// /= operation for Vec3
const Vec3& Vec3::operator /=(const Vec3& v)
{
    x /= v.x;
    y /= v.y;
    z /= v.z;
    w = 1.0f;
    return *this;
}
// += operation for Vec3 + float
const Vec3& Vec3::operator +=(const float& f)
{
    x += f;
    y += f;
    z += f;
    w = 1.0f;
    return *this;
}
// -= operation for Vec3 + float
const Vec3& Vec3::operator -=(const float& f)
{
    x -= f;
    y -= f;
    z -= f;
    w = 1.0f;
    return *this;
}
// *= operation for Vec3 + float
const Vec3& Vec3::operator *=(const float& f)
{
    x *= f;
    y *= f;
    z *= f;
    w = 1.0f;
    return *this;
}
// /= operation for Vec3 + float
const Vec3& Vec3::operator /=(const float& f)
{
    x /= f;
    y /= f;
    z /= f;
    w = 1.0f;
    return *this;
}
