#include <iostream>
#include <string>

using namespace std;

//Creating structure called Student
struct Student
{
  //Student characteristics:
  string name;
  int id;
  double gpa;
  //...other member variables...
};

int main()
{
  //Declare a Student object called `s`
  Student s;

  //Initialize `s`
  s.name = "John Smith";
  s.gpa = 7;
  s.id = 4;

  //Print out the info of the Student object `s`
  cout << "Student info: " << endl;
  cout << "Name: " << s.name << endl;
  cout << "ID: " << s.id << endl;
  cout << "GPA: " << s.gpa << endl;

  //...code...

  system("pause");

  return 0;
}