# Week 10 Notes - Wednesday

## Sections
- [Intro](#intro)
  - [Notes](#notes)
    - [Defining Classes in Two Files](#defining-classes-in-two-files)
    - [Scope Operator](#scope-operator)
### Intro
Below are the notes from the Wednesday (10/29) SI session.

#### Notes
We worked on last week's worksheet and understanding classes more. We did not go over 
the new worksheet yet, so that will be held over for both Friday and Wednesday next week.

Topics discussed during the session:
- Defining Classes in Two Files
- Scope Operator

##### Defining Classes in Two Files
Because almost all of this information was displayed in last week's worksheet, we 
pretty much just reviewed last week's worksheet to understand how to define 
classes in two files.

We mainly talked about how your file layout should be, which is something along the lines of:
```
  Header: Blueprints of your class (has class function prototypes)
  Source File: Implementation of your class (has function bodies)
  Main (or wherever an instance of your class is): Application of your class (has an instance of your class)
```

So for example, with the FCylinder class in week 9's worksheet:
```
  FCylinder.h: Header file; Blueprints of FCylinder class (prototypes)
  FCylinder.cpp: Source file; Implementation of FCylinder class
  main.cpp: File with main function; Application of FCylinder class (has instances such as first_cyl, second_cyl, etc.)
```

##### Scope Operator
Remember to use the scope operator `::` to define the bodies of methods (class functions) in your 
class's source file, like so:

```
  //FCylinder class's getRadius methods
  double FCylinder::getRadius()
  {
    return radius;
  ]
```

Where the purpose of using `FCylinder::` is to specify what you're implementing. If we did not have `FCylinder::` in there, like so:
```
  double getRadius()
  {
    return radius;
  }
```

We would then be making a function not tied to anything (i.e. the ones we made before getting into classes). We would also have an error, because 
`radius` does not exist as a variable anywhere (except for inside of the class `FCylinder`).

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>