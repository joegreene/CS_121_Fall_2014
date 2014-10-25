/*
  NOTE: When we include "FCylinder.h", we're also including the libraries and namespaces          	 it includes (that is: the library "iostream" and the namespace "std")
*/     

#include "FCylinder.h"

void class_area();

int main()
{
  cout << "Start of program.";
  cout << "\n-------------------------\n";

  //Function made solely to show when the deconstructor is called
  class_area();

  cout << "\n-------------------------\n";

  //Custom exit prompt
  cout << "End of program. Press ENTER to continue.";
  cin.ignore(1000, '\n');

  return 0;
}
void class_area()
{
  //Example of each type of constructor in use
  FCylinder first_cyl;             //default constructor
  FCylinder second_cyl(7.5, 4.0);  //overloaded constructor
  FCylinder third_cyl(first_cyl);  //copy constructor

  //Print out each cylinder (before operations)

  //I added fancy prints to make it easier to read in console
  cout << "First (Before):" << endl;
  cout << "------\n";
  first_cyl.printSelf();

  cout << "Second (Before):" << endl;
  cout << "-------\n";
  second_cyl.printSelf();

  cout << "Third (Before):" << endl;
  cout << "------\n";
  third_cyl.printSelf();

  cout << endl;

  //Assign first_cyl's radius and height equal to second_cyl's (you can use '=' or getters)
  
  /*Two ways to do this:
    1) Use second_cyl's getRadius and getHeight as an argument for first_cyl's setRadius 
       and setHeight
    2) Use the assignment operator (if not implemented, this will copy all member variables 
       from the right object to the left object).
  */

  first_cyl.setHeight(second_cyl.getHeight()); //1)
  first_cyl.setRadius(second_cyl.getRadius()); //1)

  first_cyl = second_cyl;                      //2)

  //Set the radius of third_cyl equal to 14 and height to 13
  third_cyl.setRadius(14);
  third_cyl.setHeight(13);

  //Print out each cylinder's surface area and volume (NOTE: Each method returns doubles)
  cout << "first_cyl's SA and VOL:" << endl;
  cout << "-----------------------\n";
  cout << "Surface area: " << first_cyl.computeSurfaceArea() << endl;
  cout << "Volume: " << first_cyl.computeVolume() << endl;

  cout << "second_cyl's SA and VOL:" << endl;
  cout << "------------------------\n";
  cout << "Surface area: " << second_cyl.computeSurfaceArea() << endl;
  cout << "Volume: " << second_cyl.computeVolume() << endl;

  cout << "third_cyl's SA and VOL:" << endl;
  cout << "-----------------------\n";
  cout << "Surface area: " << third_cyl.computeSurfaceArea() << endl;
  cout << "Volume: " << third_cyl.computeVolume() << endl;

  cout << endl;

  //Print out each cylinder again (after operations)

  //I added fancy prints to make it easier to read in console
  cout << "First (After):" << endl;
  cout << "------\n";
  first_cyl.printSelf();

  cout << "Second (After):" << endl;
  cout << "-------\n";
  second_cyl.printSelf();

  cout << "Third (After):" << endl;
  cout << "------\n";
  third_cyl.printSelf();

  cout << endl;

  cout << "Leaving scope of class_area (destroying all variables local to this function)" << endl;
}