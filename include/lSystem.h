#ifndef LSYSTEM_H
#define LSYSTEM_H
#include "turtle.h"
#include <vector>
#include "lObject.h"

class lSystem
{
public:
    lSystem();
    ~lSystem();

    void stringInterpertator();
private:
    Turtle m_turtle;
    //lObject m_Object;
    int m_generation;
    float m_globalAngle;
    float m_globalLength;
    std::string m_string;
    std::string m_axiom;
    std::vector<std::string>m_rules;

};

#endif
