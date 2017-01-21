#include"lSystem.h"
#include <sstream>
///Declare our map out of class to keep it static.
///Unordered map of chars and our own alphabet.
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
///Declare our map out of class to keep it static
/// map of our alhpabet and std::functions to allow the interperation of the L-system string
std::map<LAlphabet , std::function<void(Turtle&)>> lSystem::AlphabetFunctions =
{
    {LAlphabet::FullStep,           &Turtle::moveForwardFullStep},
    {LAlphabet::FullStepUndrawn,    &Turtle::moveForwardFullStepUndrawn},
    {LAlphabet::HalfStep,           &Turtle::moveForwardHalfStep},
    {LAlphabet::HalfStepUndrawn,    &Turtle::moveForwardHalfStepUndrawn},
    {LAlphabet::RotateRight,        &Turtle::rotateRight},
    {LAlphabet::RotateLeft,         &Turtle::rotateLeft},
    {LAlphabet::PitchUp,            &Turtle::pitchUp},
    {LAlphabet::PitchDown,          &Turtle::pitchDown},
    {LAlphabet::RollCW,             &Turtle::rollCW},
    {LAlphabet::RollCCW,            &Turtle::rollCCW},
    {LAlphabet::TurnAround,         &Turtle::turnAround},
    {LAlphabet::StartBranch,        &Turtle::pushOnStack},
    {LAlphabet::EndBranch,          &Turtle::popOffStack}
};


lSystem::lSystem()
{
    m_turtle = new Turtle();
    m_generation = 0;
}

lSystem::~lSystem()
{

}

void lSystem::stringInterpertator()
{
   // interperate axiom of user rules etc.

    for(unsigned int i = 0; i < m_string.size(); i++)
    {
      AlphabetFunctions[AlphabetsStrings[m_string[i]]](*m_turtle);
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
    for(size_t i = 0; i<m_rules.size(); i++)
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

void lSystem::splitRules()
{
    LHS_rules.clear();
    RHS_rules.clear();
    std::vector<std::string> myRulesSplit;
    for(size_t i = 0; i<m_rules.size(); i++)
    {
        std::stringstream ss(m_rules[i]);
        std::string temp;
        while(std::getline(ss,temp,'='))
        {
            myRulesSplit.push_back(temp);
        }
    }

    for(size_t x=0; x < myRulesSplit.size(); x+=2)
    {
        LHS_rules.push_back(myRulesSplit[x]);
        //printf("LHS: %s \n",myRulesSplit[x].c_str()); //Debug Only
        RHS_rules.push_back(myRulesSplit[x+1]);
        //printf("RHS: %s \n",myRulesSplit[x+1].c_str()); //Debug Only
    }

}


void lSystem::increaseGeneration()
{
    if(m_generation == 0)
    {
        m_string = m_axiom;
    }

    std::vector<stringRuleSolver> m_stringSolved;
    for(size_t x= 0; x<m_string.length(); x++)
    {
        stringRuleSolver SRS;
        SRS.c = m_string[x];
        SRS.r = LRules::Character;
        m_stringSolved.push_back(SRS);
    }

    LRules rule = LRules::Rule1;
    splitRules();
    for(size_t i = 0; i<LHS_rules.size();i++)
    {
        //Starting point is string[0]
        size_t startSearchingFrom = 0;
        //make startingpoint = searchString[first character of found subString]
        while((startSearchingFrom = m_string.find(LHS_rules[i],startSearchingFrom)) != std::string::npos )
        {
            startSearchingFrom ++;
            m_stringSolved[startSearchingFrom-1].r = rule;
        }
        ++rule;
    }

    std::string newString;
    for(size_t f = 0; f<m_stringSolved.size(); f++)
    {
       // printf("Enum is: %i \n", int(m_stringSolved[f].r)); //Debug Only
        switch(m_stringSolved[f].r)
        {
        case LRules::Rule1:
            m_stringSolved[f].c = RHS_rules[int(LRules::Rule1)];
            break;
        case LRules::Rule2:
            m_stringSolved[f].c = RHS_rules[int(LRules::Rule2)];
            break;
        case LRules::Rule3:
            m_stringSolved[f].c = RHS_rules[int(LRules::Rule3)];
            break;
        case LRules::Rule4:
            m_stringSolved[f].c = RHS_rules[int(LRules::Rule4)];
            break;
        case LRules::Rule5:
            m_stringSolved[f].c = RHS_rules[int(LRules::Rule5)];
            break;
        case LRules::Rule6:
            m_stringSolved[f].c = RHS_rules[int(LRules::Rule6)];
            break;
        case LRules::Rule7:
            m_stringSolved[f].c = RHS_rules[int(LRules::Rule7)];
            break;
        case LRules::Rule8:
            m_stringSolved[f].c = RHS_rules[int(LRules::Rule7)];
            break;
        case LRules::Rule9:
            m_stringSolved[f].c = RHS_rules[int(LRules::Rule7)];
            break;
        case LRules::Rule10:
            m_stringSolved[f].c = RHS_rules[int(LRules::Rule7)];
            break;
        default:
            break;
        }
        newString+= m_stringSolved[f].c;
    }
    //printf("Final String is: %s \n", newString.c_str());//Debug Only
    m_string = newString;
    m_generation ++;

}
