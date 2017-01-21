#include "turtle.h"
#include <iostream>
Turtle::Turtle()
{
    //Default constructor
}

Turtle::~Turtle()
{
    //Default deconstructor
}

void Turtle::moveForwardFullStep()
{
    //Move the turtle one unit forward either drawn or undrawn
    drawing = true;
    std::string boolian;
    drawing ? boolian = "True" : boolian = "False";
    printf("Moving forward full step and drawn is: %s \n", boolian.c_str());
}
void Turtle::moveForwardFullStepUndrawn()
{
    //Move the turtle one unit forward either drawn or undrawn
    drawing = false;
    std::string boolian;
    drawing ? boolian = "True" : boolian = "False";

    printf("Moving forward full step and drawn is: %s \n", boolian.c_str());
}
void Turtle::moveForwardHalfStep()
{
    //Move the turtle half a unit forward either drawn or undrawn
    drawing = true;
    std::string boolian;
    drawing ? boolian = "True" : boolian = "False";
    printf("Moving forward full step and drawn is: %s \n", boolian.c_str());
}

void Turtle::moveForwardHalfStepUndrawn()
{
    //Move the turtle half a unit forward either drawn or undrawn
    drawing = false;
    std::string boolian;
    drawing ? boolian = "True" : boolian = "False";
    printf("Moving forward full step and drawn is: %s \n", boolian.c_str());
}

void Turtle::rotateLeft()
{
    //Rotate the turtle by the angle either left or right
    printf("Rotate Left by angle: %f \n",m_standardAngle);
}

void Turtle::rotateRight()
{
    //Rotate the turtle by the angle either left or right
    printf("Rotate Right by angle: %f \n",m_standardAngle);
}

void Turtle::pitchUp()
{
    //Pitch the turtle by the angle //3D only
    printf("Pitch up by angle: %f \n",m_standardAngle);
}

void Turtle::pitchDown()
{
    //Pitch the turtle by the angle //3D only
    printf("Pitch down by angle: %f \n",m_standardAngle);
}

void Turtle::rollCW()
{
    //Roll the turtle by the angle //3D only
    printf("Roll clockwise by angle: %f \n",m_standardAngle);
}
void Turtle::rollCCW()
{
    //Roll the turtle by the angle //3D onl
    printf("Roll counter clockwise by angle: %f \n",m_standardAngle);
}

void Turtle::turnAround()
{
    //rotate the turtle 180
    printf("Turn Around \n");
}

void Turtle::pushOnStack()
{
    //Push off of the current row to branch off the current part.
     printf("Push on \n");
}

void Turtle::popOffStack()
{
    //pop back onto the original state current generation of the L-system.
     printf("Pop off \n");
}
