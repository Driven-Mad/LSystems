#ifndef LSYSTEM_H
#define LSYSTEM_H
#include "turtle.h"
#include <vector>
#include <iostream>
#include "lObject.h"
#include <unordered_map>
#include <map>
#include <functional>

enum class LAlphabet
 {
     FullStep,
     FullStepUndrawn,
     HalfStep,
     HalfStepUndrawn,
     RotateRight,
     RotateLeft,
     PitchUp,
     PitchDown,
     RollCW,
     RollCCW,
     TurnAround,
     StartBranch,
     EndBranch
 };



class lSystem
{
public:
    lSystem();
    ~lSystem();

    static std::unordered_map<char , LAlphabet> AlphabetsStrings;
    static std::map<LAlphabet , std::function<void(Turtle&)>> AlphabetFunctions;



    void stringInterpertator();
    void setLSystem(std::string p_system){m_string = p_system;};
    void setLSystem(char* p_system){m_string = p_system;};
    void setGlobalAngle(float p_angle){m_globalAngle = p_angle;};
    void setGlobalLength(float p_length){m_globalLength = p_length;};
    void setAxiom(std::string p_axiom){m_axiom = p_axiom;};
    void setGeneration(int p_gen){m_generation = p_gen;};

    std::string getLSystem(){return m_string;};
    int getGeneration(){return m_generation;};
    float getGlobalAngle(){return m_globalAngle;};
    float getGlobalLength(){return m_globalLength;};
    std::string getAxiom(){return m_axiom;};


    void addRule(std::string p_rule){m_rules.push_back(p_rule);};

    void printLSystem();
    void printVariables();
    void printRules();
    void printAll();
private:
    Turtle m_turtle;
    int m_generation;
    float m_globalAngle;
    float m_globalLength;
    std::string m_string;
    std::string m_axiom;
    std::vector<std::string>m_rules;


};



#endif
