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
    {']', LAlphabet::EndBranch}
};
std::map<LAlphabet , std::function<void(Turtle&)>> lSystem::AlphabetFunctions =
{
    {LAlphabet::FullStep, &Turtle::moveForwardFullStep},
    {LAlphabet::FullStepUndrawn, &Turtle::moveForwardFullStep},
    {LAlphabet::HalfStep, &Turtle::moveForwardHalfStep},
    {LAlphabet::HalfStepUndrawn, &Turtle::moveForwardHalfStep},
    {LAlphabet::RotateRight, &Turtle::rotate},
    {LAlphabet::RotateLeft, &Turtle::rotate},
    {LAlphabet::PitchUp, &Turtle::pitch},
    {LAlphabet::PitchDown, &Turtle::pitch},
    {LAlphabet::RollCW, &Turtle::roll},
    {LAlphabet::RollCCW, &Turtle::roll},
    {LAlphabet::TurnAround, &Turtle::turnAround},
    {LAlphabet::StartBranch, &Turtle::pushOnStack},
    {LAlphabet::EndBranch, &Turtle::popOffStack}
};


lSystem::lSystem()
{
    //std::function<void(Turtle&)> gey = &Turtle::moveForwardFullStep;

    // plz get rid of this
    unsigned int max = (unsigned int)(LAlphabet::EndBranch) + 1;

    //AlphabetFunctions[LAlphabet::FullStep](m_turtle);

   // for(unsigned int i = 0; i < max; i++)
   // {
   //   AlphabetFunctions[(LAlphabet)i](m_turtle);
   // }

    // how to call it
    //gey(m_turtle);

    //AlphabetFunctions[LAlphabet::FullStep] = gey;
     //AlphabetFunctions.insert(LAlphabet::FullStep, std::function<void(Turtle&)>(&Turtle::moveForwardFullStep));

     //AlphabetFunctions.insert(std::pair<LAlphabet, std::function<void(Turtle&)>(LAlphabet::FullStep,&Turtle::moveForwardFullStep ));
}

lSystem::~lSystem()
{

}

void lSystem::stringInterpertator()
{
   // interperate axiom of user rules etc.

    for(unsigned int i = 0; i < m_string.size(); i++)
    {
      AlphabetFunctions[AlphabetsStrings[m_string[i]]](m_turtle);
    }

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
