# Week 13 Notes - Wednesday

## Sections
- [Intro](#intro)
  - [Notes](#notes)
    - [Operator Overloading](#operator-overloading)
    - [`friend` keyword](#friend-keyword)
    
### Intro
Below are the notes from the Wednesday (11/19) SI session.

#### Notes
We worked on this week's worksheet and talked about Monday's lecture. We reviewed operator overloading and 
the friend keyword.

Topics discussed during the session:
- Operator Overloading
- `friend` Keyword

##### Operator Overloading
Mainly just a useful tool, __operator overloading__ allows you to set up a class so you may define how some operators 
(such as arithmetic, conditional, and insertion/extraction) work for your class. You could technically avoid operator 
overloading altogether by making specially-named functions, however operator overloading is there for convenience's sake.

One great example for operator overloading is when working with `vector` and `string` objects:
```C++
  //The following would not be possible without operator overloading
  vector<int> vect1;
  vect1.push_back(2);
  vector<int> vect2 = vect1; //overloaded assignment operator in vector class
  
  string s1 = "hello";
  string s2 = s1;            //overloaded assignment operator for string class
```

Without the above, you'd be stuck copying positions by-index in a for loop! You'd also be stuck with using `.at(int i)`, since 
`[]` is an overloaded operator for both `vector` and `string`.

They may seem difficult to understand at first (I know it was for me). Best way to understand them is to think about 
how each operator functions, and from there see example implementations (like in the link below). Don't just memorize 
them!

I strongly suggest checking out the link [here](http://stackoverflow.com/questions/4421706/operator-overloading). 
Majority of the syntax examples I put on my worksheet were from here anyways.

Also a good resource for learning operator overloading is [here](http://www.tutorialspoint.com/cplusplus/cpp_overloading.htm). 
It has a list of all the overload-able/non-overload-able operators near the bottom as well.

##### `friend` Keyword
You use the `friend` keyword when you want to indicate that an external class or function should be given access to the entirety 
of a class. Take it for what it says: as friends are people you trust, having a friend class/function means it is trusted.

In general: `friend` allows another class or function to access another class's `private` and `protected` members directly (as if 
it were inside the class itself).

Although I went over this a little bit during the SI session, [here](http://www.cplusplus.com/doc/tutorial/inheritance/) is a nice 
reference, and so is the power point notes. [Here](http://stackoverflow.com/questions/17434/when-should-you-use-friend-in-c) as well 
if you want to know when to use `friend` (might be a bit hard to follow with though).

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>