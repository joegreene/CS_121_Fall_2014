# Week 16 Notes - Friday

## Sections
- [Intro](#intro)
  - [Notes](#notes)
    - [More on Recursion](#more-on-recursion)
    - [Arrow Operator](#arrow-operator)
    - [Private Class Functions](#private-class-functions)
    
### Intro
Below are the notes from the Friday (12/12) SI session.

#### Notes
We talked a bit more in-depth with recursion, the arrow operator, and a bit about private class functions.

Topics discussed during the session:
- More on Recursion
- Arrow Operator
- Private Class Functions

##### More on Recursion
Continuing on from last session, we took a visual approach to understanding how to create recursive solutions 
to problems).

<TBD>; For now check [this](http://web.eecs.utk.edu/~cs102/lectures/recursion.html) out.

##### Arrow Operator
You'll be using this a lot in CS 131, so if you don't know it now it's best to look at it from here first (or 
from some tutorial site.

The arrow operator `->` is a shorthand way of saying you're pointing to a member of a class pointer.

I will be using the following class in the examples below:
```C++
  class Car {
    public:
      Car();
      printDetails();
      string * strptr;
  };
```

Firstly, let's start with creating a `Car` pointer and dynamically create (since we're making the memory on runtime, 
not compile time) a `Car` object with that pointer:
```C++
  //Assume the constructor here initializes
  Car * cptr = new Car();
```

If we wanted to use `printDetails`, we would first have to __dereference__ `cptr` (since `cptr` is a pointer which 
"points to a memory location that has a `Car` in it") like so:
```C++
  (*cptr).printDetails();
```

The reason we require parenthesis is because, by operator precedence (the order in which the compiler works on 
operators, like [PEMDAS](http://www.mathsisfun.com/operation-order-pemdas.html) in mathematics), the dot operator 
works before the dereference operator.

Now, if we wanted to get the length of `strptr` we would have to type the following:
```C++
  (*(*cptr).strptr).length();
```

As you can probably see, this can get pretty annoying to type out. One way around using parenthesis is by using the 
arrow operator:
```C++
  cptr->printDetails();   //to call "printDetails" method from cptr
  cptr->strptr->length(); //to call cptr's strptr's "length" method
```

Note that the arrow operator is a mix of the characters `-` (dash) and `>` (greater-than), not a single key.

##### Private Class Functions
Just like public class functions, private class functions are functions a class possesses. The only difference here 
is that only the class itself can use them (hence "private"). Like any function they're used to enforce reusability, 
plus they make your code look tidier.

Example Scenario: Assume we want to create a `MovieTheater` class that initializes itself based off of a file name (which 
has various data about movie times, showings, etc.). Assume as well that we do not require keeping the file name when 
we're done loading the data from the file.

One possible blueprint of this class would be the following:
```C++
  class MovieTheater {
    public:
      MovieTheater();
      void initByFile(string fn);
  };
```

This implementation is fine... although it's improbable that we'd want a user of our class to be able to 
call `initByFile` any other time other than the start. This can be achieved by doing the following:
```C++
  class MovieTheater {
    private:
      void initByFile(string fn);
    public:
      MovieTheater(string fn) {
        initByFile(fn);
      }
  };
```

Where we call the function `initByFile` through the constructor. We could've technically moved `initByFile` method into 
the constructor, although the constructor would start to look messy. It would also become harder to edit things inside 
of the constructor if we took that route. Thirdly, if we ever plan on making more constructors then we'd have to retype 
the function out (which is where reusability comes in).

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>