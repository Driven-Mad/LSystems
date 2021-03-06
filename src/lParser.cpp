#include "lParser.h"


lParser::lParser()
{

}

lParser::~lParser()
{

}

bool lParser::writeObj(const std::string & filepath, object Obj)
{
    //Object writer (ref old code - re-write for c++ 11
    bool success = false;
    return success;
}

bool lParser::loadObj(const std::string & filepath, object &obj)
{
        //STORGE CONTAINERS

        //VERTICIES
        std::vector<unsigned int> vetexIndicies; //F 1,4,7
        std::vector<ngl::Vec3> t_Verts; //V

        //UV's
        std::vector<unsigned int> uvIndicies; //F 2,5,8
        std::vector<ngl::Vec2> t_UVs; //VT

        //NORMALS
        std::vector<unsigned int> normalIndicies;// F 3, 6,9
        std::vector<ngl::Vec3> t_Norms; //VN

        std::string line;
        std::ifstream myObjectFile(filepath);

        //Succesful Files REad
        bool success = false;
        if(myObjectFile.is_open())
        {
            printf("File has been opened \n");
        }

        if(myObjectFile.is_open())
        {
            while(std::getline(myObjectFile, line))
            { //Going through every line of the document - PER LINE
                //////////////////////////////////////////
                //VERTICIES//////
                //////////////////////////////////////////
                if(line[0] == 'v' && line[1] == ' ')
                { //<---------- //If line starts with "V " then continue, did try V however got the whole document
                    std::vector<std::string> split_string; //Storage for our line to be split into
                    std::string buffer; //Buffer to store splitting of string
                    std::stringstream ss(line); //streaming the line
                    while(ss >> buffer)
                    { // splits the string by white spaces
                        split_string.push_back(buffer); //Adds the seperate words into our storage for our  line split
                    }
                    if(split_string.size() > 4)
                    {
                        printf("File has too many options with verticies for our object loader, sorry. \n"); //ERROR checking incase theres more than just an Identifier,X,Y,Z
                        myObjectFile.close(); //close file

                        break;
                    }
                    ngl::Vec3 vert; //temp value to store the verticie
                    vert.m_x = std::stof(split_string[1]); //pass the value of the string and convert to a float (X)
                    vert.m_y = std::stof(split_string[2]);//pass the value of the string and convert to a float 󰀀
                    vert.m_z = std::stof(split_string[3]);//pass the value of the string and convert to a float (Z)
                    t_Verts.push_back(vert);//Add the verticie to our verticie storage.
                }// <------------


                //////////////////////////////////////////
                //UVS//////
                //////////////////////////////////////////
                if(line[0] == 'v' && line[1] == 't')
                { //<---------- //If line starts with "VT" then continue
                    std::vector<std::string> split_string; //Storage for our line to be split into
                    std::string buffer; //Buffer to store splitting of string
                    std::stringstream ss(line); //streaming the line
                    while(ss >> buffer)
                    { // splits the string by white spaces
                        split_string.push_back(buffer); //Adds the seperate words into our storage for our  line split
                    }
                    if(split_string.size() > 3)
                    {
                        printf("File has too many options with UVS for our object loader, sorry. \n"); //ERROR checking incase theres more than just an Identifier,X,Y
                        myObjectFile.close(); //close file
                        break;
                    }
                    ngl::Vec2 uv; //temp value to store the UV
                    uv.m_x = std::stof(split_string[1]); //pass the value of the string and convert to a float (X)
                    uv.m_y = std::stof(split_string[2]);//pass the value of the string and convert to a float 󰀀
                    t_UVs.push_back(uv);//Add the UV to our UVs storage.
                }// <------------


                //////////////////////////////////////////
                //NORMALS//////
                //////////////////////////////////////////
                if(line[0] == 'v' && line[1] == 'n')
                { //<---------- //If line starts with "Vn" then continue
                    std::vector<std::string> split_string; //Storage for our line to be split into
                    std::string buffer; //Buffer to store splitting of string
                    std::stringstream ss(line); //streaming the line
                    while(ss >> buffer)
                    { // splits the string by white spaces
                        split_string.push_back(buffer); //Adds the seperate words into our storage for our  line split
                    }
                    if(split_string.size() > 4)
                    {
                        printf("File has too many options with Normals for our object loader, sorry. \n"); //ERROR checking incase theres more than just an Identifier,X,Y,Z
                        myObjectFile.close(); //close file
                        break;
                    }
                    ngl::Vec3 norm; //temp value to store the normal
                    norm.m_x = std::stof(split_string[1]); //pass the value of the string and convert to a float (X)
                    norm.m_y = std::stof(split_string[2]);//pass the value of the string and convert to a float 󰀀
                    norm.m_z = std::stof(split_string[3]);//pass the value of the string and convert to a float (Z)
                    t_Norms.push_back(norm);//Add the normal to our normal storage.m_
                }// <------------

                //////////////////////////////////////////
                //Faces//////
                //////////////////////////////////////////
                if(line[0]=='f')
                {
                    ///////////SPLITTING AT SPACES
                    std::vector<std::string> split_string; //Storage for our line to be split into
                    std::string buffer; //Buffer to store splitting of string
                    std::stringstream ss(line); //streaming the line
                    while(ss >> buffer)
                    { // splits the string by white spaces
                        split_string.push_back(buffer); //Adds the seperate words into our storage for our  line split
                    }
                    if(split_string.size() == 4)
                    {
                        //SPLITTING AT '/' in each 3 points
                        //Point 1 of the face
                        std::string buffer1;
                        std::stringstream face_point1(split_string[1]);
                        std::vector<std::string> face_point1_details;
                        while(std::getline(face_point1, buffer1, '/'))
                        {
                            face_point1_details.push_back(buffer1);
                        }
                        vetexIndicies.push_back(std::stoi(face_point1_details[0]));
                        uvIndicies.push_back(std::stoi(face_point1_details[1]));
                        normalIndicies.push_back(std::stoi(face_point1_details[2]));
                        //Point 2 of the face
                        std::string buffer2;
                        std::stringstream face_point2(split_string[2]);
                        std::vector<std::string> face_point2_details;
                        while(std::getline(face_point2, buffer2, '/'))
                        {
                            face_point2_details.push_back(buffer2);
                        }
                        vetexIndicies.push_back(std::stoi(face_point2_details[0]));
                        uvIndicies.push_back(std::stoi(face_point2_details[1]));
                        normalIndicies.push_back(std::stoi(face_point2_details[2]));
                        //Point 3 of the face
                        std::string buffer3;
                        std::stringstream face_point3(split_string[3]);
                        std::vector<std::string> face_point3_details;
                        while(std::getline(face_point3, buffer3, '/'))
                        {
                            face_point3_details.push_back(buffer3);
                        }
                        vetexIndicies.push_back(std::stoi(face_point3_details[0]));
                        uvIndicies.push_back(std::stoi(face_point3_details[1]));
                        normalIndicies.push_back(std::stoi(face_point3_details[2]));
                    }
                    if(split_string.size() == 5)
                    {
                        //SPLITTING AT '/' in each 3 points
                        //TRIANGLE 1
                        //Point 1 of the face
                        std::string buffer4;
                        std::stringstream face_point4(split_string[1]);
                        std::vector<std::string> face_point4_details;
                        while(std::getline(face_point4, buffer4, '/'))
                        {
                            face_point4_details.push_back(buffer4);
                        }
                        vetexIndicies.push_back(std::stoi(face_point4_details[0]));
                        uvIndicies.push_back(std::stoi(face_point4_details[1]));
                        normalIndicies.push_back(std::stoi(face_point4_details[2]));
                        //Point 2 of the face
                        std::string buffer5;
                        std::stringstream face_point5(split_string[2]);
                        std::vector<std::string> face_point5_details;
                        while(std::getline(face_point5, buffer5, '/'))
                        {
                            face_point5_details.push_back(buffer5);
                        }
                        vetexIndicies.push_back(std::stoi(face_point5_details[0]));
                        uvIndicies.push_back(std::stoi(face_point5_details[1]));
                        normalIndicies.push_back(std::stoi(face_point5_details[2]));
                        //Point 3 of the face
                        std::string buffer6;
                        std::stringstream face_point6(split_string[3]);
                        std::vector<std::string> face_point6_details;
                        while(std::getline(face_point6, buffer6, '/'))
                        {
                            face_point6_details.push_back(buffer6);
                        }
                        vetexIndicies.push_back(std::stoi(face_point6_details[0]));
                        uvIndicies.push_back(std::stoi(face_point6_details[1]));
                        normalIndicies.push_back(std::stoi(face_point6_details[2]));

                        //TRIANGLE 2
                        //SPLITTING AT '/' in each 3 points
                        //Point 1 of the face
                        std::string buffer1;
                        std::stringstream face_point1(split_string[2]);
                        std::vector<std::string> face_point1_details;
                        while(std::getline(face_point1, buffer1, '/'))
                        {
                            face_point1_details.push_back(buffer1);
                        }
                        vetexIndicies.push_back(std::stoi(face_point1_details[0]));
                        uvIndicies.push_back(std::stoi(face_point1_details[1]));
                        normalIndicies.push_back(std::stoi(face_point1_details[2]));
                        //Point 2 of the face
                        std::string buffer2;
                        std::stringstream face_point2(split_string[3]);
                        std::vector<std::string> face_point2_details;
                        while(std::getline(face_point2, buffer2, '/'))
                        {
                            face_point2_details.push_back(buffer2);
                        }
                        vetexIndicies.push_back(std::stoi(face_point2_details[0]));
                        uvIndicies.push_back(std::stoi(face_point2_details[1]));
                        normalIndicies.push_back(std::stoi(face_point2_details[2]));
                        //Point 3 of the face
                        std::string buffer3;
                        std::stringstream face_point3(split_string[4]);
                        std::vector<std::string> face_point3_details;
                        while(std::getline(face_point3, buffer3, '/'))
                        {
                            face_point3_details.push_back(buffer3);
                        }
                        vetexIndicies.push_back(std::stoi(face_point3_details[0]));
                        uvIndicies.push_back(std::stoi(face_point3_details[1]));
                        normalIndicies.push_back(std::stoi(face_point3_details[2]));
                    }
                    if(split_string.size() > 5)
                    {
                        //In non quads or triangles.
                        printf("File has too many options with faces for our object loader, sorry. \n try converting to triangles or quads. \n"); //ERROR checking incase theres more than just an Identifier,P1 details,P2 details,P3 details
                        myObjectFile.close(); //close filesuccess = true;
                        break;
                    }

                }

            }
            myObjectFile.close();

            for(size_t i = 0; i<vetexIndicies.size(); i++)
            {
                size_t vertexIndex = vetexIndicies[i];
                size_t UVIndex = uvIndicies[i];
                size_t normalIndex = normalIndicies[i];

                ngl::Vec3 vertex = t_Verts[vertexIndex -1];
                ngl::Vec2 UV = t_UVs[UVIndex -1];
                UV.m_y = 1.0f - UV.m_y;
                ngl::Vec3 normal = t_Norms[normalIndex -1];

                //Pushing out of the function
                obj.addVert(vertex);
                obj.addUV(UV);
                obj.addNormal(normal);
                if(success != true)
                {
                    success = true;
                }
             }

        }else
        {
            //Error checking to see if file can be read or not.
            printf("File could not be read by this object loader, so sorry for any inconvinience. \n");
        }

    return success;
}


