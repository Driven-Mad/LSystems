#ifndef TURTLE_H
#define TURTLE_H // TURTLE_H
#include <iostream>
#include <ngl/Transformation.h>
//------------------------------------------------------------------
/// \file    turtle.h
/// \author  Lloyd Phillips
/// \brief   This is the turtle class to manipulate a "turtle" to create geometric shapes.
//------------------------------------------------------------------

class Turtle
{
public:
    Turtle();
    ~Turtle();

    void moveForwardFullStep();
    void moveForwardHalfStep();
    void moveForwardFullStepUndrawn();
    void moveForwardHalfStepUndrawn();
    void yawLeft();
    void yawRight();
    void pitchUp();
    void pitchDown();
    void rollCW();
    void rollCCW();
    void turnAround();
    void pushOnStack();
    void popOffStack();

    //getters and setters
    void setPosition(ngl::Vec4 p_pos){m_position = p_pos;};
    void setRotation(ngl::Vec4 p_rot){m_rotation = p_rot;};
    void setStoredPosition(ngl::Vec3 p_pos){m_storedStackPosition = p_pos;};
    void setStoredRotation(ngl::Vec3 p_rot){m_storedStackRotation = p_rot;};
    void setStandardUnit(float p_sUnit){m_standardUnit = p_sUnit;};
    void setStandardAngle(float p_angle){m_standardAngle = p_angle;};

    ngl::Vec4 getPosition(){return m_position;};
    ngl::Vec4 getRotation(){return m_rotation;};
    ngl::Vec3 getStoredPosition(){return m_storedStackPosition;};
    ngl::Vec3 getStoredRotation(){return m_storedStackRotation;};
    float getStandardUnit(){return m_standardUnit;};
    float getAngle(){return m_standardAngle;};

    void toggleDrawing(){drawing = !drawing;};

    void update();
    ngl::Transformation m_transformationMatrix;
private:
    ngl::Vec4 m_position;
    ngl::Vec4 m_rotation;
    ngl::Vec3 m_storedStackPosition;
    ngl::Vec3 m_storedStackRotation;
    float m_standardUnit;
    float m_standardAngle;
    bool drawing = true;

};

#endif // !TURTLE_H_
