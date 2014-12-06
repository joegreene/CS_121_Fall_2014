# Week 15 Notes - Wednesday

## Sections
- [Intro](#intro)
  - [Notes](#notes)
    - [Polymorphism Recap](#polymorphism-recap)
    - [Override vs. Overload](#override-vs-overload)
    
### Intro
Below are the notes from the Wednesday (12/3) SI session.

#### Notes
We worked on this week's worksheet and talked about Monday's lecture. We reviewed operator overloading and 
the friend keyword.

Topics discussed during the session:
- Polymorphism Recap
- Override vs. Overload

##### Polymorphism Recap
We pretty much referred to the power point notes for this since it does it well, so just head over to 
its example. It shows a GradStudent object being passed into a function that takes a Student object as a 
parameter. The general idea is that the keyword 'virtual' helps the program know which method to use: 
`getInfo` in Student, or the overriding `getInfo` in GradStudent.

##### Override vs. Overload
Overriding refers to replacing inherited functions (in children classes) from base classes, whereas overloading 
refers to having multiple functions of the same name.

Example of overriding:
```C++
  class Pet
  {
    public:
      void makeNoise(){ cout << "Generic pet noise!"; };
  };
  
  class Cat : public Pet
  {
    public:
      void makeNoise(){ cout << "Meow!"; }
  };
```

In the above, `makeNoise()` in `Cat` is overriding `makeNoise()` in `Pet`.

Example of overloading:
```C++
  void subtract(int a, int b);
  void subtract(int a, int b, int c);
```

`subtract` is an overloaded function, where it can be called two different ways. For example:
```C++
  subtract(1,2,3);
  subtract(1,2);
```

Note that providing parameters for a constructor is considered overloading the constructor, like so:
```C++
  class Employee
  {
    public:
      Employee(string n, double s);  //overloaded constructor 
                                     //(default is Employee() which is here on default)
  };
```

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>