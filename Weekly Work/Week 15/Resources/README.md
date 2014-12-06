# Week 15 Solutions

## Sections
- [Intro](#intro)
- [Worksheet](#worksheet)
  - [Questions](#questions)
    - [Problems](#problems)
    
### Intro
This page hosts the solutions to the questions for this week's worksheet. 

The worksheet itself is located in its usual place (in the file listing above).

__NOTE__: I made quite a bit of errors in the printed version of this worksheet 
(specifically on question three) and I apologize for that. The uploaded document 
has a revised version of everything, so it's best to refer to the uploaded document 
instead.

### Worksheet
Below is the worksheet solutions for this week.

#### Questions
Grab the questions from the worksheet document.

##### Problems
1) Output:
```
  7
  11
  5
  6
```

First line: Dereferencing the second position of `vals`

Second line: Dereferencing the third position of `vals`

Third line: Dereferencing the first position of `vals` then adding one

Fourth line: Dereferencing the first position of `vals` then adding two
(operator precedence dictates `*` before `+`)

2) All lines :
```C++
  //Given info
  char * list;
  
  //initialize `list`, then...
  char * otherptr = list;
  
  //Four ways are below
  cout << list[3]       << " "     
       << *(list+3)     << " "
       << otherptr[3]   << " "
       << *(otherptr+3) << endl;
```

3) Output:
```
-1
1
0
y
t
3 3 4
```

4) First line compares two addresses, the second compares dereferenced addresses (i.e. the 
variables located at each address).

5) One code example (I didn't expect anyone to type out every bit of the program, just 
crucial parts for general understanding):
```C++
  //This is Employee.h
  #include <iostream>
  #include <string>
  #include <cstring>
  
  using namespace std;
  
  //Employee Class
  class Employee
  {
    public:
      Employee(string n, double s)
      {
        //First make a cstring equal to the length of the input string, 
        //plus one for the NULL character the cstring requires
        name = new char [n.length()+1];
        
        //Next, copy the input string to name; strcpy makes a deep copy.
        //Alternatively, use strncpy(name, n);
        strcpy(name, n.c_str());
        
        //Lastly, set salary equal to s
        salary = s;
      }
      ~Employee()
      {
        //Dealing with dynamic memory, so delete name when done with it
        delete name;
      }
      void printSelf()
      {
        cout << "Employee Name: ";
        
        //Unfortunately, with c-string you can't get past this
        for (int i = 0; i < name_length; ++i)
        {
          cout << name[i];
        }
        cout << endl;
        
        cout << "Employee Salary: " << salary << endl;
      }
    private:
      char * name;
      int name_length; //for 
      double salary;
  };
```

Usage in `main`:
```C++
  //This is `main_program.cpp`
  #include "Employee.h"

  int main()
  {
    string name;
    double salary;
    
    getline(cin, name);
    cin >> salary;
    cin.ignore(); //call this since ignore does not skip '\n'
    
    //Create new employee
    Employee emp(name,s);
    emp.printSelf();
    
    return 0;
  }
```

__NOTE__: On default, `getline` skips `'\n'`. However, since `cin >> ...` does not then 
any call for user input will try to get a `'\n'` as its input. To fix this, use `ignore` 
to skip the leftover character `'\n'`.

__NOTE 2__: Instead of calling `.c_str()`, you can call `strncpy(name, n);` which does 
exactly the same, minus the `.c_str()` call. Check [here](http://www.cplusplus.com/reference/string/string/c_str/)
for more info.

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>