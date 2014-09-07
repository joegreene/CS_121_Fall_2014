/*
  Name: Joe Greene
  Program: Temperature Converter (Celsius/Fahrenheit)
  Purpose: To convert temperatures given by the user (either Celsius or Fahrenheit). 
           The program prints both the Celsius and Fahrenheit in the end.
  Notes: 
    - This program uses basic console IO (no error-checking)
    - This program isn't the most efficient way to make it, but still works and 
      is easier to explain.
    - The program assumes the user has inputted all required values correctly.
    - No custom functions are used in this version.
    - For more explanation on cin.ignore(1000, '\n'), check out this 
      link: http://www.cplusplus.com/reference/istream/istream/ignore/
*/

#include <iostream>  //for cout/cin
#include <string>    //to use the string object

using namespace std; //for cout/cin (lets us avoid typing "std::cout" and "std::cin")

int main()
{
  double temp_given = 0,     //variable for temperature given by user
  conv_temp = 0;             //temporary variable to convert temp_given to

  string temp_type = "";     //variable for determining temperature type

  cout << "Is your temperature in Celsius or Fahrenheit? ";
  getline(cin, temp_type);   //assuming the user inputs "Celsius" or "Fahrenheit"

  cout << "Enter in your temperature: ";
  cin >> temp_given;         //grabbing the temperature from the user

  cin.ignore(1000, '\n');    //skips to the new line and ignores 1000 characters of input (if it exists)

  if(temp_type == "Celsius") //if we were given a celsius temperature
  {
    cout << "Celsius: " << temp_given << endl;
    conv_temp = temp_given * 1.8 + 32;  //convert celsius to fahrenheit
    cout << "Fahrenheit: " << conv_temp << endl;
  }
  else  //assumably fahrenheit to celsius conversion
  {
    conv_temp = (temp_given - 32) / 1.8;  //convert fahrenheit to celsius
    cout << "Celsius: " << conv_temp << endl;
    cout << "Fahrenheit: " << temp_given << endl;
  }

  //Custom "system("pause");" code
  cout << "Press ENTER to exit this program.";
  cin.ignore(1000, '\n');   //same as before

  return 0;
}