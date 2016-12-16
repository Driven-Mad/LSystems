#include "Image.h"
#include <cstdlib>
#include <Magick++.h>
#include <iostream>
#include "lParser.h"
int main()
{
  object *obj = new object();
  lParser *pars = new lParser();
  lSystem *lsys = new lSystem();

  bool success = pars->loadObj("cube.obj",*obj);

  success = pars->loadLSystem("lsystem.txt","rules.txt",*lsys);

  lsys->stringInterpertator();
 // obj->printVerticies();
  //lsys->printAll();

  //Image *img = new Image(720,480,24);
  //img->clearScreen(Colour(0,255,0));
  //img->setPixel(10,10,Colour(255,0,0));
  //img->setPixel(11,10,Colour(255,0,0));
  //img->setPixel(12,10,Colour(255,0,0));
  //img->setPixel(13,10,Colour(255,0,0));
  //
  //Magick::Image output(img->getWidth(),img->getHeight(),"RGB",Magick::CharPixel, img->get());
  ////
  //output.depth(img->getPixelDepth());
  //delete img;
  //output.write("Test.png");

  return EXIT_SUCCESS;
}
