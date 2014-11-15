# Week 12 Notes - Friday

## Sections
- [Intro](#intro)
  - [Notes](#notes)
    - [Objects as Arguments (Review)](#objects-as-arguments-(review))
    - [More on Algorithm Analysis](#more-on-algorithm-analysis)
  
### Intro
Below are the notes from the Friday (11/14) SI session.

#### Notes
We talked about passing objects through functions as arguments, 

Topics discussed during the session:
- Objects as Arguments
- More on Algorithm Analysis

##### Objects as Arguments (Review)
A review on how objects should be passed through functions.

Typically you want to pass objects by reference (when you plan to edit them inside 
a function) or `const` reference (when you do not plan to edit them inside a function).

Remember that, if you plan on editing an object, it must be passed through a function 
by-reference. If you pass by-value, you are sending a copy of the object (and thus not 
editing the original object you want to edit).

An example function of where we plan on editing an object argument:
```C++
  void increase_width(Square& s, int w);  //adds w to the square's current width
```

An example function for `const` reference parameters, where inside this function 
all we're doing is returning the average of the values in a `double` vector (which is an object):
```C++
  double print_avg(const vector<double>& list);  //recall that the type of 'list' is 'vector<double>'
```

##### More on Algorithm Analysis
Went through entire examples of bubble sort, selection sort, linear/sequential search, and 
binary search.

Like the last notes: It's typically easier to understand sorting/searching algorithms if you 
see it visually, then afterwards reviewing psuedo-code to fully understand what is going on.

Head over to the Wednesday notes page [here](WED_NOTES.md) for a list of links, under the "Algorithm 
Analysis" section.

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>