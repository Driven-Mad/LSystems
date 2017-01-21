#ifndef LPARSER_H
#define LPARSER_H
#include"lSystem.h"
#include "object.h"

#include <string>
#include <fstream>
#include <sstream>


class lParser
{
public:
    lParser();
    ~lParser();


    bool loadObj(const std::string &filepath, object &obj);
    bool writeObj(const std::string & filepath, object lObj);

    //Write default files in both cases.
    bool writeLObj(lSystem &lObj);

    //Use default files
    bool writeLObjRulesOnly(lSystem &lObj);
    //Overloaded to write to your own files
    bool writeLObjRulesOnly(const std::string & _variables_rules_filepath, lSystem &lObj);

    //Use default files
    bool writeLObjSystemOnly(lSystem &lObj);
    //Overloaded to write to your own files
    bool writeLObjSystemOnly(const std::string & _lsytem_string_filepath, lSystem &lObj);


    //Use default files (if not there, they will be created with default L-system
    bool loadLSystem(lSystem &lObj);
    //Overloaded to use your own
    bool loadLSystem(const std::string &_lsytem_string_filepath, const std::string &_variables_rules_filepath, lSystem &lObj);



private:

};

#endif
