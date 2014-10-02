/*
  Name: Joe Greene
  Project: Program 2 (Palindrome Algorithm)
  Notes:
    - This program represents one way I would check if a string is a palindrome
    - You only needed to check for isalpha(char), although I made the program 
      a bit better by including digits (by using isalnum()).
      INFO HERE: http://www.cplusplus.com/reference/cctype/isalnum/
    - If you want, you can omit char left and char right and replace the if-check with:
      if(temp2[p] != temp2[temp2.length() - 1 - p])
      {
        is_palindrome = false;
      }

      To make it more efficient. To me it's more legible with characters (and easier to explain), 
      however if you do the above then you'll be able to save a byte per char and four lines of 
      code in total. In this case, the trade-off doesn't matter too much.
*/
//Required libraries
#include <fstream>
#include <iostream>
#include <string>

//Alternative to "using namespace std;"
using std::cout;
using std::cin;
using std::string;
using std::endl;

int main()
{
  //string we plan to use to grab from user
  string temp_str;

  //Grab string info from user
  cout << "Enter a string to see if it is a palindrome: ";
  getline(cin, temp_str);

  //For "scrubbing" all non-alphabetic and non-digit characters from phrase
  string temp2 = temp_str;

  //For each position in the string
  for(int w = 0; w < temp2.length(); ++w)
  {
    //If the current position in the string is not alphabetic and not a digit
    if(!isalnum(temp2[w]))
    {
      //Erase the position; NOTE: Length changes when we erase, which is 
      //what we need for this.
      temp2.erase(w, 1);
    }

    //DEBUG, if in case you don't understand what I mean by "changing length"
    //cout << "Temp2: " << temp2 << "\nLength: " << temp2.length() << endl;
  }

  //Set is_palindrome to true (optimism)
  bool is_palindrome = true;

  //Initialize left and right; We can use right = temp2[temp2.length() - 1]; as well
  char left = temp2[0], right = temp2.back();

  //For half the length of temp2 AND we still have the characteristics of a palindrome
  //Also, start at 1 because we already set up position 0 and back for left and right
  for(int p = 1; p <= temp2.length()/2 && is_palindrome; ++p)
  {
    //Debug code:
    //cout << "left: " << left << "  right: " << right << endl;

    //If left isn't equal to right, we know the string is not a palindrome
    if(left != right)
    {
      is_palindrome = false;
    }
    //Else, we still have a palindrome and now move left/right inwards
    else
    {
      //Move to the pth position
      left = temp2[p];

      //Move to the back (length - 1) minus pth position 
      right = temp2[temp2.length() - 1 - p];

      //Debug; To understand the position shifts
      //cout << "p: " << p << "\nBack index: " << temp2.length() - 1 - p << endl;
    }
  }

  //Funky, but "efficient" way to print
  cout << "Phrase: \"" << temp_str << "\" is ";
  if(!is_palindrome)
  {
    cout << "not ";
  }
  cout << "a palindrome" << endl;

  //End prompt; 1000 and '\n' to ignore either 1000 char or until ENTER was pressed.
  cout << "Press ENTER to exit program. ";
  cin.ignore(1000, '\n');
  
  return 0;
}