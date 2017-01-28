#ifndef LPARSER_H
#define LPARSER_H //LPARSER_H
#include"lSystem.h"
#include "object.h"
#include <GL/gl.h>
#include <string>
#include <fstream>
#include <sstream>
//--------------------------------------------------------------------------------------------------------------------------
/// @file lParser.h
/// @brief This is the parser class, it can read and write Lsystem files. load shader programs, and also load objects.
/// Soon to be added will be the ability to write objects out to file.
/// @author Lloyd Phillips
/// @version 1.2
/// @date 25/01/17
/// Revision History:
/// Development from original plane object loader to include multiple types of files to load
/// included is the program load and lsystem laoder.
/// @class lParser
/// @brief The class loads different objects.
//--------------------------------------------------------------------------------------------------------------------------


class lParser
{
public:
    lParser();
    ~lParser();
//--------------------------------------------------------------------------------------------------------------------------
/// READ
//--------------------------------------------------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief loads in an object from file into an instance of the class object.
    /// @param filepath - The filepath you wish to load the object from. (string)
    /// @param obj - The obj that you want to write your loaded object too. (object)
    /// @return returns true if successfully loaded object. (bool)
    //----------------------------------------------------------------------------------------------------------------------
    bool loadObj(const std::string &filepath, object &obj);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief loads in an lsystem from file into an instance of the class lSystem.
    /// Use default files (if not there, they will be created with default L-system)
    /// Default files are: LSystemFiles/rules.txt & LSystemFiles/lsystem.txt (Lsystem)
    /// @param lSys - The lSystem that you want to write your loaded lsystem too.
    /// @return returns true if successfully loaded lSystem. (bool)
    //----------------------------------------------------------------------------------------------------------------------
    bool loadLSystem(lSystem &lSys);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief loads in an lsystem from file into an instance of the class lSystem.
    /// Uses 2 file paths of your own.
    /// @param _lsytem_string_filepath is the filepath of the lsystem you want to load (string)
    /// @param _variables_rules_filepath is the filepath for the rules for the lsystem (string)
    /// @param lSys - The lSystem that you want to write your loaded lsystem too. (lSystem)
    /// @return returns true if successfully loaded lSystem. (bool)
    //----------------------------------------------------------------------------------------------------------------------
    bool loadLSystem(const std::string &lsytemStringFilepath, const std::string &variablesRulesFilepath, lSystem &lObj);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief loads any text file into a single string
    /// @param filepath is the filepath of the file you want to load (string)
    /// @param storage is the string you want to store your file in. (string)
    //----------------------------------------------------------------------------------------------------------------------
    void loadfile(const std::string &filepath, std::string &storage);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief loads any of the 3 main shaders, Fragment, Vertex, Geometry
    /// you pass in your program id, shader id, shader file path and the shader type.
    /// @param program is the program id you want to attach this shader to, to be eventually linked together.(GLuint)
    /// @param shader is the shader id you want to attach this too.(GLuint)
    /// @param shaderFilepath the filepath of the shader you want to read in.(string)
    /// @param shaderType either: GL_FRAGMENT_SHADER | GL_VERTEX_SHADER | GL_GEOMETRY_SHADER (GLenum)
    //----------------------------------------------------------------------------------------------------------------------
    void loadShader(GLuint &program, GLuint &shader, const std::string &shaderFilepath, GLenum shaderType);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief loads a program that will compile and link a vertex and fragment shader together.
    /// @param vertexShaderFilePath The file path of the vertex shader that you want to link into this program (string)
    /// @param fragmentShaderFilePath The file path of the fragment shader that you want to link into this program (string)
    /// @return returns the finished program ID needed for shader.(GLUint)
    //----------------------------------------------------------------------------------------------------------------------
    GLuint loadProgram(const std::string & vertexShaderFilePath, const std::string &fragmentShaderFilePath);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief loads a program that will compile and link a vertex, fragment and geometry shader together.
    /// @param vertexShaderFilePath The file path of the vertex shader that you want to link into this program (string)
    /// @param fragmentShaderFilePath The file path of the fragment shader that you want to link into this program (string)
    /// @param geometryShaderFilepath The file path of the geometry shader that you want to link into this program (string)
    /// @return returns the finished program ID needed for shader. will flag up error if unable to link or otherwise. (GLUint)
    //----------------------------------------------------------------------------------------------------------------------
    GLuint loadProgram(const std::string &vertexShaderFilePath, const std::string &fragmentShaderFilePath, const std::string &geoShaderFilePath);

//--------------------------------------------------------------------------------------------------------------------------
/// Write
//--------------------------------------------------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief !NOTE! NOT IMPLEMENTED !!NOTE! writes object to file
    /// @param filepath - The filepath you wish to load the object from. (string)
    /// @return returns true if successfully written object.
    //----------------------------------------------------------------------------------------------------------------------
    bool writeObj(const std::string & filepath, object Obj);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief writes in an lsystem to file from an instance of the class lSystem.
    /// Use default files (if not there, they will be created with default L-system)
    /// Default files are: LSystemFiles/rules.txt & LSystemFiles/lsystem.txt
    /// @param lSys - The lSystem that you want to write too file.(string)
    /// @return returns true if successfully written lSystem. (bool)
    //----------------------------------------------------------------------------------------------------------------------
    //Write default files in both cases.
    bool writeLSystem(lSystem &lsys);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief writes in an lsystem *RULES ONLY* to file from an instance of the class lSystem.
    /// Use default files (if not there, they will be created with default L-system)
    /// Default files are: LSystemFiles/rules.txt
    /// @param lSys - The lSystem that you want to write too file.(lSystem)
    /// @return returns true if successfully written lSystem. (bool)
    //----------------------------------------------------------------------------------------------------------------------
    bool writeLSystemRulesOnly(lSystem &lsys);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief writes in an lsystem *RULES ONLY* to file from an instance of the class lSystem
    /// to your own file.
    /// @param _variables_rules_filepath - the filepath which you want to save out your rules too.(string)
    /// @param lSys - The lSystem that you want to write too file.(lSystem)
    /// @return returns true if successfully written lSystem. (bool)
    //----------------------------------------------------------------------------------------------------------------------
    bool writeLSystemRulesOnly(const std::string & variablesRulesFilepath, lSystem &lSys);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief writes in an lsystem *SYSTEM ONLY* to file from an instance of the class lSystem.
    /// Use default files (if not there, they will be created with default L-system)
    /// Default files are:& LSystemFiles/lsystem.txt
    /// @param lSys - The lSystem that you want to write too file. (lSystem)
    /// @return returns true if successfully written lSystem. (bool)
    //----------------------------------------------------------------------------------------------------------------------
    bool writeLSystemSystemOnly(lSystem &lObj);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief writes in an lsystem *SYSTEM ONLY* to file from an instance of the class lSystem.
    /// Use default files (if not there, they will be created with default L-system)
    /// Default files are:& LSystemFiles/lsystem.txt
    /// @param _lsytem_string_filepath - the filepath which you want to save out your system too.(string)
    /// @param lSys - The lSystem that you want to write too file.(lSystem)
    /// @return returns true if successfully written lSystem. (bool)
    //----------------------------------------------------------------------------------------------------------------------
    bool writeLSystemSystemOnly(const std::string & lsytemStringFilepath, lSystem &lsys);




protected:
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief checks if our shader has successfully compiled
    /// @param lSys - The lSystem that you want to write too file.
    /// @return returns true if successfully compiled. (bool)
    //----------------------------------------------------------------------------------------------------------------------
    bool CheckShaderCompiled(GLuint shader);


private:

};

#endif //!LPARSER_H
