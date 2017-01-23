#include "Turtle.h"

Turtle::Turtle()
{
    //Default constructor
    m_position.zero();
    m_transformationMatrix.setPosition(0,0,0);
    m_transformationMatrix.addRotation(0,0,90);

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
//    m_transformationMatrix.reset();
    m_transformationMatrix.addPosition(m_transformationMatrix.getMatrix().getForwardVector() * m_standardUnit);
}
void Turtle::moveForwardFullStepUndrawn()
{
    //Move the turtle one unit forward either drawn or undrawn
    drawing = false;
    std::string boolian;
    drawing ? boolian = "True" : boolian = "False";

    printf("Moving forward full step and drawn is: %s \n", boolian.c_str());
    m_transformationMatrix.addPosition(m_transformationMatrix.getMatrix().getForwardVector() * m_standardUnit);
}
void Turtle::moveForwardHalfStep()
{
    //Move the turtle half a unit forward either drawn or undrawn
    drawing = true;
    std::string boolian;
    drawing ? boolian = "True" : boolian = "False";
    printf("Moving forward full step and drawn is: %s \n", boolian.c_str());
    m_transformationMatrix.addPosition(m_transformationMatrix.getMatrix().getForwardVector() * (m_standardUnit/2));
}

void Turtle::moveForwardHalfStepUndrawn()
{
    //Move the turtle half a unit forward either drawn or undrawn
    drawing = false;
    std::string boolian;
    drawing ? boolian = "True" : boolian = "False";
    printf("Moving forward full step and drawn is: %s \n", boolian.c_str());
    m_transformationMatrix.addPosition(m_transformationMatrix.getMatrix().getForwardVector() * (m_standardUnit/2));
}

void Turtle::yawLeft()
{

    //m_transformationMatrix.getMatrix().rotateZ(-m_standardAngle);
    //Rotate the turtle by the angle either left or right
    printf("Rotate Left by angle: %f \n",m_standardAngle);
    m_transformationMatrix.addRotation(0,-m_standardAngle,0);
}

void Turtle::yawRight()
{
    //m_transformationMatrix.getMatrix().rotateZ(m_standardAngle);
    //Rotate the turtle by the angle either left or right
    printf("Rotate Right by angle: %f \n",m_standardAngle);

    m_transformationMatrix.addRotation(0,m_standardAngle,0);
}

void Turtle::pitchUp()
{
    //m_transformationMatrix.getMatrix().rotateY(m_standardAngle);
    //Pitch the turtle by the angle //3D only
    printf("Pitch up by angle: %f \n",m_standardAngle);

    m_transformationMatrix.addRotation(0,m_standardAngle,0);
}

void Turtle::pitchDown()
{
    //m_transformationMatrix.getMatrix().rotateY(-m_standardAngle);
    //Pitch the turtle by the angle //3D only
    printf("Pitch down by angle: %f \n",m_standardAngle);
    m_transformationMatrix.addRotation(0,-m_standardAngle,0);
}

void Turtle::rollCW()
{
    //m_transformationMatrix.getMatrix().rotateX(m_standardAngle);
    //Roll the turtle by the angle //3D only
    printf("Roll clockwise by angle: %f \n",m_standardAngle);
    m_transformationMatrix.addRotation(m_standardAngle,0,0);
}
void Turtle::rollCCW()
{
    m_transformationMatrix.getMatrix().rotateX(-m_standardAngle);
    //Roll the turtle by the angle //3D onl
    printf("Roll counter clockwise by angle: %f \n",m_standardAngle);
    m_transformationMatrix.addRotation(-m_standardAngle,0,0);
}

void Turtle::turnAround()
{
    m_transformationMatrix.addRotation(180,0,0);
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

#include <ngl/NGLStream.h>
#include <iomanip>

void Turtle::update()
{
    std::cout<<std::fixed<<std::endl;
    std::cout<< m_position.m_x<<" , "<< m_position.m_y<<" , "<< m_position.m_z <<std::endl;
    m_position = ngl::Vec3(m_transformationMatrix.getPosition().m_x,m_transformationMatrix.getPosition().m_z,m_transformationMatrix.getPosition().m_y);
    std::cout<< m_position.m_x<<" , "<< m_position.m_y<<" , "<< m_position.m_z <<std::endl;


   // m_position.x = m_transformationMatrix.m_03;
   // m_position.y = m_transformationMatrix.m_13;
   // m_position.z = m_transformationMatrix.m_23;
}
