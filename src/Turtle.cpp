#include "Turtle.h"
#include <algorithm>
Turtle::Turtle()
{
    //Default constructor
    //Zero out everything.
    m_position.zero();
    m_transformation.setPosition(0,0,0);

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
    m_transformation.addPosition(m_transformation.getMatrix().getUpVector() * m_standardUnit);

    m_transformation.getMatrix().getUpVector();
    printf("FORWARD VECTOR = X: %f, Y: %f, Z: %f\n",m_transformation.getMatrix().getForwardVector().m_x,m_transformation.getMatrix().getForwardVector().m_y,m_transformation.getMatrix().getForwardVector().m_z);

}

void Turtle::moveForwardFullStepUndrawn()
{
#ifdef _DEBUG
    printf("Moved forward full step and draw flag is set to false (off) \n");
#endif

    draw = false;
    m_transformation.addPosition(m_transformation.getMatrix().getForwardVector() * m_standardUnit);
}

void Turtle::moveForwardHalfStep()
{
#ifdef _DEBUG
    printf("Moved forward half step and draw flag is set to true (on) \n");
#endif

    draw = true;
    m_transformation.addPosition(m_transformation.getMatrix().getForwardVector() * m_halfUnit);
}

void Turtle::moveForwardHalfStepUndrawn()
{
#ifdef _DEBUG
    printf("Moved forward half step and draw flag is set to false (off) \n");
#endif

    draw = false;
    m_transformation.addPosition(m_transformation.getMatrix().getForwardVector() * m_halfUnit);
}

void Turtle::yawLeft()
{
#ifdef _DEBUG
    printf("Yawed Left by angle: %f \n",m_standardAngle);
#endif

    //m_transformation.addRotation(-m_standardAngle,0,0);
    //m_transformation.addRotation(0,-m_standardAngle,0);
    //m_transformation.getMatrix().rotateZ(-m_standardAngle);
    m_transformation.addRotation(0,0,-m_standardAngle);
}

void Turtle::yawRight()
{
#ifdef _DEBUG
    printf("Yawed Right by angle: %f \n",m_standardAngle);
#endif

   // m_transformation.addRotation(m_standardAngle,0,0);
  //m_transformation.addRotation(0,m_standardAngle,0);
  m_transformation.addRotation(0,0,m_standardAngle);
}

void Turtle::pitchUp()
{
#ifdef _DEBUG
    printf("Pitched up by angle: %f \n",m_standardAngle);
#endif

    m_transformation.addRotation(0,m_standardAngle,0);
}

void Turtle::pitchDown()
{
#ifdef _DEBUG
    printf("Pitched down by angle: %f \n",m_standardAngle);
#endif

    m_transformation.addRotation(0,-m_standardAngle,0);
}

void Turtle::rollCW()
{
#ifdef _DEBUG
    printf("Rolled clockwise by angle: %f \n",m_standardAngle);
#endif

    m_transformation.addRotation(m_standardAngle,0,0);
}
void Turtle::rollCCW()
{
#ifdef _DEBUG
    printf("Rolled counter clockwise by angle: %f \n",m_standardAngle);
#endif

    m_transformation.addRotation(-m_standardAngle,0,0);
}

void Turtle::turnAround()
{
#ifdef _DEBUG
    printf("Turned Around \n");
#endif

    m_transformation.addRotation(0,180,0);
}

void Turtle::startBranch()
{
#ifdef _DEBUG
    printf("Started new branch \n");
    printf("Storing currentPosition = X: %f, Y: %f, Z: %f\n",m_position.m_x,m_position.m_y,m_position.m_z);
#endif
    storedTrans = m_transformation;

    //m_storedStackPosition = m_position;
    //m_storedStackRotation = m_rotation;
    printf("After storing the stored position is = X: %f, Y: %f, Z: %f\n",m_storedStackPosition.m_x,m_storedStackPosition.m_y,m_storedStackPosition.m_z);
}

void Turtle::endBranch()
{
#ifdef _DEBUG
    printf("ended branch \n");
    printf("Returning position too = X: %f, Y: %f, Z: %f\n",m_storedStackPosition.m_x,m_storedStackPosition.m_y,m_storedStackPosition.m_z);
    printf("the current position is = X: %f, Y: %f, Z: %f\n",m_position.m_x,m_position.m_y,m_position.m_z);


#endif
    m_transformation = storedTrans;
    m_position = ngl::Vec4(m_transformation.getMatrix().m_30,m_transformation.getMatrix().m_31, m_transformation.getMatrix().m_32, 1);
    //restorePosition();
    //restoreRotation();
    printf("After restore the position is now = X: %f, Y: %f, Z: %f\n",m_position.m_x,m_position.m_y,m_position.m_z);

}

void Turtle::update()
{


    m_position = ngl::Vec4(m_transformation.getMatrix().m_30,m_transformation.getMatrix().m_31, m_transformation.getMatrix().m_32, 1);
    printf("After restore the position is now = X: %f, Y: %f, Z: %f\n",m_position.m_x,m_position.m_y,m_position.m_z);


}
