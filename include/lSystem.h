#ifndef LSYSTEM_H
#define LSYSTEM_H
#include "Turtle.h"
#include <vector>
#include <iostream>
#include "lObject.h"
#include <unordered_map>
#include <map>
#include <functional>
//--------------------------------------------------------------------------------------------------------------------------
/// @file lSystem.h
/// @brief This is the lSystem class
/// @author Lloyd Phillips
/// @version 0.7
/// @date 25/01/17
/// Revision History:
/// Currently in working progress, most interpretations have been implemented but not all
/// @class lSystem
/// @brief lSystem class for storing our rules and strings, while also controlling our turtle.
/// @class lAlphabet
/// @brief The alphabet that we're going to call to call functions. (enums)
/// @class lRules
/// @brief allows for up ot 10 rules currently + character (enums)
//--------------------------------------------------------------------------------------------------------------------------
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

enum class lRules
{
    Rule1,
    Rule2,
    Rule3,
    Rule4,
    Rule5,
    Rule6,
    Rule7,
    Rule8,
    Rule9,
    Rule10,
    Character
};
//----------------------------------------------------------------------------------------------------------------------
/// @brief overload ++ operator to accept lRules for itterating
//----------------------------------------------------------------------------------------------------------------------
inline lRules operator++(lRules &r)
{
    r = (lRules)((int)(r) + 1);
    if(r == lRules::Character)
    {
        r = (lRules)(0);
    }
    return r;
}
//----------------------------------------------------------------------------------------------------------------------
/// @brief overload -- operator to accept lRules for itterating
//----------------------------------------------------------------------------------------------------------------------
inline lRules operator--(lRules &r)
{
    r = (lRules)((int)(r) - 1);
    if(r == lRules::Rule1)
    {
        r = lRules::Character;
    }
    return r;
}

class lSystem
{
public:
//--------------------------------------------------------------------------------------------------------------------------
/// FUNCTIONALITY
//--------------------------------------------------------------------------------------------------------------------------

