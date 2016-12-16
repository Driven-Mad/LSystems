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
    std::string boolian;
    if(drawing)
    {
        boolian = "True";
    }else{
        boolian = "False";
    }
    printf("Moving forward full step and drawn is: %s \n", boolian.c_str());
}

void Turtle::moveForwardHalfStep()
{
    //Move the turtle half a unit forward either drawn or undrawn
    std::string boolian;
    if(drawing)
    {
        boolian = "True";
    }else{
        boolian = "False";
    }
    printf("Moving forward full step and drawn is: %s \n", boolian.c_str());
}

void Turtle::rotate()
{
    //Rotate the turtle by the angle either left or right
    printf("Rotate by angle: %i \n",m_standardAngle);
}

void Turtle::pitch()
{
    //Pitch the turtle by the angle //3D only
    printf("Pitch by angle: %i \n",m_standardAngle);
}

void Turtle::roll()
{
    //Roll the turtle by the angle //3D only
    printf("Roll by angle: %i \n",m_standardAngle);
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
