#include"lSystem.h"

std::unordered_map<char , LAlphabet> lSystem::AlphabetsStrings =
{
    {'F', LAlphabet::FullStep},
    {'f', LAlphabet::FullStepUndrawn},
    {'H', LAlphabet::HalfStep},
    {'h', LAlphabet::HalfStepUndrawn},
    {'+', LAlphabet::RotateRight},
    {'-', LAlphabet::RotateLeft},
    {'&', LAlphabet::PitchUp},
    {'^', LAlphabet::PitchDown},
    {'/', LAlphabet::RollCW},
    {'\\',LAlphabet::RollCCW},
    {'|', LAlphabet::TurnAround},
    {'[', LAlphabet::StartBranch},
    {']', LAlphabet::EndBranch},
    {'~', LAlphabet::Random}
};

lSystem::lSystem()
{

}

lSystem::~lSystem()
{

}

void lSystem::stringInterpertator()
{
   // interperate axiom of user rules etc.
}

void lSystem::printLSystem()
{
    printf("Lsystem is as follows: \n%s\n", m_string.c_str());
}

void lSystem::printVariables()
{
    printf("Angle is as follows: \n%f\n",m_globalAngle );
    printf("Length is as follows: \n%f\n",m_globalLength );
    printf("Axiom is as follows: \n%s\n", m_axiom.c_str());

}

void lSystem::printRules()
{
    for(unsigned int i; i<m_rules.size(); i++)
    {
        printf("Rule %i is as follows: \n%s\n",i, m_rules[i].c_str());
    }
}

void lSystem::printAll()
{
    printLSystem();
    printVariables();
    printRules();

}