    //----------------------------------------------------------------------------------------------------------------------
    /// @brief ctor for lSystem class
    //----------------------------------------------------------------------------------------------------------------------
    lSystem();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief dtor for turtle class
    //----------------------------------------------------------------------------------------------------------------------
    ~lSystem();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief function to split the rules into Left hand side and Right hand side vectors.
    //----------------------------------------------------------------------------------------------------------------------
    void splitRules();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief function that will interpret our string and call appropriate functions to move the turtle
    //----------------------------------------------------------------------------------------------------------------------
    void stringInterpertator();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief function to increase generation
    //----------------------------------------------------------------------------------------------------------------------
    void increaseGeneration();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief function to decrease generation
    //----------------------------------------------------------------------------------------------------------------------
    void decreaseGeneration();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief function to print out the lSystem string
    //----------------------------------------------------------------------------------------------------------------------
    void printLSystem();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief function to print out the lSystem's variables
    //----------------------------------------------------------------------------------------------------------------------
    void printVariables();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief function to print out the lSystem's rules
    //----------------------------------------------------------------------------------------------------------------------
    void printRules();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief function to print out all the attributes of the lsystem
    //----------------------------------------------------------------------------------------------------------------------
    void printAll();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief unordered map to interpret our string into LAlphabets
    //----------------------------------------------------------------------------------------------------------------------
    static std::unordered_map<char , LAlphabet> AlphabetsStrings;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief map to interperate our LAlphabets into function calls.
    //----------------------------------------------------------------------------------------------------------------------
    static std::map<LAlphabet , std::function<void(Turtle&)>> AlphabetFunctions;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Our Turtle - Public for accessibility.
    //----------------------------------------------------------------------------------------------------------------------
    Turtle *m_turtle;
//--------------------------------------------------------------------------------------------------------------------------
/// SETTERS
//--------------------------------------------------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Sets the lsystem string
    /// @param p_system - The passed in string that we want to set as our lsystem. (string)
    //----------------------------------------------------------------------------------------------------------------------
    void setLSystem(std::string const& p_system){m_string = p_system;}
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Sets the axion
    /// @param p_axiom - The passed in axiom that we want to set as our axiom. (string)
    //----------------------------------------------------------------------------------------------------------------------
    void setAxiom(std::string const& p_axiom){m_axiom = p_axiom;}
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Sets the generation
    /// @param p_gen - The passed in generation that we want to set as our generation. (int)
    //----------------------------------------------------------------------------------------------------------------------
    void setGeneration(int const& p_gen){m_generation = p_gen;}
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief adds a rule to our list of current rules
    /// @param p_rule - The rule that we want to add to our existing rules. (string)
    //----------------------------------------------------------------------------------------------------------------------
    void addRule(std::string p_rule){m_rules.push_back(p_rule);}
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Sets the turtle unit which will be passed eventually to our turtle
    /// @param u - The unit that we want to set our turtles unit too. (float)
    //----------------------------------------------------------------------------------------------------------------------
    void setTurtleUnit(float u){m_turtleUnit = u;}
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Sets the turtle angle which will be passed eventually to our turtle
    /// @param a - The angle that we want to set our turtles angle too. (float)
    //----------------------------------------------------------------------------------------------------------------------
    void setTurtleAngle(float a){m_turtleAngle = a;}
//--------------------------------------------------------------------------------------------------------------------------
/// GETTERS
//--------------------------------------------------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Gets the lSystem String.
    /// @return Returns the current lSystem (m_string) (string)
    //----------------------------------------------------------------------------------------------------------------------
    std::string getLSystem(){return m_string;}
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Gets the lSystem generation.
    /// @return Returns the current generation (m_generation) (int)
    //----------------------------------------------------------------------------------------------------------------------
    const int &getGeneration() const {return m_generation;}
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Gets the lSystem axiom.
    /// @return Returns the current axiom (m_axiom) (string)
    //----------------------------------------------------------------------------------------------------------------------
    const std::string &getAxiom() const {return m_axiom;}
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Gets the array of rules.
    /// @return Returns the array of rules.
    //----------------------------------------------------------------------------------------------------------------------
    std::vector<std::string> getRules(){return m_rules;}
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief gets the generated object
    /// @return Returns the size of the array storing our rules
    //----------------------------------------------------------------------------------------------------------------------
    lObject getGeneratedObject() {return *m_generatedObject;}
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Gets the turtle unit passed in from our parser
    /// @return Returns the current turtles unit that has been loaded (m_turtleUnit) (float)
    //----------------------------------------------------------------------------------------------------------------------
    float getTurtleUnit(){return m_turtleUnit;}
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Gets the turtle angle passed in from our parser
    /// @return Returns the current turtles angle that has been loaded (m_turtleAngle) (float)
    //----------------------------------------------------------------------------------------------------------------------
    float getTurtleAngle(){return m_turtleAngle;}
private:
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Current generation that our lSystem is on.
    //----------------------------------------------------------------------------------------------------------------------
    int m_generation;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Container for our lSystem
    //----------------------------------------------------------------------------------------------------------------------
    std::string m_string;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief The Axiom (starting point) for our lSystem
    //----------------------------------------------------------------------------------------------------------------------
    std::string m_axiom;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief The object that will eventually replace m_verts - Currently storing raw verts + Indicies.
    //----------------------------------------------------------------------------------------------------------------------
    lObject *m_generatedObject;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Container for our rules
    //----------------------------------------------------------------------------------------------------------------------
    std::vector<std::string> m_rules;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Container for our rules once split (Left hand side)
    //----------------------------------------------------------------------------------------------------------------------
    std::vector<std::string> LHS_rules;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Container for our rules once split (Right hand side)
    //----------------------------------------------------------------------------------------------------------------------
    std::vector<std::string> RHS_rules;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Our turtles angle - loaded in from parser
    //----------------------------------------------------------------------------------------------------------------------
    float m_turtleAngle;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Our turtles unit - loaded in from parser
    //----------------------------------------------------------------------------------------------------------------------
    float m_turtleUnit;




};



#endif
