#include "turtle.h"

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
}

void Turtle::moveForwardHalfStep()
{
    //Move the turtle half a unit forward either drawn or undrawn
}

void Turtle::rotate(float p_angle)
{
    //Rotate the turtle by the angle either left or right
}

void Turtle::pitch(float p_angle)
{
    //Pitch the turtle by the angle //3D only
}

void Turtle::roll(float p_angle)
{
    //Roll the turtle by the angle //3D only
}

void Turtle::turnAround()
{
    //rotate the turtle 180
}

void Turtle::pushOnStack()
{
    //Push off of the current row to branch off the current part.
}

void Turtle::popOffStack()
{
    //pop back onto the original state current generation of the L-system.
}
