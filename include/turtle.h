#ifndef TURTLE_H_
#define TURTLE_H_ // TURTLE_H_
#include"vec3.h"

class Turtle
{
public:
    Turtle();
    ~Turtle();
    void moveForwardFullStep();
    void moveForwardHalfStep();
    void rotate(float p_angle);
    void pitch(float p_angle);
    void roll(float p_angle);
    void turnAround();
    void pushOnStack();
    void popOffStack();

    //getters and setters
    void setPosition(Vec3 p_pos){m_position = p_pos;};
    void setRotation(Vec3 p_rot){m_rotation = p_rot;};
    void setStoredPosition(Vec3 p_pos){m_storedStackPosition = p_pos;};
    void setStoredRotation(Vec3 p_rot){m_storedStackRotation = p_rot;};
    void setStandardUnit(float p_sUnit){m_standardUnit = p_sUnit;};

    Vec3 getPosition(){return m_position;};
    Vec3 getRotation(){return m_rotation;};
    Vec3 getStoredPosition(){return m_storedStackPosition;};
    Vec3 getStoredRotation(){return m_storedStackRotation;};
    float getStandardUnit(){return m_standardUnit;};

    void toggleDrawing(){drawing = !drawing;};

private:
    Vec3 m_position;
    Vec3 m_rotation;
    Vec3 m_storedStackPosition;
    Vec3 m_storedStackRotation;
    float m_standardUnit;
    bool drawing = true;
};

#endif // !TURTLE_H_
