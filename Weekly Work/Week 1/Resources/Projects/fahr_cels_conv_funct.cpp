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
    - Custom functions are used in this program.
    - For more explanation on cin.ignore(1000, '\n'), check out this 
      link: http://www.cplusplus.com/reference/istream/istream/ignore/
*/

#include <iostream>  //for cout/cin
#include <string>    //to use the string object

using namespace std; //for cout/cin (lets us avoid typing "std::cout" and "std::cin")

//Function prototypes
double fahr_to_cels(double fahr);           //Function to convert fahrenheit to celsius; returns celsius
double cels_to_fahr(double cels);           //Function to convert celsius to fahrenheit; returns fahrenheit
void print_temp(double cels, double fahr);  //Function to print temperatures; returns nothing (void)
void pause_program();                       //Custom "pause" function; returns nothing (void)

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
    conv_temp = cels_to_fahr(temp_given);  //convert celsius to fahrenheit
    print_temp(temp_given, conv_temp);     //left parameter is celsius, right is fahrenheit
  }
  else  //assumably fahrenheit to celsius conversion
  {
    conv_temp = fahr_to_cels(temp_given);  //convert fahrenheit to celsius
    print_temp(conv_temp, temp_given);     //left parameter is celsius, right is fahrenheit
  }

  //Pause program at end using custom function
  pause_program();

  return 0;
}

//Function to convert fahrenheit to celsius; returns celsius
double fahr_to_cels(double fahr)
{
  return (fahr - 32) / 1.8;
}

//Function to convert celsius to fahrenheit; returns fahrenheit
double cels_to_fahr(double cels)
{
  return (cels * 1.8) + 32;
}

//Function to print temperature; returns nothing (void)
void print_temp(double cels, double fahr)
{
  cout << "Celsius: " << cels << endl << "Fahrenheit: " << fahr << endl;
}

//Custom "system("pause");" code
void pause_program()
{
  cout << "Press ENTER to exit this program.";
  cin.ignore(1000, '\n');   //same as before
}