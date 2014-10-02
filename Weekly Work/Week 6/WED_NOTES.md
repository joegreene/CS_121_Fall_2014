# Week 6 Notes - Wednesday

## Sections
- [Intro](#intro)
  - [Notes](#notes)
    - [Vectors (Basics)](#vectors-basics)
    - [Using CPlusPlus.com](#using-cpluspluscom)
    - [Comparing Arrays and Vectors](#comparing-arrays-and-vectors)
  
### Intro
Below are the notes from the Wednesday (10/01) SI session.

#### Notes
We worked (did not finish) the Week 6 worksheet. We did, however, 
discuss the following topics (which pertain to the worksheet):

Topics discussed during the session (no particular order):
- Vectors (Basics)
- Using CPlusPlus.com
- Comparing Arrays and Vectors

##### Vectors (Basics)
The main thing to note is that a vector is a dynamically-sized array and the arrays we've 
been working with before are statically-sized. In layman's terms: Vectors can change size, 
whereas the arrays we've been working with before cannot change size.

Other than this, refer to the CH8 PPT on vectors, your notes, your book, or the following 
topic.

##### Using CPlusPlus.com
I'm pretty sure a good amount of you already know about this website, but disregarding that 
this website is a lifesaver when it comes to remembering thing about C++ (I'm specifically 
talking about the references section, __NOT__ the forums).

For practice, we went to the [cplusplus.com reference page for vectors](http://www.cplusplus.com/reference/vector/vector/), 
and looked at the pages for the following (grabbed from CH 8-3 PPT, p3):
- (constructor)
- operator=
- size
- empty
- operator[]
- at
- front
- back
- push_back
- pop_back
- clear

Some might be really weird to understand (especially (constructor)), however if you take 
the time to read through each page and look at the examples, they become easy to understand. 

__WARNING__: Only focus on the following parts when on each reference page: 
- `std::vector::vector`, . 
- Parameters
- Example (most important part!)

__TRIVIA__: (constructor) refers to the function called when declaring an object (in our case, that's 
a vector). As soon as it is made, . The constructor may not be called at any other point other than 
the object's declaration (in this case, the vector's declaration).

__TRIVIA 2__: operator= and operator[] is the way an object defines its own version of using the 
equals and bracket operators for itself. Stating "operator" in front is special notation, and you 
shouldn't need to worry about that (we'll talk more on why it looks like that later).


Especially ignore all the functions with "C++11" on them (we'll talk about this later).

##### Comparing Arrays and Vectors
Like we mentioned before: Vectors are dynamically-sized whereas typical arrays are statically-sized.

Remember that, to use a vector, we must use `#include <vector>`.

We didn't go too much into detail on this part (will be saved for Friday), however we did make a picture diagram 
of what goes on when we push_back, pop_back, and clear a vector:

1. Create a vector of type int called vect
```C++
  vector<int> vect;
```

Visually:
```
  No elements. (vect.size() == 0)
```

2. Add "17" to the end of vect. Add "12" to the end of vect.
```C++
  vect.push_back(17);
  vect.push_back(12);
```

Visually:
```
  [ 17 ]         (vect.size() == 1)
    0    
  [ 17 ] [ 12 ]  (vect.size() == 2)
    0      1
```

3. Pop (remove) the last value of vect
```C++
  vect.pop_back();
```

Visually:
```
  [ 17 ]         (vect.size() == 1)
    0    
```

4. Erase all elements in vect
```C++
  vect.clear();
```

Visually:
```
  No elements. (vect.size() == 0)
```

__WARNING__: If you attempt to call `vect.at(0);` at the end, you'll get an access violation error. This is 
because you're attempting to access the first position of a zero-size vector. There are no positions in a 
zero-size vector. If you use `vect[0]`, you'll get similar results.

__NOTE__: Key difference between `.at` and `[]` are explained [here](http://stackoverflow.com/questions/9376049/vectorat-vs-vectoroperator).

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>