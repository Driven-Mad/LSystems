#include "Turtle.h"

Turtle::Turtle()
{
    //Default constructor
    //Zero out everything.
    m_position.zero();
    m_transformationMatrix.setPosition(0,0,0);
}

Turtle::~Turtle()
{
    //Default deconstructor
}

void Turtle::moveForwardFullStep()
{
#ifdef _DEBUG
    printf("Moved forward full step and draw flag is set to true (on) \n");
#endif

    draw = true;
    m_transformationMatrix.addPosition(m_transformationMatrix.getMatrix().getForwardVector() * m_standardUnit);
}

void Turtle::moveForwardFullStepUndrawn()
{
#ifdef _DEBUG
    printf("Moved forward full step and draw flag is set to false (off) \n");
#endif

    draw = false;
    m_transformationMatrix.addPosition(m_transformationMatrix.getMatrix().getForwardVector() * m_standardUnit);
}

void Turtle::moveForwardHalfStep()
{
#ifdef _DEBUG
    printf("Moved forward half step and draw flag is set to true (on) \n");
#endif

    draw = true;
    m_transformationMatrix.addPosition(m_transformationMatrix.getMatrix().getForwardVector() * m_halfUnit);
}

void Turtle::moveForwardHalfStepUndrawn()
{
#ifdef _DEBUG
    printf("Moved forward half step and draw flag is set to false (off) \n");
#endif

    draw = false;
    m_transformationMatrix.addPosition(m_transformationMatrix.getMatrix().getForwardVector() * m_halfUnit);
}

void Turtle::yawLeft()
{
#ifdef _DEBUG
    printf("Yawed Left by angle: %f \n",m_standardAngle);
#endif

    m_transformationMatrix.addRotation(0,-m_standardAngle,0);
}

void Turtle::yawRight()
{
#ifdef _DEBUG
    printf("Yawed Right by angle: %f \n",m_standardAngle);
#endif

    m_transformationMatrix.addRotation(0,m_standardAngle,0);
}

void Turtle::pitchUp()
{
#ifdef _DEBUG
    printf("Pitched up by angle: %f \n",m_standardAngle);
#endif

    m_transformationMatrix.addRotation(m_standardAngle,0,0);
}

void Turtle::pitchDown()
{
#ifdef _DEBUG
    printf("Pitched down by angle: %f \n",m_standardAngle);
#endif

    m_transformationMatrix.addRotation(-m_standardAngle,0,0);
}

void Turtle::rollCW()
{
#ifdef _DEBUG
    printf("Rolled clockwise by angle: %f \n",m_standardAngle);
#endif

    m_transformationMatrix.addRotation(0,0,m_standardAngle);
}
void Turtle::rollCCW()
{
#ifdef _DEBUG
    printf("Rolled counter clockwise by angle: %f \n",m_standardAngle);
#endif

    m_transformationMatrix.addRotation(0,0,m_standardAngle);
}

void Turtle::turnAround()
{
#ifdef _DEBUG
    printf("Turned Around \n");
#endif

    m_transformationMatrix.addRotation(0,180,0);
}

void Turtle::pushOnStack()
{
#ifdef _DEBUG
    printf("Pushed on to new stack \n");
#endif

     printf("Push on \n");
}

void Turtle::popOffStack()
{
#ifdef _DEBUG
    printf("Poped off the old stack \n");
#endif

     printf("Pop off \n");
}

void Turtle::update()
{

    m_position = m_transformationMatrix.getPosition();

#ifdef _DEBUG
    printf("Turtle Position = X: %f, Y: %f, Z: %f\n",m_position.m_x,m_position.m_y,m_position.m_z);
#endif

}
