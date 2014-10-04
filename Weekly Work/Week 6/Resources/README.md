# Week 6 Solutions

## Sections
- [Intro](#intro)
- [Worksheet 1](#worksheet-1)
  - [Questions](#questions)
    - [Syntax Practice](#syntax-practice)
    - [General Concept](#general-concept)
- [Worksheet 2](#worksheet-2)
  - [Questions](#questions)

### Intro
This page hosts the solutions to the questions in both worksheet 1 and 2 for this week.

Worksheet 1's solutions will be posted on Friday afternoon, 
and worksheet 2's solutions will be posted Wednesday afternoon
(next week).

__NOTE__: I have made revisions to the following problems. Explanations are 
with each corresponding solution and the problems are noted in the "Questions" section.

### Worksheet 1
Above with file name "CS 121 Week 6 - Vectors Worksheet.docx".

Check [this](http://www.cplusplus.com/reference/vector/vector/) page out for __A LOT__ of 
information regarding vectors. Follow the instructions from the worksheet to understand how 
to use the website.

#### Questions
Problems revised (edits already made in uploaded .docx):
- Syntax Practice: #4, #9

##### Syntax Practice
1. Answers may vary.

One possible solution (adds 0, 15, 30, 45, 60 to list):
```C++
  for(int i = 0; i < 5; ++i)
  {
    dynscores.push_back(i*15);
  ]
```

2. Focus mainly on how "size()" is used in this:
```C++
  for(int i = 0; i < dyn_scores.size(); ++i)
  {
    cout << "Score " << (i+1) << ": " << dyn_scores[i] << endl;
  }
```

Output (using my example numbers):
```
  Score 1: 0
  Score 2: 15
  Score 3: 30
  Score 4: 45
  Score 5: 60
```

3. For loop:
```C++
  for(int i = 0; i < dyn_scores.size(); ++i)
  {
    dyn_scores.pop_back();
  }
```

Single line:
```C++
  dyn_scores.clear();
```

4. I made a weird mistake with this (should say "push_back" only)
```C++
  for(int i = 0; i < STUDENT_SIZE; ++i)
  {
    more_scores.push_back(grades[i]);
  }
```

__NOTE__: We cannot replace `more_scores.push_back(grades[i]);` with the following:
```C++
  more_scores[i] = grades[i];
  //or
  more_scores.at(i) = grades[i];
```

This is because, if we access try to access the position (in the for loop) at those times, 
we'll be accessing the nth position every time (which is an out-of-bounds error).

For example, in the first iteration (of the for loop) we have the following:
```C++
  more_scores.size() = 0; //we have no elements in the list
```

This means that there are no indexes available to access. In the second iteration:
```C++
  more_scores.size() = 1; //we have one element in the list
```

This means there is only one item and, recalling back to static arrays, if we access the nth position 
(i.e. if the index we attempt to call is equal to the list's size), we will get an out-of-bounds error. 
The range is `0 to n-1` where n is the list's size. This pattern occurs each iteration.

5. Single line:
```C++
  dyn_scores = more_scores;
```

6. Using `double mean` for this:
```C++
  double mean = 0;
  
  for (int i = 0; i < dyn_scores; ++i)
  {
    mean+=dyn_scores.at(i); //can use [i] as well
  }
  
  //Mean is calculated by the sum of all values divided by the number of values
  cout << "Mean: " << (mean / dyn_scores.size()) << endl;
  
```

7. 
1) `dyn_scores` (similar to `more_scores`):
```C++
  for(int i = 0; i < dyn_scores.size(); ++i)
  {
    dyn_scores[i] = 0;
  }
```

__NOTE__: The "quickest" way to do this is in your book (or so I remember). It involves using the vector functions 
"clear()" and "resize()". Although I don't remember if this is necessary to know for this class, it is indeed extremely 
handy:
```C++
  dyn_scores.clear();       //clear dyn_scores so it has no elements (dyn_scores.size() is 0 now)
  dyn_scores.resize(5, 0);  //resizes dyn_scores so its size is 5, and sets each position to 0
```

Check [this](http://www.cplusplus.com/reference/vector/vector/resize/) page out for information regarding the `resize` function.

2) `grades`
```C++
  for(int i = 0; i < STUDENT_SIZE; ++i)
  {
    grades[i] = 0;
  }
```

8. Empty check:
```C++
  if(dyn_scores.empty() && more_scores.empty())
  {
    //...
  }
```

9. Six ways (three each; can be done to dyn_scores too):
```C++
  //Front
  more_scores.front();
  more_scores.at(0);
  more_scores[0];
  
  //Back
  more_scores.back();
  more_scores.at(more_scores.size() - 1); //same as saying n-1 where n is the size of the list
  more_scores[more_scores.size() - 1];
```

__NOTE__: Sorry if it was unclear on what I was asking of you. I meant "two ways per part", which 
(in a sense) equates to four total lines.

##### General Concept
1. Nope. Say we had a vector called "vect". If we want its size, we call "vect.size();". There's no 
need to worry about how many elements we have because ".size()" marks how many elements we have. 
A vector's size is dynamic, and we won't be dealing with partially-filled vectors.

2. A vector is not a primitive type. This is because we have to include a library (i.e. `#include <vector>`) 
in order to use it. Examples of primitive data types are `int`, `bool`, `char`, `double` and so on that don't need 
any external dependencies (like adding in libraries).

3. Refer to the chapter 8, section 8-3 powerpoint notes for this. It covers most information regarding this
question.

### Worksheet 2
Above with file name: "CS 121 Week 6 - Vectors, Delimiters, and Functions.docx".

Revisions made (already fixed in uploaded .docx files):
- Last problem (second section); will be explained later.

__NOTE__: On Monday the notes will cover why, in class, why I made the revision to the last problem.

#### Questions
Will be filled out next week Wednesday.

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>