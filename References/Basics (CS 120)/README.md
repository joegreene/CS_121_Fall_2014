# Basics
## Contents
- [Intro](#intro)
- [Topics](#topics)
  - [General Terminology](#general-terminology)
  - [Escape Characters](#escape-characters)
  - [Variables](#variables)
  - [if, else if, else, switch](#if-else-if-else-switch)
  - [Loops](#loops)
  - [Arrays](#arrays)
  - [Functions](#functions)
- [Sources Used](#source-used)

### Intro
This page serves as a refresher on CS 120 content. Note that this does not mean it will 
teach you the material, so if you need to learn the material then it's best to head over 
to a website such as [here](http://www.cplusplus.com/doc/tutorial/) or 
[here](http://www.tutorialspoint.com/cplusplus/).

More may be added on this page if deemed necessary. If there are any errors or issues just let me know.

NOTE: I realize some of you guys might have not worked on functions in CS 120. If you have, however, 
the resource is within the topic list. Otherwise, you may want to head over to a tutorial site for help.

### Topics
Each topic provides common terminology and errors associated per topic.

#### General Terminology
Most is covered in the following topics, but here is a list of general terminology you may hear:
- __Statement__: Individual instructions of a program, e.g. variable declarations and expressions
- __Headers__: Libraries included into the program (e.g. "iostream" in "#include <iostream>")
- __Delimiter__: Sequence of one or more characters to determine a boundary (e.g. '\n' in `cin.ignore(1000, '\n');`)
- __Directory__: A specific folder (e.g. "C:\Users\Administrator\Desktop" leads to the user named Administrator's desktop on a Windows 7 computer)

More will be added if recognized/noted.

#### Escape Characters
Always handy to know by hand. The most commonly used ones are `\n`, `\\`, `\"`, `\'` and `\t`.

Here's a list of them: http://msdn.microsoft.com/en-us/library/6aw8xdf2.aspx

Keep in mind that some are OS-specific (that is, they only work on specific operating systems). I don't remember 
where the list is located for that, but if anyone does know then please let me know so I may add it here.

#### Variables
Variables are a way to store values into memory.

Form of a variable (declaration, initialization, and mixed)
```
  data_type identifier;         //declaration
  identifier = value;           //initialization
  data_type identifier = value; //mix
```

Examples:
```C++
  int something;                //variable declaration
  something = 5;                //variable initialization
  char no = 'a';                //declaration and initialization
  const double TAX_RATE = 8.75; //constant variable with declaration and intialization
```

Commonly used data types:
- `char`: Character (single letter)
- `double`: Double (floating point)
- `float`: Floating-point number
- `int`: Integer (non floating-point)
- `string`: Sequence of characters (NOTE: This is not a primitive type (noted by requiring the header `string`))

Byte-sizes and data ranges vary per standard. For Visual Studio (2013) you can check [here](http://msdn.microsoft.com/en-us/library/cc953fe1.aspx) for more information.

For a better distinction on `double` and `float`, click [here](http://stackoverflow.com/questions/2386772/difference-between-float-and-double).

Terms tied to variables:
- __Constant Variable__: A variable that does not and cannot change throughout the program (declared as `const`)
- __Data type__: The type of variable
- __Declaration__: To create a variable
- __Initialize__: To assign a variable a value
- __Identifier__: Name associated with a variable
- __Primitive Types__: Built-in data types not requiring external libraries

Common errors/issues:
- __Case sensitivity (identifiers)__: Remember that C++ is a case-sensitive programming language (e.g. identifier `ident` is NOT EQUAL to identifier `Ident`)
- __Disregarding naming schemes__: Look at [this page](http://msdn.microsoft.com/en-us/library/565w213d.aspx) for naming schemes (e.g. invalid characters for identifiers)
- __Using an undeclared variable__: Avoid this by keeping track of what variables you need and where you place them
- __Using an uninitialized variable__: Best way to avoid this is to assign a value to a variable as soon as it is declared

For more information regarding variables, best to look at [this page](http://www.tutorialspoint.com/cplusplus/cpp_data_types.htm).

#### if, else if, else, switch
Selection statements, or `if`, `else if`, `else`, and `switch`, help control the flow of a program. Noting that programs work top to bottom, one line at a time, selection 
statements help jump to sections of the program if required.

Structure of a if/else if/else chain:
```
  if(conditional_check)
  {
    //statement list
  }
  else if(conditional_check)
  {
    //statement list
  }
  else
  {
    //statement list
  }
```

If the first conditional check returns true, the program runs the statement list under the first `if` check (and ignores the rest). Same goes for 
the others.

If there is a single statement under the `if` check, then you may omit the curly braces. Same goes for the others.

The lesser-used `switch` statement takes in a single integral value, and (depending on the value). 
```
  switch(integral_type)
  {
    case integral_type_check:
      //statement list
      break_statement
    case another_integral_type_check:
      //statement list
      break statement
    //more cases if necessary
    default case
      //statement list
  }
```

Example of a `switch` statement:
```C++
  int some_int = 42;
  
  switch(some_int)
  {
    case 5:
      std::cout << "some_int is 5";
      break;
    case 4: 
    case 42: //follow through
      std::cout << "some_int is either 4 or 42";
      break;
    default:
      std::cout << "some_int is not 5, 4, or 42";
  }
```

Output:
```
  some_int is either 4 or 42
```

`switch` statements require curly braces. Note also that each line (except the last) requires `break;`, which lets the program know 
to jump out of the switch statement at that time. 

Terms tied to if, else if, else:
- __Conditional Check__: The boolean condition to be checked if 

Common errors/issues:
- Note that all integral values are `true` (e.g. -1, 12, 12714632, -44123, etc.), whereas the value `0` means `false`.

Terms tied to switch statements:
- __Case__: A single-value conditional check (e.g. `if(a == 4)` versus `switch(a) { case 4: ... }`)
- __Falling Through__: When a `break` statement isn't assigned to a case

Common errors/issues:
- __Forgetting `break` Statements__: Unless you intend falling-through, always remember to include your `break` statements.
- __Trying to Use `switch` Statements for Ranged Data__: `switch` statements are for specific values. If you need to work with ranges of values, 
use if/else/else if chains instead.

#### Loops
Iterative statements, or loops, help repeat a statement list. They repeat until their conditional expression returns false (or zero).

There are three types we work with: `for`, `while`, and `do-while`.

Structure of a `for` loop:
```
  for(optional_declaration; conditional_expression; optional_update)
  {
    //statement list
  }
```

Structure of a `while` loop:
```
  while(conditional_expression)
  {
    //statement list
  }
```

Structure of a `do-while` loop:
```
  do
  {
    //statement_list
  }while(conditional_expression);
```

Use a `for` loop when you know how many times to loop, `while` loop when you want to loop zero to an indefinite amount of times, and `do-while` to loop 
at least once to an indefinite amount of times.

NOTE: Curly braces are optional for `for` and `while` loops if you only have one line in them, whereas they are always required in `do-while` loops.

Terms tied to loop structures:
- __Iterate/Iteration__: Each repeat of a loop (e.g. if a while loop runs for four times, there are 4 iterations)
- __Iterator__: A variable used to count the number of iterations in a loop
- __Pre-test__: To perform the conditional check BEFORE running the loop (for and while)
- __Post-test__: To perform the conditional check AFTER running the loop (do-while)

Common errors/issues:
- __Off-by-one Error__: When miscounting looping by one (more info [here](http://en.wikipedia.org/wiki/Off-by-one_error)).

#### Arrays
Arrays help store variables of the same type. The ones we've worked with so far have a static (unchanging/fixed) size. 

Examples of array declarations/initializations:
```
  int list[5];                            //array declaration, uninitialized
  double scores[] = {4.3, 444.5, 11, 9};  //defining an array's size by its contents (4)
  string names[3] = {"hello", "world"};   //array declaration (partial initialization)
```

Example (parallel arrays):
```C++
  const int MAX_MOVIE_COUNT = 5;              //constant variable to handle the number of movies
  int movie_count = 0;                   //counter for number of movies
  std::string movie_titles[MAX_MOVIE_COUNT];  //list of movie titles
  double movie_scores[MAX_MOVIE_COUNT];       //list of movie scores
  bool movie_recommend[MAX_MOVIE_COUNT];      //boolean array to say if a movie is recommended or not
  
  movie_titles[0] = "Spaceballs";        //Assign first movie title, "Spaceballs"
  movie_scores[0] = 100.0;               //Assign first movie score, 100.0 (I like this movie)
  movie_recommend[0] = true;             //Recommend the movie (true)
  movie_count++;                         //Increment counter
  
  //other movie assignments go here, incrementing counter afterwards
  
  //Movie print header
  std::cout << "MOVIE LIST:\n";
  std::cout << "-----------\n";
  
  //Print each movie title
  for(int i = 0; i < movie_count; ++i)
  {
    std::cout << "Movie title: " << movie_titles[i]
      << "\nScore: " << movie_scores[i]
      << "\nRecommended?: ";
    
    if(movie_recommend[i])
    {
      std::cout << "Yes\n";
    }
    else
    {
      std::cout << "No\n";
    }
  }
```

Output:
```
  MOVIE LIST:
  -----------
  Movie title: Spaceballs
  Score: 100
  Recommended?: Yes
  ...
```

Another way to compact the loop is by means of the [conditional operator](http://www.cplusplus.com/forum/articles/14631/):
```C++
  //Print each movie title
  for(int i = 0; i < MAX_MOVIE_COUNT; ++i)
  {
    std::cout << "Movie title: " << movie_titles[i]
      << "\nScore: " << movie_scores[i]
      << "\nRecommended?: " << ((movie_recommend[i]) ? "Yes\n" : "No\n") << "\n";
  }
```

It might look more confusing at first and it's there if you want to use it. Helps best with small statements.

Terms tied to arrays:
- __Index__: Position in the array (started from 0 and goes to n-1, where n is the length of the array)
- __Length__: Size of the array (i.e. number of locations it takes up in RAM)
- __Partially-Initialized Array__: When an array has some of its contents initialized (not all)
- __Parallel Arrays__: Separate arrays that have corresponding index positions

Common errors/issues:
- __Miscounting Indices__: Array index position starts from 0, and ends at n - 1 (where n is the array length). 
Two ways to avoid miscounting indices is to either remember to start from 0, or start from 1 and have your 
array length be n + 1 (where n is the length). The latter is more confusing to other programmers, and is prone to both 
errors (uninitialized index position) and a waste of space (one extra space required).

#### Functions
A way to make your code look a lot nicer, possibly remove chunks of repeated code, and overall enforce 
reusability. 

Components of a function (prototype only):
```
  return_type function_name(parameter_list);
```

Components of a function (with body):
```
  return_type function_name(parameter_list)
  {
    //...
    //statement list
    //...
    //return return_value;
  }
```

Examples:
```C++
  #include <iostream>
  
  void print_int(int stuff); //function prototype
  
  int main()
  {
    print_int(55); //function call
    
    return 0;
  }
  
  void print_int(int stuff) //function 
  {
    std::cout << "Your integer is: " << stuff;
    return; //optional return statement here
  }
```

Output
```
  Your integer is: 55
```

Terms tied to functions:
- __Body of a function__: The statements inside the curly braces of a function
- __Function__: Group of statements that is given a name, and which can be called from some point of the program.
- __Function Call__: Expression that passes arguments (if any exist) to a function to perform an operation
- __Function Declaration__: To tell the compiler about a function name and how to call a function
- __Function Name/Identifier__: Name associated with the function (used for when calling a function)
- __Function Prototypes__: To declare a function without creating its body (must be made later on however)
- __Parameter(s)__: Variable(s) part of the function's declaration
- __Argument(s)__: Variable(s) or values passed when calling a function

Common errors/issues/issues:
- __Creating functions never used__: Delete unnecessary functions whenever needed or possible
- __Forgetting to define the body of a function__: Best thing to do is make it right after the prototype is declared.

#### Sources Used
- http://www.cplusplus.com/doc/tutorial/ 
- http://www.tutorialspoint.com/cplusplus/index.htm 
- http://stackoverflow.com/ 

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>