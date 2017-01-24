#ifndef TURTLE_H
#define TURTLE_H // TURTLE_H
#include <iostream>
#include <ngl/Transformation.h>
//--------------------------------------------------------------------------------------------------------------------------
/// @file turtle.h
/// @brief This is the turtle class to manipulate a "turtle" to create geometric shapes.
/// @author Lloyd Phillips
/// @version 0.3
/// @date 24/01/17
/// Revision History:
/// Currently in working progress, most is working accept pop on & off, only simple commands have been
/// issued none have been overloaded to allow for the overriding of global variables.
/// @class Turtle
/// @brief The class that manipulates itself to move like a turtle using commands.
//--------------------------------------------------------------------------------------------------------------------------

class Turtle
{
public:
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief ctor for turtle class
    //----------------------------------------------------------------------------------------------------------------------
    Turtle();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief dtor for turtle class
    //----------------------------------------------------------------------------------------------------------------------
    ~Turtle();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Moves forward by one full length and sets draw flag to true.
    //----------------------------------------------------------------------------------------------------------------------
    void moveForwardFullStep();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Moves forward by one half length and sets draw flag to true.
    //----------------------------------------------------------------------------------------------------------------------
    void moveForwardHalfStep();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Moves forward by one full length and sets draw flag to false.
    //----------------------------------------------------------------------------------------------------------------------
    void moveForwardFullStepUndrawn();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Moves forward by one half length and sets draw flag to false.
    //----------------------------------------------------------------------------------------------------------------------
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

    void setPosition(ngl::Vec4 p_pos){m_position = p_pos;}
    void setRotation(ngl::Vec4 p_rot){m_rotation = p_rot;}
    void setStoredPosition(ngl::Vec3 p_pos){m_storedStackPosition = p_pos;}
    void setStoredRotation(ngl::Vec3 p_rot){m_storedStackRotation = p_rot;}
    void setStandardUnit(float p_sUnit){m_standardUnit = p_sUnit;m_halfUnit = p_sUnit/2.0f;}
    void setStandardAngle(float p_angle){m_standardAngle = p_angle;}
    const ngl::Vec4 &getPosition() const {return m_position;}
    ngl::Vec4 getRotation(){return m_rotation;}
    ngl::Vec3 getStoredPosition(){return m_storedStackPosition;}
    ngl::Vec3 getStoredRotation(){return m_storedStackRotation;}
    float getStandardUnit(){return m_standardUnit;}
    float getAngle(){return m_standardAngle;}
    bool getDrawing(){return draw;}
    void toggleDrawing(){draw = !draw;}
    void update();
    ngl::Transformation m_transformationMatrix;
private:
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Turtle Current Position
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Vec4 m_position;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Turtle Current Rotation
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Vec4 m_rotation;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Turtles Stored Position before it is pushed off the stack.
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Vec3 m_storedStackPosition;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Turtles Stored Rotation before it is pushed off the stack.
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Vec3 m_storedStackRotation;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief The standard unit lenght of movement
    //----------------------------------------------------------------------------------------------------------------------
    float m_standardUnit;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief The half unit value of standard unit
    //----------------------------------------------------------------------------------------------------------------------
    float m_halfUnit;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief The Standard Angle to rotate by.
    //----------------------------------------------------------------------------------------------------------------------
    float m_standardAngle;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief draw flag to see if the turtle is being drawn.
    //----------------------------------------------------------------------------------------------------------------------
    bool draw = false;

};

#endif // !TURTLE_H_
