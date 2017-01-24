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
    {LAlphabet::RotateRight,        &Turtle::yawRight},
    {LAlphabet::RotateLeft,         &Turtle::yawLeft},
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
    m_generatedObject = new lObject();
    m_generation = 0;
}

lSystem::~lSystem()
{

}

void lSystem::stringInterpertator()
{
   // interperate axiom of user rules etc.
    m_verts.clear();
    m_generatedObject->clearAll();
    m_turtle->m_transformationMatrix.reset();
    int index = 0;


    for(unsigned int i = 0; i < m_string.size(); i++)
    {
        if(m_string[i] == 'F' || m_string[i] == 'H' )
        {
            //Add the current position
            m_generatedObject->addVert(m_turtle->getPosition());
            // add that index
            m_generatedObject->addIndicies(index);
            //Increase the index
            index++;

        }
        //Call appropriate function based on string
        AlphabetFunctions[AlphabetsStrings[m_string[i]]](*m_turtle);
        //update the turtle
        m_turtle->update();

        //IF the string variable we are reading in is a FULL DRAWN step
        if(m_string[i] == 'F' || m_string[i] == 'H')
        {
            //Add the current position
            m_generatedObject->addVert(m_turtle->getPosition());
            // add that index
            m_generatedObject->addIndicies(index);
            //Increase the index
            index++;

        }
    }

    for(int x=0; x< m_generatedObject->iSize(); x++)
    {
        //printf("Indicies are as follows: %i \n", m_generatedObject->getIndicie(x));
        int g = m_generatedObject->getIndicie(x);
        m_verts.push_back(m_generatedObject->getVertex(g));
        //printf("X: %f, Y: %f, Z: %f \n",m_verts[x].m_x,m_verts[x].m_y,m_verts[x].m_z);
    }

   /*
    *    // interperate axiom of user rules etc.
   m_verts.clear();
   m_generatedObject->clearAll();
   m_turtle->m_transformationMatrix.reset();

   for(unsigned int i = 0; i < m_string.size(); i++)
   {
     if(m_turtle->getDrawing())
     {
         m_generatedObject->addIndicies(i);
     }
     AlphabetFunctions[AlphabetsStrings[m_string[i]]](*m_turtle);
     m_turtle->update();
     m_generatedObject->addVert(m_turtle->getPosition());
     if(m_turtle->getDrawing())
     {
         m_generatedObject->addIndicies(i);
     }
   }
   for(int x=0; x< m_generatedObject->iSize(); x++)
   {
       printf("Indicies are as follows: %i \n", m_generatedObject->getIndicie(x));
       m_verts.push_back(m_generatedObject->getVertex(m_generatedObject->getIndicie(x)));
       printf("X: %f, Y: %f, Z: %f \n",m_verts[x].m_x,m_verts[x].m_y,m_verts[x].m_z);
   }

    */


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
        printf("Rule %i is as follows: \n%s\n",int(i), m_rules[i].c_str());

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

void lSystem::decreaseGeneration()
{

   if(m_generation >= 0)
   {
       LRules rule = LRules(LHS_rules.size()-1);

       splitRules();
       for(size_t i = 0; i<RHS_rules.size();i++)
       {
           //Starting point is string[0]
           size_t startSearchingFrom = 0;
           //make startingpoint = searchString[first character of found subString]
           while((startSearchingFrom = m_string.find(RHS_rules[int(rule)],startSearchingFrom)) != std::string::npos )
           {
               //increase by one to the end.
               m_string.replace(startSearchingFrom,(RHS_rules[int(rule)].length()),LHS_rules[int(rule)]);
               //startSearchingFrom += RHS_rules[i].length();
               startSearchingFrom++;
           }
           --rule;
       }
       m_generation --;
       stringInterpertator();
   }


}

void lSystem::increaseGeneration()
{
    std::vector<LRules> m_stringSolved;

    for(size_t x= 0; x<m_string.length(); x++)
    {
        LRules c = LRules::Character;
        m_stringSolved.push_back(c);
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
            //increase by one to the end.
            startSearchingFrom ++;
            m_stringSolved[startSearchingFrom-1] = rule;
        }
        ++rule;
    }

    std::string newString;
    for(size_t f = 0; f<m_stringSolved.size(); f++)
    {
       // printf("Enum is: %i \n", int(m_stringSolved[f].r)); //Debug Only
        switch(m_stringSolved[f])
        {
        case LRules::Rule1:
            newString+= RHS_rules[int(LRules::Rule1)];
            break;
        case LRules::Rule2:
            newString+= RHS_rules[int(LRules::Rule2)];
            break;
        case LRules::Rule3:
            newString+= RHS_rules[int(LRules::Rule3)];
            break;
        case LRules::Rule4:
            newString+= RHS_rules[int(LRules::Rule4)];
            break;
        case LRules::Rule5:
            newString+= RHS_rules[int(LRules::Rule5)];
            break;
        case LRules::Rule6:
            newString+= RHS_rules[int(LRules::Rule6)];
            break;
        case LRules::Rule7:
            newString+= RHS_rules[int(LRules::Rule7)];
            break;
        case LRules::Rule8:
            newString+= RHS_rules[int(LRules::Rule8)];
            break;
        case LRules::Rule9:
            newString+= RHS_rules[int(LRules::Rule9)];
            break;
        case LRules::Rule10:
            newString+= RHS_rules[int(LRules::Rule10)];
            break;
        case LRules::Character:
            newString+= m_string[f];
            break;
        default:
            break;
        }
    }
    //printf("Final String is: %s \n", newString.c_str()); //Debug Only
    m_string = newString;
    m_generation ++;
    stringInterpertator();

}
