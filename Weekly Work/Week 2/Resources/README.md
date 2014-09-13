# Week 2 Solutions

## Sections
- [Concept & Syntax Questions](#concept--syntax-questions)
  - [Question 1](#question-1)
  - [Question 2](#question-2)
  - [Question 3](#question-3)
  - [Question 4](#question-4)
  - [Question 5](#question-5)
  - [Question 6](#question-6)
  - [Question 7](#question-7)
- [Practice Projects](#practice-projects)


### Concept & Syntax Questions
Below are the concept & syntax solutions from Week 2's (day two's) worksheet.

#### Question 1
Declaration: To create a variable (not assign a value)

ex) 
```C++
  int var;      //declaring an integer called var
  double PI;    //declaring a double called PI
  string name;  //declaring a string called name
```

__NOTE__: "var", "PI", and "name" are each called the __identifiers__ of the variables they link with. Identifiers help 
programmers know what variables they are working with.

Initialization: To assign a variable a value

ex)
```C++
  int var = 12;                //declaring an integer called var and initializing it with the value 12
  const double PI = 3.141592;  //declaring a constant double called PI
  name = "Joe";                //initializing a string called name and assigning it the value "Joe"
  cin >> var;                  //another way of initializing a variable; assigning the input stream's value to var
```

__Is it okay to use a variable that's initialized but not declared?__: No, because the program does not know what datatype it is 
working with.

__Is it okay to use a variable that's declared but not initialized?__: No, because we never assigned a value to the variable. Although on 
default C++ assigns values to some variables when they are declared, these are garbage values (e.g. -814512378) that shouldn't be 
worked with.

#### Question 2
Nothing will print out. The else at the bottom is attached to the the closest "if" it finds (in this case, it is the one under the top "if").

The "true" format of the code is as follows:
```C++
  if(a==3)
  {
    if(a == 4)
    {
      cout << "Your number is either 3 or 4";
    }
    else
    {
      cout << "Your number is not 3";
    }
  }
```

The lesson to be learned by this exercise is: 
```
  To make it easier on yourself and others reading your code, always include curly braces with if/else if/else.
```

__NOTE__: This issue is known as the "dangling else" problem, where the compiler does not know which "if" to attach the "else" 
statement to (otherwise, it's ambiguous to the compiler). More information on this is [here](http://www.mathcs.emory.edu/~cheung/Courses/561/Syllabus/2-C/dangling-else.html). Look at the 
part where it says "Java, C and C++ have chosen to resolve the Dangling-Else ambiguity uses the following rule".

#### Question 3
An escape sequence/character is a character that performs a unique action.

Three examples:
```
  '\n': End line escape character, which makes the cursor move to a new line (equivalent to pressing ENTER/RETURN)
  '\t': Tab escape character, which prints a tab (equivalent of pressing the TAB key on the keyboard)
  '\a': Alarm escape character, which makes the computer beep (not used much, but fun to use)
```

When to use the above (below are just a few reasons):
```
  '\n': For printing to new line and as a delimiter, e.g. "cin.ignore(1000, '\n');"
  '\t': For formatting on the console or as a delimiter (if you plan to split data somewhere using the TAB key)
  '\a': For notifying when a certain event occurred (e.g. beep when an if-statement was reached)
```

__NOTE__: Remember that the term "delimiter" pretty much means "mark-off point". For example when looking at the following sentence:
```
  The quick brown fox jumped over the moon.
```

Using space, or ' ', is a delimiter. It lets the reader where each word starts and ends. Also, '.' is a delimiter (it tells the user where the end 
of the sentence is).

__TIP__: Normally, spaces, endlines (`\n`), `$`, tabs (`\t`), and `|` (pipe key, and `SHIFT + \` are used as delimiters when working with input data (in files and console input).

#### Question 4
Output:
```
  4
  2
  4
  8
```

__BONUS__: Each indicates the byte-size of each datatype, and it represents the amount of space in RAM each datatype takes (also, the total amount of values each type can 
be in RAM).

__NOTE__: I specifically asked about the output in Visual Studio because different compilers may or may not have different standards on each type's byte-size. For a chart 
on the byte-sizes, check [this](http://msdn.microsoft.com/en-us/library/cc953fe1%28v=vs.100%29.aspx) and [this](http://msdn.microsoft.com/en-us/library/s3f49ktz%28v=vs.100%29.aspx) out.

A last note regarding byte-sizes:
```
  Let's say we have a 1-byte datatype. From this information, we know the following:
    - Each byte is 8 bits long
    - Each bit is a 0 or 1 value, meaning there are two possible values for each bit
    - Using a bit of algebra, we then have:
        2^1 * 2^1 * 2^1 * 2^1 * 2^1 * 2^1 * 2^1 * 2^1 = 2^8 = number of possible combinations of 0's and 1's we can make in a byte
  
  Therefore, there are 2^8 number of values that reside in a single byte of data (256 unique values).
  
  If we take this to something like an unsigned integer (in C++):
    - unsigned integers are 4 bytes, or 4 bytes * 8 bits per byte = 32 bits in total
    - Using the same algebra as before:
      2 * 2 * 2 * ... * 2 = 2^32 total unique values in 4 bytes of data.
  
  The data range for an unsigned integer is 0 to 2^32 - 1. We subtract 1 to account for using 0 as well.
  
  For (signed) integers it's a bit funkier, but nonetheless the same method:
    - 4 bytes, meaning 2^32 unique values
    - The data range for a (signed) integer is:
      -2^31 to 2^31 - 1 (we take one bit for the sign, 32 -> 31, and subtract one to account for 0)
    The above is called two's compliment, noted about here: http://www.cs.uwm.edu/~cs151/Bacon/Lecture/HTML/ch03s09.html
```

__TRIVIA__: Booleans (even though they are only true/false) are one byte because one byte is the smallest piece of data RAM can work with.

#### Question 5
For use when writing identifiers, examples are below:
```C++
  int thisIsCamelCase;  //writing an identifier using camel case
  bool under_scores;    //writing an identifier using underscores
```

Neither is better than the other, and is solely preferential on the programmer. Just make sure to stick with one, or at least some programming 
style standard, or else your code will look wonky and readers will have trouble understanding what you type.

Here's a page with a little more description on it: http://programmers.stackexchange.com/questions/27264/naming-conventions-camelcase-versus-underscore-case-what-are-your-thoughts-ab

#### Question 6
`num` would be equal to "4". This is due to "integer cut-off". Integer cut-off is, when assigning a decimal/floating point value to an integer variable, the decimal is cut-off.

The output of `cout << (3/4) << endl` would be 0. When dividing integers the result is an integer value. Originally, "3/4" yields 0.25, but because we are not working with floating-point values 
we cut-off the decimal and are left with 0.

__NOTE__: If you want to fix this issue, you can do one of two ways:

1: Assign one value to be floating-point:
```C++
  cout << (3.0/4) << endl;
  cout << (3/4.0) << endl;
```

2: Use `static_cast` to convert the integral-based value to a floating-point value
```C++
  cout << (static_cast<double>(3)/4) << endl;
  cout << (3/static_cast<double>(4)) << endl;
```

All of this ties with type-casting, which means to convert from one datatype to another. 
You can learn more about type-casting either in the powerpoint notes, [here](http://www.cprogramming.com/tutorial/lesson11.html), 
or [here](http://www.cplusplus.com/doc/tutorial/typecasting/).

#### Question 7
The modulus operator (`%`) returns the remainder of two integers (and integers only).

Although it's useful for many reasons, here are just a few for now:
- When working with `rand()` (a question like this popped up in worksheet 1)
- Determining odd/even numbers (e.g. `num%2 == 0` is true when `num` is even)
- Checking to see when the current year is NOT a leap year. We have leap years when the year is divisible by 4, and not a leap year if divisible by 100 and not 400). Examples 
of leap years are 2000 and 1504, and examples of non-leap years are 1900 and 1997.

More information on modulus [here](http://www.cprogramming.com/tutorial/modulus.html) and [here](http://stackoverflow.com/questions/12556946/how-does-the-modulus-operator-work).
Also, more information on that leap-year rule [here](http://www.timeanddate.com/date/leapyear.html).
-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>