bool lParser::writeLSystemRulesOnly(const std::string &variablesRulesFilepath, lSystem &lSys)
{
    bool success = false;

    //check if we can open the file.
    std::ifstream iMyRulesFile(variablesRulesFilepath);
    if(iMyRulesFile.is_open())
    {
        //if it is opened then open it as a writable file
        std::ofstream myRulesFile(variablesRulesFilepath);
        //If ifstream can open, file exists, write to it.
        printf("%s File has been opened \n",variablesRulesFilepath.c_str());
        //create a temporary array for a rules.
        std::vector<std::string> rules = lSys.getRules();
        //write rules to file
        myRulesFile <<"#Rules \n";
        for(size_t i = 0; i < rules.size(); i++)
        {
            myRulesFile <<"rule " << std::to_string(i) << " " << rules[i] << "\n";
        }
        //write variables to file
        myRulesFile <<"#Variables \n";
        myRulesFile <<"angle " << std::to_string(lSys.getTurtleAngle()) << "\n";
        myRulesFile <<"length " << std::to_string(lSys.getTurtleUnit()) << "\n";
        myRulesFile <<"axiom " << lSys.getAxiom() << "\n";
        myRulesFile <<"generation " << std::to_string(lSys.getGeneration()) << "\n";
        //close up both files.
        myRulesFile.close();
        iMyRulesFile.close();
        success = true;
    }else
    {
        //Else the file doesn't exist, close it up and return false
        printf("%s does not exist \n",variablesRulesFilepath.c_str());
        iMyRulesFile.close();
        success = false;
    }
    return success;
}

