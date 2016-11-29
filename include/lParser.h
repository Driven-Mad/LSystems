#ifndef LPARSER_H
#define LPARSER_H
#include "lObject.h"
#include "object.h"
class lParser
{
public:
    lParser();
    ~lParser();

    bool loadLObj(char * filepath, lObject lObj);
    bool writeObj(char * filepath, object lObj);
    bool loadObj(char * filepath, object &obj);
    bool writeLObj(char * filepath, lObject lObj);
private:
};

#endif
