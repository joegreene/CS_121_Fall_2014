# Week 13 Notes - Friday

## Sections
- [Intro](#intro)
  - [Notes](#notes)
    - [Inheritance](#inheritance)
    - [Polymorphism](#polymorphism)
    - [`virtual` Keyword](#virtual-keyword)
    
### Intro
Below are the notes from the Friday (11/21) SI session.

#### Notes
We worked on this week's worksheet and talked about Friday's lecture. We reviewed a bit on 
polymorphism, inheritance, and the virtual keyword.

Topics discussed during the session:
- Inheritance
- Polymorphism
- `virtual` Keyword

##### Inheritance
Before getting into this, it might be good to recap on what the difference between public, private, and protected 
are (which are called access modifiers). [This page](http://www.tutorialspoint.com/cplusplus/cpp_class_access_modifiers.htm) 
explains them well (along with some code examples).

Inheritance allows a new (child) class to be based off of another existing (base) class. The child class 
inherits all member variables and methods of the base class, excluding the base class's constructor, 
deconstructor, overloaded operators, and friends.

When creating instances of a child class, both its parent and own constructors are called (in that order). 
When the child instance is destroyed the child class's deconstructor is called first, then the parent's 
deconstructor.

For accessibility information (i.e. if inherited variables are public, private, or protected) check 
out the chart [here](http://www.tutorialspoint.com/cplusplus/cpp_inheritance.htm) (under "Access Control 
and Inheritance").

If the chart in the given link is confusing, take for instance the following code excerpt:
```C++
  class Student 
  {
    public:
      Student(string n, string id);
      void print();
    protected:
      string name;
      string ownID;
  };
  
  class GradStudent : public Student
  {
    public:
      GradStudent(string n, string id, string prevdeg);
    protected:
      string prevDegree;
  };
```

In the above example, we say `GradStudent` is a `Student` (or you can say it's a type of Student). GradStudent 
will inherit a public method `print()` and protected member variables `name` and `ownID`.

If we were to say instead:
```C++
  class GradStudent : protected 
```

Then the inherited `print()` method and the `name` and `ownID` protected member variables will all be protected (inside 
of GradStudent).

##### Polymorphism and the `virtual` Keyword
When learning about polymorphism, I used [this page](http://www.tutorialspoint.com/cplusplus/cpp_polymorphism.htm) to help me understand 
what it is and how to implement it. This is mainly if the PowerPoint notes were difficult to comprehend.

One way to remember what polymorphism is about is by thinking about what the word means. As the word means "taking many forms", the idea 
in computer science is to have it so that one method may take different meanings. More described below.

To implement polymorphism use the `virtual` keyword. This tells the compiler that the function may (or may not) be overridden in a child class 
later on. An example of this is in the Chapter 15 PowerPoint notes, pages 8 and 9. Note that page 8 shows a `static-bind` and page 9 shows a 
`dynamic-bind`. A dynamic-bind requires the keyword `virtual`.

Alongside what the notes talk about this (Chapter 15, pg15), [this](http://www.tutorialspoint.com/cplusplus/cpp_interfaces.htm) can help as well.

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>