bool lParser::writeLSystemRulesOnly(lSystem &lSys)
{
    const std::string _variables_rules_filepath = "LSystemFiles/rules.txt";

    std::ifstream iMyRulesFile(_variables_rules_filepath);
    //check if file already exists.
    if(!iMyRulesFile.is_open())
    {
        printf("Default file does not exist, creating rules.txt \n",_variables_rules_filepath.c_str());
    }
    iMyRulesFile.close();
    //if either way. Write to the default file.
    std::ofstream myRulesFile(_variables_rules_filepath);
    //If ifstream can open, file exists, write to it.
    printf("%s File has been opened \n",_variables_rules_filepath.c_str());
    //write our rules and variables to the file
    std::vector<std::string> rules = lSys.getRules();
    myRulesFile <<"#Rules \n";
    for(size_t i = 0; i < rules.size(); i++)
    {
        myRulesFile <<"rule " << std::to_string(i) << " " << rules[i] << "\n";
    }
    myRulesFile <<"#Variables \n";
    myRulesFile <<"angle " << std::to_string(lSys.getTurtleAngle()) << "\n";
    myRulesFile <<"length " << std::to_string(lSys.getTurtleUnit()) << "\n";
    myRulesFile <<"axiom " << lSys.getAxiom() << "\n";
    myRulesFile <<"generation " << std::to_string(lSys.getGeneration()) << "\n";
    //close up, return successful.
    myRulesFile.close();

    return true;
}

