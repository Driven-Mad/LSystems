#ifndef LSYSTEM_H
#define LSYSTEM_H
#include "turtle.h"
#include "lObject.h"

class lSystem
{
public:
    lSystem();
    ~lSystem();
    stringInterpertator();
private:
    Turtle m_turtle;
    lObject m_Object;
    int m_generation;
    float m_globalAngle;
    float m_globalLength;
    std::string m_axiom: string;
    std::vector<std::string>m_rules;

};

#endif
