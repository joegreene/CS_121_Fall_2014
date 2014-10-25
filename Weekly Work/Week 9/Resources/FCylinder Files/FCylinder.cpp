#include "FCylinder.h"

//default constructor
FCylinder::FCylinder()
{
  //default initialization
  radius = height = 1;
}

//overloaded constructor
FCylinder::FCylinder(double r, double h)
{
  //First assign default value
  radius = height = 1;

  //Afterwards, attempt to assign the values of r, h to radius, height
  setRadius(r);
  setHeight(h);

  //NOTE: If setRadius does not work, then radius is the default value of 1. 
  //      If setHeight does not work, then height is the default value of 1.
}

//copy constructor; I included this to show what a copy constructor does
FCylinder::FCylinder(const FCylinder& fc)
{
  //We're allowed to use the dot operator here because we're within 
  //the "same" class

  radius = fc.radius;
  height = fc.height;
}

//deconstructor
FCylinder::~FCylinder()
{
  cout << "Destroyed a FCylinder.\n";
}

//---------------------Getter Methods---------------------//
//returns radius
double FCylinder::getRadius()
{
  return radius;
}

//returns height (TO-DO)
double FCylinder::getHeight()
{
  return radius;
}

//---------------------Setter Methods---------------------//
//Set radius (as long as r > 0, else keep original)
void FCylinder::setRadius(double r)
{
  if(r > 0)
  {
    radius = r;
  }
  else
  {
    cout << "Attempted to assign invalid radius size! Retaining current radius value.\n";
  }
}

//Set height (as long as h > 0, else keep original)
void FCylinder::setHeight(double h)
{
  //TO-DO
  if(h > 0)
  {
    height = h;
  }
  else
  {
    cout << "Attempted to assign invalid height size! Retaining current height value.\n";
  }
}
    
//----------------------Misc. Methods---------------------//
//returns surface area of FCylinder
double FCylinder::computeSurfaceArea()
{
  return 2 * PI * radius * height;
}
//returns volume of FCylinder (TO-DO)
double FCylinder::computeVolume()
{
  //Volume = pi * r^2 * h = pi * r * r * h
  return PI * radius * radius * height;
}

//prints member variables of FCylinder class to console output (TO-DO)
void FCylinder::printSelf()
{
  cout << "Radius: " << radius << endl;
  cout << "Height: " << height << endl;
}