bool lParser::writeLSystemSystemOnly(lSystem &lSys)
{
    std::string _lsytem_string_filepath = "LSystemFiles/lsystem.txt"; //default file name will be "lsystem.txt

    //Check if file already exists just so that we can inform the user if that it's newly created.
    std::ifstream iMyRulesFile(_lsytem_string_filepath);
    if(!iMyRulesFile.is_open())
    {
        printf("Default file does not exist, creating lsystem.txt \n",_lsytem_string_filepath.c_str());
    }
    iMyRulesFile.close();
    //!Finished Check
    //Write our variables to the file.
    std::ofstream myRulesFile(_lsytem_string_filepath);
    printf("%s File has been opened \n",_lsytem_string_filepath.c_str());
    myRulesFile << lSys.getLSystem();
    myRulesFile.close();

    return true;
}

bool lParser::writeLSystemSystemOnly(const std::string &lsytemStringFilepath, lSystem &lSys)
{
    bool success = false;
    std::ifstream iMyRulesFile(lsytemStringFilepath);
    //check if file exists as it's user defined
    if(iMyRulesFile.is_open())
    {
        std::ofstream myRulesFile(lsytemStringFilepath);
        //If if stream can open, file exists, write to it.
        printf("%s File has been opened \n",lsytemStringFilepath.c_str());
        myRulesFile << lSys.getLSystem();

        //close up files
        myRulesFile.close();
        iMyRulesFile.close();
        success = true;
    }else
    {
        printf("%s does not exist \n",lsytemStringFilepath.c_str());
        //close up file, and return false.
        iMyRulesFile.close();
        success = false;
    }
    return success;
}

bool lParser::writeLSystem(lSystem &lsys)
{
    bool success = writeLSystemSystemOnly(lsys);
    if(success)
    {
        success =writeLSystemRulesOnly(lsys);
    }
    return success;
}

