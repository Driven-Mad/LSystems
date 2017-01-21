#include "Image.h"
#include <cstdlib>
#include <Magick++.h>
#include <iostream>
#include "lParser.h"
int main()
{
 // object *obj = new object();
  lParser *pars = new lParser();
  lSystem *lsys = new lSystem();
  bool success;
  //bool success = pars->loadObj("cube.obj",*obj);

  success = pars->loadLSystem(*lsys);

  //lsys->stringInterpertator();
 // obj->printVerticies();



  lsys->printLSystem();
  lsys->increaseGeneration();
  lsys->increaseGeneration();
  lsys->printLSystem();
  return EXIT_SUCCESS;
}
