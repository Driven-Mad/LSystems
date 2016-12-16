#ifndef LPARSER_H
#define LPARSER_H
#include"lSystem.h"
#include "object.h"

#include <string>
#include <fstream>
#include <sstream>

#include <boost/tokenizer.hpp>
#include <boost/spirit/include/qi.hpp>

namespace qi = boost::spirit::qi;
namespace spt = boost::spirit;

class lParser
{
public:
    lParser();
    ~lParser();


    typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
    bool loadLSystem(const std::string &_lsytem_string_filepath, const std::string &_variables_rules_filepath, lSystem &lObj);
    bool writeObj(const std::string & filepath, object lObj);
    bool loadObj(const std::string &filepath, object &obj);
    bool writeLObj(const std::string & filepath, lObject lObj);

    void parseLSystem(tokenizer::iterator &_firstWord);
    void parseAngle(tokenizer::iterator &_firstWord);
    void parseAxiom(tokenizer::iterator &_firstWord);
    void parseGeneration(tokenizer::iterator &_firstWord);


private:
};

#endif
