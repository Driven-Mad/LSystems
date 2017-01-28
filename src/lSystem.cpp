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
    {LAlphabet::StartBranch,        &Turtle::startBranch},
    {LAlphabet::EndBranch,          &Turtle::endBranch}
};


lSystem::lSystem()
{

    m_generatedObject = new lObject();
    m_generation = 0;
}

lSystem::~lSystem()
{

}
void lSystem::stringInterpertator(std::string stringToBeInter,Turtle passedIntTurtle)
{

    printf("I'M HITTIIIIIIINNGGGGGGGGGGGGGGGGGGGGGGGGGGGGG \n");
    //interperate axiom of user rules etc.
    Turtle *T = new Turtle();
    //m_generatedObject->clearAll();
    T->resetTransformation();
    T->init(m_turtleAngle,m_turtleUnit);
    T->setPosition(passedIntTurtle.getPosition());
    T->setRotation(passedIntTurtle.getRotation());

    //NOTE: THIS LOOP IS NOT ACTUALLY UTILISING THE VERTS AND INDICES, THERE ARE DUPLICATED
    //      AND WILL NEED TO BE CHANGED EVENTUALLY TO RETRIEVE VERTS WITH ADDRESSES.


    if(T->active){
        for(unsigned int i = 0; i < stringToBeInter.size(); i++)
        {
           //if(stringToBeInter[i] == '[')
           //{
           //    size_t startOfBranch = i+1;
           //    printf("SOB = %i \n", startOfBranch);
           //    size_t endOfBranch = stringToBeInter.find(']',startOfBranch);
           //    printf("EOB = %i \n", endOfBranch);
           //    size_t length = (endOfBranch - startOfBranch) ;
           //    printf("L = %i \n", length);
           //    std::string myBranch =  stringToBeInter.substr(startOfBranch, length);
           //    printf("myBranch = %s \n", myBranch.c_str());
           //    stringInterpertator(myBranch,*T);
           //    i+= length;
           //    break;
           //
           //
           //}
            if(stringToBeInter[i] == 'F' || stringToBeInter[i] == 'H' )
            {
                //Add the current position
                m_generatedObject->addVert(T->getPosition());
                // add that index
                m_generatedObject->addIndicies(index);
                //Increase the index
                index++;

            }
            //Call appropriate function based on string
            AlphabetFunctions[AlphabetsStrings[stringToBeInter[i]]](*T);
            //update the turtle
            T->update();

            //IF the string variable we are reading in is a FULL DRAWN step
            if(stringToBeInter[i] == 'F' || stringToBeInter[i] == 'H')
            {
                //Add the current position
                m_generatedObject->addVert(T->getPosition());
                // add that index
                m_generatedObject->addIndicies(index);
                //Increase the index
                index++;

            }
        }
    }

}
void lSystem::stringInterpertator(std::string stringToBeInter)
{

    //interperate axiom of user rules etc.
    Turtle *T = new Turtle();
    m_generatedObject->clearAll();
    T->resetTransformation();
    T->init(m_turtleAngle,m_turtleUnit);
    index = 0;

    //NOTE: THIS LOOP IS NOT ACTUALLY UTILISING THE VERTS AND INDICES, THERE ARE DUPLICATED
    //      AND WILL NEED TO BE CHANGED EVENTUALLY TO RETRIEVE VERTS WITH ADDRESSES.


    if(T->active){
        for(unsigned int i = 0; i < stringToBeInter.size(); i++)
        {
            //SO CLOSE
            //if(stringToBeInter[i] == '[')
            //{
            //    size_t startOfBranch = i+1;
            //    printf("SOB = %i \n", startOfBranch);
            //    size_t endOfBranch = stringToBeInter.find(']',startOfBranch);
            //    printf("EOB = %i \n", endOfBranch);
            //    size_t length = (endOfBranch - startOfBranch) ;
            //    printf("L = %i \n", length);
            //    std::string myBranch =  stringToBeInter.substr(startOfBranch, length);
            //    printf("myBranch = %s \n", myBranch.c_str());
            //    stringInterpertator(myBranch,*T);
            //    i+= length;
            //
            //
            //}
            if(stringToBeInter[i] == 'F' || stringToBeInter[i] == 'H' )
            {
                //Add the current position
                m_generatedObject->addVert(T->getPosition());
                // add that index
                m_generatedObject->addIndicies(index);
                //Increase the index
                index++;

            }
            //Call appropriate function based on string
            AlphabetFunctions[AlphabetsStrings[stringToBeInter[i]]](*T);
            //update the turtle
            T->update();

            //IF the string variable we are reading in is a FULL DRAWN step
            if(stringToBeInter[i] == 'F' || stringToBeInter[i] == 'H')
            {
                //Add the current position
                m_generatedObject->addVert(T->getPosition());
                // add that index
                m_generatedObject->addIndicies(index);
                //Increase the index
                index++;

            }
        }
    }

}



void lSystem::printLSystem()
{
    printf("Lsystem is as follows: \n%s\n", m_string.c_str());

}

void lSystem::printVariables()
{
    printf("Angle is as follows: \n%f\n",m_turtleAngle );
    printf("Length is as follows: \n%f\n",m_turtleUnit );
    printf("Axiom is as follows: \n%s\n", m_axiom.c_str());
    printf("||||||||||||||Generation %i|||||||||||||||||| \n",m_generation);

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
       lRules rule = lRules(LHS_rules.size()-1);

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
       stringInterpertator(m_string);
   }


}

void lSystem::increaseGeneration()
{

    std::vector<lRules> m_stringSolved;

    for(size_t x= 0; x<m_string.length(); x++)
    {
        lRules c = lRules::Character;
        m_stringSolved.push_back(c);
    }

    lRules rule = lRules::Rule1;
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
        case lRules::Rule1:
            newString+= RHS_rules[int(lRules::Rule1)];
            break;
        case lRules::Rule2:
            newString+= RHS_rules[int(lRules::Rule2)];
            break;
        case lRules::Rule3:
            newString+= RHS_rules[int(lRules::Rule3)];
            break;
        case lRules::Rule4:
            newString+= RHS_rules[int(lRules::Rule4)];
            break;
        case lRules::Rule5:
            newString+= RHS_rules[int(lRules::Rule5)];
            break;
        case lRules::Rule6:
            newString+= RHS_rules[int(lRules::Rule6)];
            break;
        case lRules::Rule7:
            newString+= RHS_rules[int(lRules::Rule7)];
            break;
        case lRules::Rule8:
            newString+= RHS_rules[int(lRules::Rule8)];
            break;
        case lRules::Rule9:
            newString+= RHS_rules[int(lRules::Rule9)];
            break;
        case lRules::Rule10:
            newString+= RHS_rules[int(lRules::Rule10)];
            break;
        case lRules::Character:
            newString+= m_string[f];
            break;
        default:
            break;
        }
    }
    //printf("Final String is: %s \n", newString.c_str()); //Debug Only
    m_string = newString;
    m_generation ++;
    printf("||||||||||||||Generation %i|||||||||||||||||| \n",m_generation);
    stringInterpertator(m_string);

}


void lSystem::Reset()
{
    m_generatedObject->clearAll();
    m_rules.clear();
    m_generation = 0;
    m_turtleAngle = 0;
    m_turtleUnit = 0;
    m_axiom = "";
    m_string = "";

}
