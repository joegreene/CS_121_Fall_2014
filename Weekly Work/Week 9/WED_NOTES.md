# Week 9 Notes - Wednesday

## Sections
- [Intro](#intro)
  - [Notes](#notes)
    - [Order of Default Parameters](#order-of-default-parameters)
    - [Different Types of Constructors](#different-types-of-constructors)
  
### Intro
Below are the notes from the Wednesday (10/22) SI session.

#### Notes
We worked on both the worksheet and some questions peers had about the project due this Friday (the pizza project).

Topics discussed during the session:
- Order of Default Parameters
- Different Types of Constructors

##### Order of Default Parameters
A peer during the SI session asked if something similar to the following was valid syntax (for a function heading):
```C++
  void print_char(char ch = 'c', int num);
```

Simply put: The above is __invalid__ syntax. The reason for this is because, if we tried to make the following function call:
```C++
  print_char(50);
```

The compiler will be confused. This is because of the following:
1. The compiler expects you to input a character in the first position (which makes the call bad to begin with)
2. If we plug in  

The valid way to making the above function (and any function with default parameters) is to have __default parameters in the 
back__ and __parameters that require input towards the front__. This means the above will need to be rewritten as:
```C++
  print_char(int num, char ch = 'c'); //valid
```

The same goes for parameters with consecutively identical data types:
```C++
  string concat_str1(string s1 = "bad", string s2, string s3 = "three");          //invalid
  
  string concat_str2(string s1 = "bad", string s2, string s3);                    //invalid
  
  string concat_str3(string s1, string s2 = "second", string s3 = "three");       //valid
  
  string concat_str4(string s1, string s2, string s3 = "three");                  //valid
  
  string concat_str4(string s1 = "hello", string s2 = " world", string s3 = "!"); //valid
```

##### Different Types of Constructors
There are three different types of constructors: __Default__, __Overloaded__, and __Copy__.

The __default constructor__ is the default constructor (no duh) that classes and structures work with. 
They have no parameter listing whatsoever. For instance, with the `FCylinder` class in this week's worksheet, 
the default constructor looks as follows (located in the header file):
```C++
  FCylinder();
```

The __default constructor__ is called automatically when you declare an object of a class or structure. Example 
syntax of this is:
```C++
  FCylinder first_cyl;    //no arguments passed through (implicit call to default constructor)
  FCylinder first_cyl2(); //same thing as the first line (explicit call to default constructor)
```

Next up are __overloaded constructors__. Just like [overloading functions](http://www.cplusplus.com/doc/tutorial/functions2/), 
an overloaded constructor changes the amount of parameters there are in the constructor. For instance, we have the 
following method prototype for the overloaded constructor in FCylinder:
```C++
  FCylinder(double r, double h); //I named these 'r' and 'h' to hint what the arguments should be
```

We're overloading it by changing the amount of parameters (from the default's zero parameters to the above parameter count of two).

__NOTE__: We can also have default parameters in the constructor. For instance:
```C++
  FCylinder(double r = 1, double h = 1);
```

Lastly (but definitely not least) is the __copy constructor__. This allows us to, on declaration, copy the member variables (or whatever 
we desire to write) from one object to another. For instance, the copy constructor from the worksheet:
```C++
  FCylinder(const FCylinder& fc);
```

Allows us to use one FCylinder to define another. Looking at its implementation:
```C++
  FCylinder::FCylinder(const FCylinder& fc)
  {
    radius = fc.radius;
    height = fc.height;
  }
```

We're able to assign the radius and height of the FCylinder passed through the constructor (that is, `fc`) to the one we're currently trying to 
declare (and initialize). One weird part about the above might be that we were able to call `fc.radius` and `fc.height` directly, despite them 
being `private`. In this case we're allowed to call the other FCylinder's private member variables with the dot operator because we're 
still working within the FCylinder class (noted by `FCylinder::`).

An example from the worksheet for declaring a FCylinder object by using the copy constructor (under `main.cpp`):
```C++
  FCylinder third_cyl(first_cyl); //calls copy constructor inside of FCylinder.h, which is 
                                  //implemented inside of FCylinder.cpp
```

The funkiest part about doing all this is that you're working with multiple files. It really just takes practice. Best thing to do is try either 
retyping the FCylinder class, understanding each component, and (of course) read the PowerPoint notes and your book. Online sources and my 
worksheet notes/questions are here to help as well, plus you can always email me or Professor Anderson in case you have any questions.

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>