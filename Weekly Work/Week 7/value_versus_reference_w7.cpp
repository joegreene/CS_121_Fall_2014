#include <iostream>

using namespace std;

void no_change(int value);       //calling function by-value

void new_num(int& value);        //normally you don't want to use by-reference to return one value 
                                 //from a function. Rather, you would change the return type of the 
                                 //function to what you want to return. For now, this only serves as 
                                 //an example.

void swap(int& a, int& b);       //Because it's a great example
bool ret_fact(int& fact, int n); //referring to one of my notes for concept question #2; 
                                 //returns factorial and if it was computed or not 
                                 //(true == computed, false == not computed)

int main()
{
  //num, num2 for first section, fact and n for bool function
  int num, num2, fact = 1, n = 5;
  num = num2 = 3;
  cout << "Before function calls: " << num << " "<< num2 << endl;
  
  no_change(num);
  new_num(num2);

  cout << "After function calls: " << num << " " << num2 << endl;

  //Because it's such a good example
  cout << "Swapped numbers: " << num << " " << num2 << endl;

  if(ret_fact(fact, n))
  {
    cout << n << "! = " << fact << endl;
  }
  else
  {
    cout << "Could not compute factorial using our n-value of: " << n << endl;
  }

  system("pause");
  
  return 0;
}

void no_change(int value)
{
  value+=2;
  cout << "Value in no_change: " << value << endl;
}

void new_num(int& value)
{
  value+=2;
  cout << "Value in new_num: " << value << endl;
}

void swap(int& a, int& b)
{
  int temp = a;
  a = b;
  b = temp;
}

bool ret_fact(int& fact, int n)
{
  if(n >= 0)
  {
    //Compute factorial
    cout << "Computing factorial...\n";
    while(n != 0)
    {
      fact*=n;
      n--;
    }
  }
  else
  {
    //n-value out of boundary for computing factorial
    return false;
  }

  //Factorial was computed (and we never accessed "else" block)
  return true;
}