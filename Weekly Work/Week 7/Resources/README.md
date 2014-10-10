# Week 7 Solutions

## Sections
- [Intro](#intro)
- [Worksheet](#worksheet)
  - [Questions](#questions)
    - [Syntax Practice](#syntax-practice)
    - [Concept Questions](#concept-questions)
    
### Intro
This page hosts the solutions to the questions in the worksheet for this week.

### Worksheet
Above with file name "CS 121 Week 7 Worksheet.docx".

I made a small bit of revisions in the notes section. Other than a few grammar changes, I added the 
following note under the "Notes/Definitions" section:
```
  •	Arguments are what sent into the function (i.e. what is used in the function call), 
  whereas parameters are what the function is defined with (i.e. in the function header).
```

Make sure you remember this! It'll be important now and in later courses, and the two terms are easily mixed-up 
all the time.

#### Questions
Below are the solutions for this week's worksheet.

##### Syntax Practice
1. Function Prototype Problems
1) Prototype:
```C++
  bool init_student(int& id, double& grade, string& name);
```

Information:
```
  Return type: Boolean
  Name/Identifier: init_student
  in-param (by-value): None
  out-param (by-reference): id, grade, name
  Purpose: To initialize a student. Return true if initialized successfully (and false if not)
```

2) Prototype:
```C++
  double conv_temp(double temp, bool is_cels = true);
```

Information:
```
  Return type: double
  Name/Identifier: conv_temp
  in-param (by-value): temp, is_cels
  out-param (by-reference): None
  Purpose: To convert (and return) a converted temperature. A celsius temperature is assumed on default.
```

3) Prototype:
```C++
  void output_char(char ch, int amount = 20, ostream& out_source = cout);
```

Information:
```
  Return type: void (nothing)
  Name/Identifier: output_char
  in-param (by-value): ch, amount
  out-param (by-reference): out_source
  Purpose: To output a character some amount of times to an output source of some kind (console or file).
           On default, we have the amount of character outputted as 20, and the default output 
           destination/source as the console (cout).
```

2. Possible code:
```C++
  void print_sq(int num); //either define here or below
  int main()
  {
    print_sq(12); //function call
    return 0;
  }
  
  void print_sq(int num)
  {
    cout << (num*num) << endl; //print square here
  }
```

3. Swap function:
```C++
  void swap_doubles(double& first, double& second)
  {
    //Algorithm: Set temp to first, change first to second, change second to temp
    double temp = first;
    first = second;
    second = temp;
  }
  int main()
  {
    double first_num = 10, second_num = 44;
    
    swap_doubles(first_num, second_num);
    
    //Optional cout below
    cout << "First num: " << first_num << "\nSecond num: " << second_num << "\n";
    
    return 0;
  }
```

4. Fixed code (total of 14 amount of errors (15 if including each curly brace):
```C++
  #include <iostream> //error one with "iostrea"

	using namespace std; //error two with "using"

	const double TAX_RATE = .81;
	double get_cost(double); //error three in identifier

	int main()
	{
	  double bp = 12.00; //$12.00 is the base price before tax
	  double actual_cost = get_cost(bp);

	  cout << "Before tax: $" << bp << endl;                     //error four in "end"
	  cout << "Tax rate: "  << (TAX_RATE*100) << "%" << endl;    //errors five (<< between string literal and TAX_RATE), six with output issue
                                                               //should print a percentage, not dollars) and seven (with "end")
	  cout <<  "After applying tax: $"  << actual_cost << endl;  //errors eight (<< between cout and string literal), nine (string literal 
                                                               //requires ending quotation"), ten (underscore in actual_cost), and eleven (in "end")
	  cout << "Same thing as before: $" << get_cost(bp) << endl;

	  system("pause"); //error twelve (requires quotation marks on "pause")

	  return 0;
	}

	double get_cost(double base) //error thirteen (need identifier "base" in parameter list) and fourteen (curly braces are required)
  {
	  return (base + (TAX_RATE * base));
  }
```

The output should be:
```
  Before tax: $12
  Tax rate: 81%
  After applying tax: $21.72
  Same thing as before: $21.72
  Press any key to continue...
```

##### Concept Questions
1. Global variables produce confusion if they are not labelled constant. If they are not constant, they could be accessed by any 
function at any time, change its value, thus making it difficult to keep track of. You can check out [this](http://stackoverflow.com/questions/484635/are-global-variables-bad) 
post for more information on this.

2. Pass by value when you have small variables/values (primitive types) that you wish to not change when used in a function argument. This would include using a custom 
print function (e.g. `void print_num(int num)`) or something along those lines. Pass by reference when you're dealing with bigger variables that you want to send into 
as a function argument or want to return more than one variable in a function (like the swap function we had in class and on this worksheet). 

__NOTE__: If you want to send a value that's considered big but don't want to change its contents in a function, call it by const reference. Examples:
```C++
  void print_vect(const vector<string>& str_list);
  int ret_sum(const int num_list[], 
```

__NOTE 2__: You cannot (and it would not make sense to) pass a literal by reference. For instance, the following is syntactically incorrect:
```C++
  bool get_fact(int n, int& fact); //returns true (and the factorial, where n! = fact, by using fact) 
                                   //if the factorial is computable
  
  int main()
  {
    //...code...
    bool got_fact = get_fact(5); //invalid
    //...code...
  }
```

You cannot edit "5" above to its factorial. You have to use a variable, such as `int n` to compute that.

3. Output (note that the initialization, `static int num = 0;` is only called __ONCE__):
```C++
  Value of num: 1
  Value of num: 2
  Value of num: 3
  Value of num: 4
  Value of num: 5
  Press any key to continue...
```

The above might be difficult to understand. Best thing to do is fiddle around with the code and keep in mind that 
`static` means the variable will not lose its value when the program leaves the function. A static variable's 
initialization is only called once.

4. Although I hardly ever use static variables, they still can be handy at times. Below are a few instances where 
you may want to consider making a static variable:
- Debugging (to see how many times a function was accessed)
- Avoiding redeclaring variables in functions that should only pertain to one function (e.g. `const static int months[] = {0,1,2,3,4,5,6,7,8,9,10,11}` 
  to have a list of month indices in a function called `get_month_index()`).
- Having unique IDs for class objects (these may or may not be discussed later in lecture/lab, but if anyone asks I can either explain this or 
you can visit [here](http://www.learncpp.com/cpp-tutorial/811-static-member-variables/))

5. Default parameters provide a quick and easy way to assume what a parameter might equal when the function is called. This allows for less 
typing, given that we are okay with what the function has on default.

Two scenarios:
- Making a print function print something to a source. The source, on default, can be the console (cout).
- The C++-standard functions `getline`, `ignore`, and  all have default parameters in them. `getline` has a default parameter for its third parameter
(the delimiter), otherwise `'\n'`. `ignore` has default parameters

More information on default parameters can be found in your notes, or on an online resource such as [here](http://www.tutorialspoint.com/cplusplus/cpp_functions.htm) 
(you can ignore the pointer stuff it talks about).

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>