# Week 6 Notes - Friday

## Sections
- [Intro](#intro)
  - [Notes](#notes)
    - [Vector Functions](#vector-functions)
  
### Intro
Below are the notes from the Friday (10/03) SI session.

#### Notes
Worked a bit on the worksheet from Wednesday and a new worksheet. Talked, in detail, 
what each vector function we're working on does.

Topics talked about today:
- Vector Functions

##### Vector Functions
On [this](http://www.cplusplus.com/reference/vector/vector/) page (an excellent reference 
for when working with vector functions), the vector functions will be presented as below. 
Since we didn't have multiple computers at our disposal in the session, I gave brief 
explanations similar to the below on each focused function. Look at the reference, solutions 
for week 6 (first worksheet), or powerpoint on 8-3 for more information.

1. (constructor): This is the first thing called when declaring a vector, and __cannot_ be called 
anywhere else. More about constructors will be talked about when we learn about classes in class 
(should be next Wednesday; pun intended).

2. operator=: Means to use the equals operator (e.g. `vect = vect2` where `vect` and `vect2` are 
same-data type vectors)

3. size(): Represents the size (i.e. number of elements) in the vector

4. empty(): Boolean that returns true if the vector has no elements (size == 0) or false if 
it has elements (size != 0)

5. clear(): Clears the vector (removes all items in the vector so size == 0)

6. operator[x]: Just like static-arrays, means to call the xth position of the vector (i.e. `vect[x]`)

7. at(x): Returns the item at position x (synonymous to `vect[x]` except with error-bounds checking)

8. front(): Returns the first element in the vector (i.e. `vect[0];`)

9. back(): Returns the last element in the vector (i.e. `vect[vect.size() - 1];` where "vect.size() - 1" 
equals "n - 1" which is the same as saying the last position, since our range is "0 to n-1" for arrays).

10. push_back(x): Adds item x to the back of your vector

11. pop_back(): Removes the last item in your vector

Most of the functions are pretty straightforward. `push_back(x)` and `pop_back()` have a bit of history 
in their name, and it's a little hard describing them (in full detail) without talking about some 
CS 131 topics (specifically when you talk about the stack ADT).

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>