bool lParser::loadLSystem(const std::string & lsytemStringFilepath, const std::string &variablesRulesFilepath, lSystem &lSys)
{
    bool success = false;
    std::string _lsytem_string_filepath = lsytemStringFilepath;
    std::string _variables_rules_filepath = variablesRulesFilepath;
    std::string line;
    std::ifstream myLsystemFile(_lsytem_string_filepath);
    std::ifstream myVariablesRulesFile(_variables_rules_filepath);


    if(myLsystemFile.is_open())
    {
        printf("%s File has been opened \n",_lsytem_string_filepath.c_str());
        while(std::getline(myLsystemFile, line))//get everyline of the lsystem
        {
            lSys.setLSystem(lSys.getLSystem().append(line)); //add every line to our system
            //need to check if everything is apart of our alphabet.
        }
        myLsystemFile.close();
        success = true;
    }else
    {
        myLsystemFile.close();
        success = writeLSystemSystemOnly(lSys);
    }

    if(myVariablesRulesFile.is_open())
    {
        printf("%s File has been opened \n",_variables_rules_filepath.c_str());
        while(std::getline(myVariablesRulesFile, line))//get everyline of the lsystem
        {
            std::vector<std::string> split_string; //Storage for our line to be split into
            std::string buffer; //Buffer to store splitting of string
            std::stringstream ss(line); //streaming the line
            if(line != "" || line.empty() == false)
            {
                while(ss >> buffer)
                { // splits the string by white spaces

                    split_string.push_back(buffer); //Adds the seperate words into our storage for our  line split

                }
                //chuck all our rules and variables into our lsystems turtle.
                if(split_string[0] == "rule")
                {
                    std::string r;
                    for(unsigned int x = 2; x < split_string.size();x++)
                    {
                        r.append(split_string[x]);
                    }
                    lSys.addRule(r);
                }
                if(split_string[0]== "angle")
                {
                    lSys.setTurtleAngle(std::stof(split_string[1]));
                }
                if(split_string[0]== "length")
                {
                    lSys.setTurtleUnit(std::stof(split_string[1]));
                }
                if(split_string[0]== "axiom")
                {
                    lSys.setAxiom(split_string[1]);
                }
                if(split_string[0]== "generation")
                {
                    lSys.setGeneration(std::stoi(split_string[1]));
                }
                success = true;
            }

        }
        success = true;
        myVariablesRulesFile.close();
    }
    else
    {

        myVariablesRulesFile.close();
        success = writeLSystemRulesOnly(lSys);
    }


    return success;

}


bool lParser::loadLSystem(lSystem &lSys)
{
    bool success = false;
    const std::string  _lsytem_string_filepath = "LSystemFiles/lsystem.txt" ;
    const std::string  _variables_rules_filepath = "LSystemFiles/rules.txt";
    std::string line;
    std::ifstream myLsystemFile(_lsytem_string_filepath);
    std::ifstream myVariablesRulesFile(_variables_rules_filepath);


    if(myLsystemFile.is_open())
    {
        printf("%s File has been opened \n",_lsytem_string_filepath.c_str());
        while(std::getline(myLsystemFile, line))//get everyline of the lsystem
        {
            lSys.setLSystem(lSys.getLSystem().append(line)); //add every line to our system
            //need to check if everything is apart of our alphabet.
        }
        myLsystemFile.close();
        success = true;
    }else
    {
        myLsystemFile.close();
        success = writeLSystemSystemOnly(lSys);
    }

    if(myVariablesRulesFile.is_open())
    {
        printf("%s File has been opened \n",_variables_rules_filepath.c_str());
        while(std::getline(myVariablesRulesFile, line))//get everyline of the lsystem
        {
            std::vector<std::string> split_string; //Storage for our line to be split into
            std::string buffer; //Buffer to store splitting of string
            std::stringstream ss(line); //streaming the line
            if(line != "" || line.empty() == false)
            {
                while(ss >> buffer)
                { // splits the string by white spaces

                    split_string.push_back(buffer); //Adds the seperate words into our storage for our  line split

                }
                //chuck all our rules and variables into our lsystems turtle.
                if(split_string[0] == "rule")
                {
                    std::string r;
                    for(unsigned int x = 2; x < split_string.size();x++)
                    {
                        r.append(split_string[x]);
                    }
                    lSys.addRule(r);
                }
                if(split_string[0]== "angle")
                {
                    lSys.setTurtleAngle(std::stof(split_string[1]));
                }
                if(split_string[0]== "length")
                {
                    lSys.setTurtleUnit(std::stof(split_string[1]));
                }
                if(split_string[0]== "axiom")
                {
                    lSys.setAxiom(split_string[1]);
                }
                if(split_string[0]== "generation")
                {
                    lSys.setGeneration(std::stoi(split_string[1]));
                }
                success = true;
            }

        }
        success = true;
        myVariablesRulesFile.close();
    }
    else
    {

        myVariablesRulesFile.close();
        success = writeLSystemRulesOnly(lSys);
    }


    return success;

}

