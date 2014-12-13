# Week 16 Notes - Wednesday

## Sections
- [Intro](#intro)
  - [Notes](#notes)
    - [Recursion](#recursion)
    - [Templates](#templates)
    
### Intro
Below are the notes from the Wednesday (12/10) SI session.

#### Notes
We worked on this week's worksheet mainly, went over the idea of recursion in programming, 
and recapped a bit on templates.

Topics discussed during the session:
- Recursion
- Templates

##### Recursion
TBD; For now check [this](http://web.eecs.utk.edu/~cs102/lectures/recursion.html) out.

##### Templates
Templates are a way to have generalized data types in a class or function, so the class/function 
can work with more types of objects through them without typing special functions for each type.

For instance, let's say you wanted to create an addition function (for whatever reason) that added 
two values of the same type together. An integer example would be:
```C++
  int add(int a, int b) {
    return a + b;
  }
```

If we wanted to have an integer version, a double version, and a string version of this, then we'd 
need three different functions:
```C++
  int add(int a, int b);
  double add(double a, double b);
  string add(string a, string b);
```

If we need more, we'd have to type (linearly) many more. One way around this is by using a template:
```C++
  template<class Gen>
  Gen add(Gen a, Gen b) {
    return a + b;
  }
```

Which allows us to use any one type inside the function, removing the need to retype the function per type 
required.

The `template` part is self-explanatory and the part inside the angled-brackets (`class Gen`) is just a 
generic name. It could be `class T` for all we care, just making sure we plug in `T` instead of `Gen` in 
the function.

Keep in mind that, especially with the above function, the program assumes that all types you put into the function 
support whatever operations you use on the generic type. 

A great example of this is the `vector` class we've worked with. Notice how you can define 
a `vector` to use `string`, `double`, `int`, ... pretty much any type of object you want, like so:
```C++
  vector<string> string_list;
  vector<bool> bool_list;
  vector<char> char_list;
  //etc.
```

The reason it's possible is because the `vector` class uses templates. If you'd like more information 
on this beyond the Power Point, check [this](http://www.tutorialspoint.com/cplusplus/cpp_templates.htm) 
page out.

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>