# Week 1 Solutions

## Sections
- [Concept & Syntax Questions](#concept--syntax-questions)
  - [Question 1](#question-1)
  - [Question 2](#question-2)
  - [Question 3](#question-3)
  - [Question 4](#question-4)
    - [Explanation and Notes on Question 4](#explanation-and-notes-on-question-4)
  - [Question 5](#question-5)
  - [Question 6](#question-6)
- [Practice Projects](#practice-projects)


### Concept & Syntax Questions
Below are the concept & syntax solutions from the worksheet.

#### Question 1
Three types are: `for`, `while`, and `do-while`

`for`:
- Pretest loop (conditional check done BEFORE body is ran)
- Done a specific amount of times (usually)
- Good for repeating statements when it's known how many times they should be ran

`while`:
- Pretest loop
- Done an uncertain amount of times usually (0 to infinity; however long the conditional takes to be false)
- Good for when you do not have a specific amount of times you need to loop some code

`do-while`:
- Post-test loop (conditional check done AFTER body is ran)
- Done at least one time (1 to infinity, unless developed otherwise, as shown below)
- Good for user input and menu-driven programming

__BONUS:__ Yes. Examples are types below:

`for` loops (assume `gnum` is an `int` taken from user input that is always greater than or equal to 0):
```C++
  //Initial for loop (for comparison)
  for(int i = 0; i < gnum; ++i)
  {
    //code here
  }
  
  //while replacing for
  int i = 0;
  
  while(i < gnum)
  {
    //code here
    ++i; //update at end
  }
  
  //do-while replacing for
  int i = 0;
  
  do
  {
    if(i < gnum)  //required if gnum is at start (meaning the conditional check is false at the start) 
    {
      //code here
      ++i;        //update at end
    }
  }while(i < gnum);
```

The other replacements can be made by moving around the above examples.

I want to emphasize replacing a `do-while` loop with a `while` loop however:
```C++
  //Initial do-while; grabs an int that's between 0 and 30 without fail-checking
  int num;
  bool valid = false; //this removes the need to have "valid = false;" in the "else"
  
  do
  {
    cout << "Enter a number between 0 and 30: ";
    cin >> num;
    
    if(num >= 0 && num <= 30) //if num is between 0 and 30
    {
      valid = true; //to jump out of the loop
    }
    else
    {
      cout << "Invalid input.\n";
    ]
    
  }while(!valid); //while valid input has not been entered
  
  //while replacing do-while
  bool valid = false;
  
  while(!valid)
  {
    cout << "Enter a number between 0 and 30: ";
    cin >> num;
    
    if(num >= 0 && num <= 30)
    {
      valid = true;
    }
    else
    {
      cout << "Invalid input.\n";
    }
  }
```

Note here that you can easily replace a `do-while` loop with a `while` loop by initializing a variable at the start. This 
pretty much makes the `do-while` unnecessary. You should know how to use them regardless as they're commonly used when doing stuff 
like making menus or user input (as shown above).

#### Question 2
- `if/else if/else` chains can check many data types (provided they support conditional checks) and ranges (of integers).
- `switch` is only for testing a single integral variable's value. It's handy when you're working with a small set of integer-based values.

__BONUS__: 
- `if/else if/else` chains can replace `switch`. You just have to check for single values (e.g. `if(a == 1)` is equivalent to `switch(a){...case 1:`...}).
- `switch` can only replace `if/else if/else` chains when testing integral types. Ranges can be checked, although only by tedious typing or fall-through.

Example of `switch` replacing `if/else if/else` (assume `grade` is an integer and is within 0 to 100):
```C++
  //initial if/else if/else chains
  if(grade >= 0 && grade < 60)       //between 0 and 59
  {
    cout << "You received a F.\n";
  }
  else if(grade >= 60 && grade < 70) //between 60 and 69
  {
    cout << "You received a D.\n";
  }
  else if(grade >= 70 && grade < 80) //between 70 and 79
  {
    cout << "You received a C.\n";
  }
  else if(grade >= 80 && grade < 90) //between 80 and 89
  {
    cout << "You received a B.\n";
  }
  else                               //assuming value is between 90 and 100
  {
    cout << "You received an A.\n";
  }
  
  //switch replacing if/else if/else chain
  switch(grade)
  {
    case 0:
    case 1:
    //...cases 2 through 58
    case 59:
      cout << "You received a F.\n";
      break;
    case 60:
    case 61:
    //...cases 62 through 68
    case 69:
      cout << "You received a D.\n";
      break;
    case 70:
    case 71:
    //...cases 72 through 78
    case 79:
      cout << "You received a C.\n";
      break;
    case 80:
    case 81:
    //...cases 82 through 88
    case 89:
      cout << "You received a B.\n";
      break;
    default: //similar to else in this case
      cout << "You received an A.\n";
  }
```

You can see how it would be annoying to use `switch` statements for ranged checks. They're handy when you 
have to test things like a grade letter (note that the character `A` translates to an integral value, i.e. `case 'A':` equals 
`case 65:` due to the [ASCII table](http://www.ascii-code.com/)).

#### Question 3
Some concepts (not all as there could be more but these are the main ones that come to my mind):
- Arrays
- if/else if/else chains
- Loops (user input, menus, etc.)
- Variables (general)
- Functions (for each action needed in the program, like adding to the list or editing individual players) 

NOTE: #3 was meant to be a collaborative group answer so complete answers may vary.

#### Question 4
Example syntax (can be done multiple ways, although this is most common):
```C++
  srand(time(NULL)); //generate seed for psuedo-random number generation
  
  int rand1 = rand() % 100 + 1;    //1 through 100
  int rand2 = rand() % 17 + 4;     //4 through 20
  int rand3 = rand() % 115 + 1900; //1900 and 2014
  
```

__BONUS__: `#include <cstdlib>` (c-standard library)

##### Explanation and Notes on Question 4
NOTE: using `time(NULL))` in `srand(time(NULL));` requires `#include <time.h>`. 

NOTE 2: `rand()` will return a value between 0 and `RAND_MAX`, in which `RAND_MAX` is some value defined by the standard library.
- In Visual Studio, `RAND_MAX` equals "0x7fff" in hexadecimal, which is "32767" in decimal. More information [here](http://msdn.microsoft.com/en-us/library/2dfe3bzd.aspx).

NOTE 3: Per line, what you mod by is the range, and the added number is the lower limit, i.e.:
```
  int num = rand() % range + starting_number;
```

The range (the number of values in the list) can be found by doing the following:
```
  range = largest_value - starting_value + 1
```

The "+ 1" accounts for including the starting value (think of counting numbers).

To explain how the equation works, let's use a small example (1 to 5) and get to a general equation from there:
```
  The C++ statement for that is: 
    int num = rand() % 5 + 1;
    
  Let's say rand() gives us the value 2344 (we don't really know when compiling however)
  Therefore, our C++ statement becomes:
    int num = 2344 % 5 + 1;
  Evaluating this, we have:
    2344 % 5 = 4 (2344/5 is 468 Remainder 4)
    Add one and we get 5 as our "random" number.
    
  If rand() gave us "4850", then we would have the following:
    int num = 4850 % 5 + 1;
    4850 % 5 = 0
    Add one and we get 1 as our "random" number.
    
  To make it a little more general:
    "rand() % 5" will always give us a value between 0 to 4 (you can say 0 to 5-1 as well)
    If we add one to that, we get 1 to 5 (which is what we need)
    For the next part, it might help to think starting_value = 1, and largest_value = 5
  
  And lastly, to be completely general about it:
    "rand() % range" will always give a value between 0 to range - 1
    If we add the starting value to that, we get starting_value to largest_value (which is what we want)
    Therefore, the C++ statement to generate a random value in C++ is:
      int num = rand() % range + starting_value;
```

It might be tricky to understand at first, and if you have any questions about this don't hesitate to ask me, fellow peers, or the teacher.

For more help with this, check [here](http://www.cplusplus.com/reference/cstdlib/rand/) or [here](http://en.cppreference.com/w/cpp/numeric/random/rand).

#### Question 5
Couple reasons (there are more):
- Readability (so others understand your code; `s` versus `num_students`)
- Easier to type (`num_oranges` versus `number_of_oranges`)
- Size of source file (.cpp or .h), although it's not much of an issue nowadays (less characters in a file means less of a file size)
  - For an example of this: Create an empty text document. Check its file size. Type some words into the file, save, then check the size again.
  
More reasons can be found via Google on sites such as [here](http://www.wellho.net/solutions/general-what-makes-a-good-variable-name.html). It's also good to maintain a consistent (and good) programming 
style.

#### Question 6
Output (in order):
```
  1
  1
  0
  0
  1
  1
```

__BONUS__: No. If you were to remove "using namespace std;" you would require each `cout` and `endl` to be `std::cout` and `std::endl` respectively. That's 
because each belongs to the namespace `std` (standard namespace). Alternatively, if you'd like to avoid having `using namespace std;` and typing `std::` for each, 
use `using std::cout;` and `using std::endl;` (where `using namespace std;` was). There is example usage of this replacement in the references folder.

### Practice Projects
Located under each .cpp file in the Projects folder. I tried my best to put in comments and thorough explanations, but if it's difficult 
to interpret then email me and I'll explain the program.

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>