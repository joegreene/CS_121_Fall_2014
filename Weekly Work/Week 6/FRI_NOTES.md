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

1. __(constructor)__: This is the first thing called when declaring a vector, and __cannot_ be called 
anywhere else. More about constructors will be talked about when we learn about classes in class 
(should be next Wednesday; pun intended).

2. __operator=__: Means to use the equals operator (e.g. `vect = vect2` where `vect` and `vect2` are 
same-data type vectors)

3. __size()__: Represents the size (i.e. number of elements) in the vector

4. __empty()__: Boolean that returns true if the vector has no elements (size == 0) or false if 
it has elements (size != 0)

5. __clear()__: Clears the vector (removes all items in the vector so size == 0)

6. __operator[x]__: Just like static-arrays, means to call the xth position of the vector (i.e. `vect[x]`)

7. __at(x)__: Returns the item at position x (synonymous to `vect[x]` except with error-bounds checking)

8. __front()__: Returns the first element in the vector (i.e. `vect[0];`)

9. __back()__: Returns the last element in the vector (i.e. `vect[vect.size() - 1];` where "vect.size() - 1" 
equals "n - 1" which is the same as saying the last position, since our range is "0 to n-1" for arrays).

10. __push_back(x)__: Adds item x to the back of your vector

11. __pop_back()__: Removes the last item in your vector

Most of the functions are pretty straightforward. `push_back(x)` and `pop_back()` have a bit of history 
in their name, and it's a little hard describing them (in full detail) without talking about some 
CS 131 topics (specifically when you talk about stacks).

Best way to think of vectors as a stack of papers or dishes: You 
push a sheet/dish onto the top (back) and "pop the top" to remove the most recently-added sheet/dish.

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>