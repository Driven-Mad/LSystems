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


void Turtle::init()
{
    m_rotation = ngl::Vec4(0.0f,0.0f,0.0f,0.0f);
    m_position = ngl::Vec4(0.0f,0.0f,0.0f,0.0f);
    //float PI = 3.14159265359f;
    //float rad = m_standardAngle * (PI/180.0f);
    //
    //
    //float c = cosf(rad);
    //float s = sinf(rad);
    ////ROTATE Z
    //// cos   sin   0
    ////-sin   cos   0
    //// 0     0     1
    //
    ////ROTATE Y
    //// cos   0    -sin
    //// 0     1     0
    //// sin   0     cos
    //
    ////ROTATE X
    //// 1     0     0
    //// 0     cos  -sin
    //// 0     sin   cos
    //
    ////NGL::MAT3
    ////00     01    02
    ////10     11    12
    ////20     21    22
    //rotationX.identity();
    //rotationX.m_11 =  c;
    //rotationX.m_21 =  s;
    //rotationX.m_12 = -s;
    //rotationX.m_22 =  c;
    //
    //rotationY.identity();
    //rotationX.m_00 =  c;
    //rotationX.m_02 = -s;
    //rotationX.m_20 =  s;
    //rotationX.m_22 =  c;
    //
    //rotationZ.identity();
    //rotationX.m_00 =  c;
    //rotationX.m_01 =  s;
    //rotationX.m_10 = -s;
    //rotationX.m_11 =  c;
}
void Turtle::init(float angle, float length)
{

    m_rotation = ngl::Vec4(0.0f,0.0f,0.0f,0.0f);
    m_position = ngl::Vec4(0.0f,0.0f,0.0f,0.0f);
    m_standardAngle = angle;
    m_standardUnit = length;
    m_halfUnit = length/2.0;
//    float PI = 3.14159265359f;
//    float rad = m_standardAngle * (PI/180.0f);


//    float c = cosf(rad);
//    float s = sinf(rad);
    //ROTATE Z
    // cos   sin   0
    //-sin   cos   0
    // 0     0     1

    //ROTATE Y
    // cos   0    -sin
    // 0     1     0
    // sin   0     cos

    //ROTATE X
    // 1     0     0
    // 0     cos  -sin
    // 0     sin   cos

    //NGL::MAT3
    //00     01    02
    //10     11    12
    //20     21    22
    //rotationX.identity();
    //rotationX.m_11 =  c;
    //rotationX.m_21 =  s;
    //rotationX.m_12 = -s;
    //rotationX.m_22 =  c;
    //
    //rotationY.identity();
    //rotationX.m_00 =  c;
    //rotationX.m_02 = -s;
    //rotationX.m_20 =  s;
    //rotationX.m_22 =  c;
    //
    //rotationZ.identity();
    //rotationX.m_00 =  c;
    //rotationX.m_01 =  s;
    //rotationX.m_10 = -s;
    //rotationX.m_11 =  c;



}


void Turtle::moveForwardFullStep()
{
#ifdef _DEBUG
    printf("Moved forward full step and draw flag is set to true (on) \n");
#endif

    draw = true;

    m_position += (m_transformation.getMatrix().getUpVector() * m_standardUnit);
    //m_position += (m_transformation.getMatrix().getRightVector() * m_standardUnit);
    printf("FORWARD VECTOR = X: %f, Y: %f, Z: %f\n",m_transformation.getMatrix().getForwardVector().m_x,m_transformation.getMatrix().getForwardVector().m_y,m_transformation.getMatrix().getForwardVector().m_z);

}

void Turtle::moveForwardFullStepUndrawn()
{
#ifdef _DEBUG
    printf("Moved forward full step and draw flag is set to false (off) \n");
#endif
    draw = false;
    m_position += (m_transformation.getMatrix().getUpVector()  * m_standardUnit);

}

void Turtle::moveForwardHalfStep()
{
#ifdef _DEBUG
    printf("Moved forward half step and draw flag is set to true (on) \n");
#endif

    draw = true;
    m_position += (m_transformation.getMatrix().getUpVector()  * m_halfUnit);
}

void Turtle::moveForwardHalfStepUndrawn()
{
#ifdef _DEBUG
    printf("Moved forward half step and draw flag is set to false (off) \n");
#endif

    draw = false;
    m_position += (m_transformation.getMatrix().getUpVector()  * m_halfUnit);
}

void Turtle::yawLeft()
{
#ifdef _DEBUG
    printf("Yawed Left by angle: %f \n",m_standardAngle);
#endif


    m_rotation.m_z -= m_standardAngle;
}

void Turtle::yawRight()
{
#ifdef _DEBUG
    printf("Yawed Right by angle: %f \n",m_standardAngle);
#endif
    m_rotation.m_z += m_standardAngle;

}

void Turtle::pitchUp()
{
#ifdef _DEBUG
    printf("Pitched up by angle: %f \n",m_standardAngle);
#endif

    m_rotation.m_y -= m_standardAngle;

}

void Turtle::pitchDown()
{
#ifdef _DEBUG
    printf("Pitched down by angle: %f \n",m_standardAngle);
#endif

    m_rotation.m_y += m_standardAngle;

}

void Turtle::rollCW()
{
#ifdef _DEBUG
    printf("Rolled clockwise by angle: %f \n",m_standardAngle);
#endif

    m_rotation.m_x -= m_standardAngle;

}
void Turtle::rollCCW()
{
#ifdef _DEBUG
    printf("Rolled counter clockwise by angle: %f \n",m_standardAngle);
#endif

    m_rotation.m_x += m_standardAngle;
    m_transformation.setRotation(m_rotation);
    m_transformation.setPosition(m_storedStackPosition);

}

void Turtle::turnAround()
{
#ifdef _DEBUG
    printf("Turned Around \n");
#endif

    m_rotation.m_x -= 180;
}

void Turtle::startBranch()
{
#ifdef _DEBUG
    printf("Started new branch \n");
    printf("Storing currentPosition = X: %f, Y: %f, Z: %f\n",m_position.m_x,m_position.m_y,m_position.m_z);
#endif

   storePosition();
   storeRotation();
    printf("After storing the stored position is = X: %f, Y: %f, Z: %f\n",m_storedStackPosition.m_x,m_storedStackPosition.m_y,m_storedStackPosition.m_z);
}

void Turtle::endBranch()
{
#ifdef _DEBUG
    printf("ended branch \n");
    printf("Returning position too = X: %f, Y: %f, Z: %f\n",m_storedStackPosition.m_x,m_storedStackPosition.m_y,m_storedStackPosition.m_z);
    printf("the current position is = X: %f, Y: %f, Z: %f\n",m_position.m_x,m_position.m_y,m_position.m_z);


#endif
     restoreRotation();
     restorePosition();

}

void Turtle::update()
{
    printf("MY ROTATION = X: %f, Y: %f, Z: %f\n",m_rotation.m_x,m_rotation.m_y,m_rotation.m_z);
    printf("MY POSITION = X: %f, Y: %f, Z: %f\n",m_position.m_x,m_position.m_y,m_position.m_z);
   m_transformation.setPosition(m_position);
   m_transformation.setRotation(m_rotation);




}
