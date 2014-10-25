# Week 9 Solutions

## Sections
- [Intro](#intro)
- [Worksheet](#worksheet)
  - [Questions](#questions)
    - [Syntax Work](#syntax-work)
    - [Questions (True/False)](#questions-true-false)
    - [Concept Questions](#concept-questions)
    
### Intro
This page hosts the solutions to the questions for this week's worksheet. I've added code for the (complete) 
FCylinder project. If you want to test it out in Visual Studio, make sure (when making the header file) to choose 
"Header File (.h)" or whichever the similar option is when adding a new file to the project solution.

I strongly urge you to run the code in Visual Studio and to study its output. All of it is located in the folder 
`FCylinder Files` in the file listing.

### Worksheet
Below is the worksheet solutions for this week. As usual, click the worksheet .docx in the file listing above 
to download it.

__NOTE__: Make sure to read the headings on instructions on what you're supposed to do in the worksheet. I had 
people ask me what they're supposed to be doing with the code, and (on the top of the second page) I state 
exactly what you're supposed to write in.

#### Questions
##### Syntax Work
For the syntax work portion refer to the completed project version on this page (in the file listing). Once again, 
I strongly urge you to run the code in Visual Studio and to study its output to get a complete grasp on classes.

##### Questions (True/False)
1. True.
2. False. Check [here](http://stackoverflow.com/questions/2750270/c-c-struct-vs-class) and [here](http://stackoverflow.com/questions/4791883/c-struct-vs-class).
3. False. Deconstructors are called on an object when you leave the scope of the object (i.e. when they are "destroyed").
4. False. You can have many different types (for instance, FCylinder has three).
5. False. They require the same name, except deconstructors require a tilde (`~`) in front.
6. False. Constructors are only called on declaration of an object.
7. False. They are normally private.
8. True.
9. False. Accessor/getter methods should only return the variables (never change).
10. True. Think of "mutator" as "mutate" meaning "change" and "set" is self-explanatory.
11. False. Inline functions are created inside of the class.

##### Concept Questions
1) Implementing "getRadius" and "getHeight" as inline :
```C++
  class FCylinder
  {
    private:
      //...code from before...
    public:
      //...code from before...
      double getRadius(){ return radius; }
      double getHeight(){ return height; }
      //...code from before...
  };
```
2) We want to pass an object by reference to have the ability to change its values. If we pass an object by-value 
through a function and call some function in the object to change one of its member variables then we will only affect 
the object in the function (not the one passed as an argument). This is because we've sent a copy.

We call objects by const-reference because classes can be large. As a class (like a struct) is a collection of data (member variables, 
methods, etc.) a class can be large in general (in terms of byte-size). When working with bigger and bigger objects the amount of time 
and resources it would take to pass an object by-value would increase (and we don't want that). To solve this issue, we call using 
a const-reference parameter.

3) I named the class in case of possible conflicts in the future. Since we want to make our code work forever (or at least for a very 
long time before needing to edit it), if we ever include a library into this project that has a class called "Cylinder" already, the 
compiler will not be able to compile your code. This is because it (the compiler) won't know which class to reference (your Cylinder or 
the included library's Cylinder). 

There are ways around this (namely by using namespaces) but for typical code it's a good idea to give your class a prefix of some sort 
to distinguish it (e.g. I used "F" for "FCylinder").

5) Structures are used typically for making small objects, whereas classes are used for more complicated objects. For instance, if I needed 
an object to account for a student's age, id, and gpa (and only those three things) you can use a structure to quickly code the object. If you 
need something more advanced (e.g. a marketing program that takes into account customers, store transactions, etc. or a level with NPCs in a 
video game) then use a class.

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>