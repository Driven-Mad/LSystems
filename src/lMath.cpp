#include "lMath.h"

#define PI 3.14159265
namespace lMath
{
    // Dot product function
    const float dot(Vec3 a, Vec3 b)
    {
        return float((a.x * b.x) + (a.y * b.y)+ (a.z * b.z));
    }
    // Cross Product function
    const Vec3 cross(Vec3 a, Vec3 b)
    {
        return Vec3((a.y * b.z)-(a.z * b.y),
                    (a.z * b.x)-(a.x * b.z),
                    (a.x * b.y)-(a.y * b.x));
    }
    // Magnitude function
    const float magnitude(Vec3 v)
    {
        return float(sqrtf(dot(v, v)));
    }
    // Normalizing Function
    const Vec3 normalize(Vec3 v)
    {

        float m = magnitude(v);
        return m!=0 ? Vec3(v/m) : Vec3(0,0,0);

    }

    // Dot product function
    const float dot(Vec2 a, Vec2 b)
    {
        return float((a.x * b.x) + (a.y * b.y));
    }
    // Cross Product function
    const Vec2 cross(Vec2 a, Vec2 b)
    {
        return Vec2((a.x * b.y),(a.y * b.x));
    }
    // Magnitude function
    const float magnitude(Vec2 v)
    {
        return float(sqrtf(dot(v, v)));
    }
    // Normalizing Function
    const Vec2 normalize(Vec2 v)
    {
        float m = magnitude(v);
        return m!=0 ? Vec2(v/m) : Vec2(0,0);
    }
    void createTangents(Vec3 normal, Vec3 &tangent)
    {
        Vec3 up = Vec3(0.0f, 1.0f, 0.0f);
        Vec3 forward = Vec3(0.0f, 0.0f, 1.0f);
        //do the cross product between a normal and forward vector
        Vec3 tang1 = lMath::cross(normal, forward);
        //do the cross product between a normal and up vector
        Vec3 tang2 = lMath::cross(normal, up);
        //find the magnitude of them both
        float tang1mag = lMath::magnitude(tang1);
        float tang2mag = lMath::magnitude(tang2);
        //if the forward magnitude is greater than the up magnitude, the tangent is = tangforward
        //else we use the up tangent.
        if (tang1mag > tang2mag)
        {
            tangent = tang1;
        }
        else{
            tangent = tang2;
        }
    }
    Vec3 rotateZaxisByPoint(Vec3 origin, float Angle, Vec3 rotatePoint)
    {
        Vec3 t_vEnd;
        float t_fTranslatedX = rotatePoint.x - origin.x;
        float t_fTranslatedY = rotatePoint.y - origin.y;
        float temp_a =  Angle * PI /180.0f;
        t_vEnd.x =((t_fTranslatedX * cosf(temp_a)) - (t_fTranslatedY * sinf(temp_a))) + origin.x;
        t_vEnd.y = ((t_fTranslatedX * sinf(temp_a)) + (t_fTranslatedY * cosf(temp_a))) + origin.y;
        t_vEnd.z = rotatePoint.z;
        return t_vEnd;
    }

    Vec3 rotateYaxisByPoint(Vec3 origin, float Angle, Vec3 rotatePoint)
    {
        Vec3 t_vEnd;
        float t_fTranslatedX = rotatePoint.x - origin.x;
        float t_fTranslatedZ = rotatePoint.z - origin.z;
        float temp_a =  Angle * PI /180.0f;
        t_vEnd.x =((t_fTranslatedX * cosf(temp_a)) - (t_fTranslatedZ * sinf(temp_a))) + origin.y ;
        t_vEnd.y =rotatePoint.y ;
        t_vEnd.z = ((t_fTranslatedX * sinf(temp_a)) + (t_fTranslatedZ * cosf(temp_a))) + origin.z;
        return t_vEnd;
    }

    Vec3 rotateXaxisByPoint(Vec3 origin, float Angle, Vec3 rotatePoint)
    {
        Vec3 t_vEnd;
        float t_fTranslatedZ = rotatePoint.z - origin.z;
        float t_fTranslatedY = rotatePoint.y - origin.y;
        float temp_a =  Angle * PI /180.0f;
        t_vEnd.x = rotatePoint.x;
        t_vEnd.y = ((t_fTranslatedY * cosf(temp_a)) - (t_fTranslatedZ * sinf(temp_a))) + origin.y;
        t_vEnd.z = ((t_fTranslatedY * sinf(temp_a)) + (t_fTranslatedZ * cosf(temp_a))) + origin.z;
        return t_vEnd;
    }

    float randF(float lowerBound, float higherBound)
    {
        return float( lowerBound + static_cast <float> (rand())/(static_cast <float> (RAND_MAX/(higherBound-lowerBound))));
    }

    void createBiTangents(Vec3 normal, Vec3 tangent, Vec3 &biTangent)
    {
        //normalise both the normal and tangent, do the cross product
        //of the solutions and that gives you the bi-tangent
        biTangent = lMath::cross(lMath::normalize(normal),lMath::normalize(tangent));
    }




}
