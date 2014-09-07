/*
  Name: Joe Greene
  Program: Print Factorial
  Purpose: To print the factorial of a positive integer
  Notes: 
    - This program uses basic console IO (minor error-checking)
    - This program isn't the most efficient way to make it, but still works and 
      is easier to explain.
    - I wouldn't suggest trying n-values over , unless you want to see integer 
      overflow occur.
    - The program assumes the user inputs integers only
    - For more explanation on cin.ignore(1000, '\n'), check out this 
      link: http://www.cplusplus.com/reference/istream/istream/ignore/
*/

#include <iostream>  //for cout/cin
#include <string>    //to use the string object

using namespace std; //for cout/cin (lets us avoid typing "std::cout" and "std::cin")

int main()
{
  int n = 0;  //n-value in "n!"
  
  cout << "Enter an integer to find its factorial: ";
  cin >> n;
  
  if(n >= 0) //if the n-value is greater than or equal to zero
  {
    int fact = 1; //the actual computed factorial value
    
    //Compute the factorial
    for(int i = n; i > 1; --i)
    {
      fact *= i;
    }
    
    cout << n << "! = " << fact << endl;
  }
  else //n-value is negative (error)
  {
    cout << "n-value is negative! Cannot compute factorial.\n";
  }

  //Custom "system("pause");" code
  cout << "Press ENTER to exit this program.";
  cin.ignore(1000, '\n');   //same as before

  return 0;
}