#ifndef LMATH_H
#define LMATH_H
//------------------------------------------------------------------
/// \file    Utilities.h
/// \author  Lloyd Phillips
/// \brief   This is the utilities namespace
//------------------------------------------------------------------
#include<iostream>
#include<vector>
#include <math.h>
#include "vec2.h"
#include "vec3.h"

///Namespace util has multiple random functions to use.
namespace lMath
{
    /// \brief creates tangents, taking in a normal, and applying the tangent directly the the specified container.
    void createTangents(Vec3 normal, Vec3 &tangent);

    /// \brief creates bitangents, taking in a normal and a tangent, and applying the bitangent directly the the specified container.
    void createBiTangents(Vec3 normal, Vec3 tangent, Vec3 &biTangent);

    /// \brief rotates about the Z Axis
    /// \returns vec3
    Vec3 rotateZaxisByPoint(Vec3 origin, float Angle, Vec3 rotatePoint);

    /// \brief rotates about the X Axis
    /// \returns vec3
    Vec3 rotateXaxisByPoint(Vec3 origin, float Angle, Vec3 rotatePoint);

    /// \brief random float between 2 floating point numbers
    /// \returns vec3
    float randF(float lowerBound, float higherBound);

    const float dot(Vec2 a, Vec2 b);
    /// \brief cross product calculations
    const Vec2 cross(Vec2 a, Vec2 b);
    /// \brief Magnitude product calculations
    const float magnitude(Vec2 v);
    /// \brief Normalize product calculations
    const Vec2 normalize(Vec2 v);

    /// \brief dot product calculations
    const float dot(Vec3 a, Vec3 b);
    /// \brief cross product calculations
    const Vec3 cross(Vec3 a, Vec3 b);
    /// \brief Magnitude product calculations
    const float magnitude(Vec3 v);
    /// \brief Normalize product calculations
    const Vec3 normalize(Vec3 v);
}
#endif ///!LMATH_H
