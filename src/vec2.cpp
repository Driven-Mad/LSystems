#include "vec2.h"
#include <math.h>
//Vector2 Constructors, takes 0,2,3 arg


//== opertion for Vec2
const bool Vec2::operator ==(const Vec2& v)
{
    (x == v.x && y == v.y && w == v.w) ? true : false;
}
//+= operation for Vec2
const Vec2& Vec2::operator +=(const Vec2& v)
{
    x += v.x;
    y += v.y;
    w = 1.0f;
    return *this;
}
//-= operation for Vec2
const Vec2& Vec2::operator -=(const Vec2& v)
{
    x -= v.x;
    y -= v.y;
    w = 1.0f;
    return *this;
}
//*= operation for Vec2
const Vec2& Vec2::operator *=(const Vec2& v)
{
    x *= v.x;
    y *= v.y;
    w = 1.0f;
    return *this;
}
// /= operation for Vec2
const Vec2& Vec2::operator /=(const Vec2& v)
{
    x /= v.x;
    y /= v.y;
    w = 1.0f;
    return *this;
}
// += operation for Vec2 + float
const Vec2& Vec2::operator +=(const float& f)
{
    x += f;
    y += f;
    w = 1.0f;
    return *this;
}
// -= operation for Vec2 + float
const Vec2& Vec2::operator -=(const float& f)
{
    x -= f;
    y -= f;
    w = 1.0f;
    return *this;
}
// *= operation for Vec2 + float
const Vec2& Vec2::operator *=(const float& f)
{
    x *= f;
    y *= f;
    w = 1.0f;
    return *this;
}
// /= operation for Vec2 + float
const Vec2& Vec2::operator /=(const float& f)
{
    x /= f;
    y /= f;
    w = 1.0f;
    return *this;
}

