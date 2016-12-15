#ifndef LPARSER_H
#define LPARSER_H
#include "lObject.h"
#include "object.h"
#include <string>
#include <fstream>
#include <sstream>
class lParser
{
public:
    lParser();
    ~lParser();

    bool loadLObj(char * _lsytem_string_filepath, char *_variables_rules_filepath, lObject lObj);
    bool writeObj(char * filepath, object lObj);
    bool loadObj(char * filepath, object &obj);
    bool writeLObj(char * filepath, lObject lObj);
private:
};

#endif