void lParser::loadfile(const std::string &filepath, std::string &storage)
{
    //read in file
    std::ifstream t(filepath);
    std::stringstream buffer;
    if(t.is_open())
    {
        buffer << t.rdbuf();
        storage = buffer.str();
    }else
    {
        printf("%s doe not exist please check naming convention", filepath.c_str());
    }
    t.close();
}

void lParser::loadShader(GLuint &program, GLuint &shader, const std::string &shaderFilepath, GLenum shaderType)
{
    //store our shader into a string
    std::string shaderStorage;
    loadfile(shaderFilepath,shaderStorage);
    //create our shader
    shader = glCreateShader(shaderType);
    const GLchar* str = shaderStorage.c_str();
    glShaderSource(shader,1,&str,NULL);
    //compile our shader and do some checks to if it compiled successfuly.
    glCompileShader(shader);
    if( CheckShaderCompiled( shader ) ){
        printf("%s successfully compiled \n", shaderFilepath.c_str());
    }
    else{
        printf("%s failed to compiled \n", shaderFilepath.c_str());
        return;
    }
    //attach shader to our program
    glAttachShader(program,shader);
    //link program up.
    glLinkProgram(program);
}

bool lParser::CheckShaderCompiled( GLuint shader )
{
    GLint compiled;
    glGetShaderiv( shader, GL_COMPILE_STATUS, &compiled );
    if ( !compiled )
    {
        GLsizei len;
        glGetShaderiv( shader, GL_INFO_LOG_LENGTH, &len );
        // OpenGL will store an error message as a string that we can retrieve and print
        GLchar* log = new GLchar[len+1];
        glGetShaderInfoLog( shader, len, &len, log );
        std::cerr << "ERROR: Shader compilation failed: " << log << std::endl;
        delete [] log;
        return false;
    }
    return true;
}


GLuint lParser::loadProgram(const std::string &vertexShaderFilePath, const std::string &fragmentShaderFilePath)
{
    //create our program
    GLuint program = glCreateProgram();
    GLuint vertShader, fragShader;
    //load our vertex shader and fragment shader.
    loadShader(program,vertShader,vertexShaderFilePath,GL_VERTEX_SHADER);
    loadShader(program,fragShader,fragmentShaderFilePath,GL_FRAGMENT_SHADER);
    GLint linked;
    //check that they have successfully linked.
    glGetProgramiv(program, GL_LINK_STATUS, &linked );
    if ( linked )
    {
        printf("Program successfully linked \n ");
        //delete as no need for shaders anymore as they are attached to our progran.
        glDeleteShader(vertShader);
        glDeleteShader(fragShader);
        return program;

    }
    else
    {
        //chuck out errors
        GLsizei len;
        glGetProgramiv( program, GL_INFO_LOG_LENGTH, &len );
        GLchar* log = new GLchar[len+1];
        glGetProgramInfoLog( program, len, &len, log );
        std::cerr << "ERROR: Shader linking failed: " << log << std::endl;
        delete [] log;
        return 0;
    }


}

GLuint lParser::loadProgram(const std::string & vertexShaderFilePath, const std::string & fragmentShaderFilePath, const std::string & geoShaderFilePath)
{
    GLuint program = glCreateProgram();
    GLuint vertShader, fragShader, geoShader;
    //load our vertex,frag,geo shaders.
    loadShader(program,vertShader,vertexShaderFilePath,GL_VERTEX_SHADER);
    loadShader(program,fragShader,fragmentShaderFilePath,GL_FRAGMENT_SHADER);
    loadShader(program,geoShader,geoShaderFilePath,GL_GEOMETRY_SHADER);
    //make sure they're all linked up.
    GLint linked;
    glGetProgramiv(program, GL_LINK_STATUS, &linked );
    if ( linked )
    {
        printf("Program successfully linked \n ");
        //delete as no need for shaders anymore as they are attached to our progran.
        glDeleteShader(vertShader);
        glDeleteShader(fragShader);
        glDeleteShader(geoShader);
        return program;

    }
    else
    {
        //chuck out errors
        GLsizei len;
        glGetProgramiv( program, GL_INFO_LOG_LENGTH, &len );
        GLchar* log = new GLchar[len+1];
        glGetProgramInfoLog( program, len, &len, log );
        std::cerr << "ERROR: Shader linking failed: " << log << std::endl;
        delete [] log;
        return 0;
    }
}


