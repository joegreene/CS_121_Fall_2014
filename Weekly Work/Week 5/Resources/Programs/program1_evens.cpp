/*
  Name: Joe Greene
  Project: Program 1 (evens check)
  Notes:
    - This program represents one way I would solve this program
    - I listed all the steps I took in order (based off of my psuedo-code)
*/

//Required libraries
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  //1. Declarations
  ifstream infile;
  const int MAX_EVENS = 100;
  bool all_even = true;
  int evens_list[MAX_EVENS];
  int evens_count = 0;
  int num;

  //2. Open file
  infile.open("num_list.txt");

  //3. If file was successfully opened
  if(infile.is_open())
  {
    //3a. While num can be set by the file's data AND evens_count is less than MAX_EVENS
    while(infile >> num && evens_count <= MAX_EVENS)
    {
      //3ai. If num mod 2 is zero, add it to evens_list and increment evens_count.
      if(num % 2 == 0)
      {
        evens_list[evens_count] = num;
        evens_count++;
      }
      //3ai. Else, set all_even to false.
      else
      {
        all_even = false;
      }
    }

    //3b. Close the file
    infile.close();

    //3c. If evens_count is zero, print that there were no even numbers in the list.
    if(evens_count == 0)
    {
      cout << "No even numbers were found in the file.\n";
    }
    //3c. Else, print every element in evens_list.
    else
    {
      cout << "EVENS LIST:\n";
      for(int i = 0; i < evens_count; ++i)
      {
        cout << "Num " << evens_list[i] << endl;
      }
      
      //If all_even is true, print that all numbers grabbed from the text document were even.
      if(all_even)
      {
        cout << "All integers from the file are even.\n";
      }
    }
  }
  //4. If the file could not be opened, print that "num_list.txt" could not be opened/read.
  else
  {
    cout << "Error when opening the file!\n";
  }

  //Lazy way
  system("pause");

  return 0;
}