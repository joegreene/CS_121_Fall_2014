# Week 6 Solutions

## Sections
- [Intro](#intro)
- [Worksheet 1](#worksheet-1)
  - [Questions](#questions)
    - [Syntax Practice](#syntax-practice)
    - [General Concept](#general-concept)
- [Worksheet 2](#worksheet-2)
  - [Questions](#questions-1)
    - [Syntax Practice](#syntax-practice-1)
    - [Functions Section](#functions-section)
    
### Intro
This page hosts the solutions to the questions in both worksheet 1 and 2 for this week.

Worksheet 1's solutions will be posted on Friday afternoon, 
and worksheet 2's solutions will be posted Wednesday afternoon
(next week).

__NOTE__: I have made revisions to the following problems. Explanations are 
with each corresponding solution and the problems are noted in the "Questions" section.

__NOTE 2__: I've included sample programs for two problems of worksheet two in a folder on this page 
(under the "Programs" folder).

### Worksheet 1
Above with file name "CS 121 Week 6 - Vectors Worksheet.docx".

Check [this](http://www.cplusplus.com/reference/vector/vector/) page out for __A LOT__ of 
information regarding vectors. Follow the instructions from the worksheet to understand how 
to use the website.

#### Questions
Problems revised (edits already made in uploaded .docx):
- Syntax Practice: #4, #9

##### Syntax Practice
__1)__ Answers may vary.

One possible solution (adds 0, 15, 30, 45, 60 to list):
```C++
  for(int i = 0; i < 5; ++i)
  {
    dynscores.push_back(i*15);
  ]
```

__2)__ Focus mainly on how "size()" is used in this:
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

__3)__ For loop:
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

__4)__ I made a weird mistake with this (should say "push_back" only)
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

__5)__ Single line:
```C++
  dyn_scores = more_scores;
```

__6)__ Using `double mean` for this:
```C++
  double mean = 0;
  
  for (int i = 0; i < dyn_scores; ++i)
  {
    mean+=dyn_scores.at(i); //can use [i] as well
  }
  
  //Mean is calculated by the sum of all values divided by the number of values
  cout << "Mean: " << (mean / dyn_scores.size()) << endl;
  
```

__7)__ 
`dyn_scores` (similar to `more_scores`):
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

`grades`
```C++
  for(int i = 0; i < STUDENT_SIZE; ++i)
  {
    grades[i] = 0;
  }
```

__8)__ Empty check:
```C++
  if(dyn_scores.empty() && more_scores.empty())
  {
    //...
  }
```

__9)__ Six ways (three each; can be done to dyn_scores too):
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
__1)__ Nope. Say we had a vector called "vect". If we want its size, we call "vect.size();". There's no 
need to worry about how many elements we have because ".size()" marks how many elements we have. 
A vector's size is dynamic, and we won't be dealing with partially-filled vectors.

__2)__ A vector is not a primitive type. This is because we have to include a library (i.e. `#include <vector>`) 
in order to use it. Examples of primitive data types are `int`, `bool`, `char`, `double` and so on that don't need 
any external dependencies (like adding in libraries).

__3)__ Refer to the chapter 8, section 8-3 powerpoint notes for this. It covers most information regarding this
question.

### Worksheet 2
Above with file name: "CS 121 Week 6 - Vectors, Delimiters, and Functions.docx".

"Programs" folder above contains two programs you can test out from this worksheet.

Revisions made (already fixed in uploaded .docx files):
- Last problem (second section); will be explained later.

__NOTE__: On Monday the notes will cover why, in class, why I made the revision to the last problem.

#### Questions
Located below.

##### Syntax Practice
__1)__ Possible solution:
```C++
  double num = 0;
  vector<double> num_list;
  
  //While there still grabbable input on the line
  while(cin >> num)
  {
    num_list.push_back(num);
    cin.ignore(1,'|'); //we could use "cin.ignore(1)", 
                       //"cin.ignore(1231,"|");"
                       //or the line above. 
  }
```

__NOTE__: The above will infinitely keep asking for more numbers. We can remedy this by changing 
the while statement. For instance, if we want to stop at 50 numbers then we can do the following:
```C++
  double num = 0;
  vector<double> num_list;
  
  //While there still grabbable input on the line AND we haven't exceeded 50 numbers in the list
  while(cin >> num && num_list.size() < 50)
  {
    num_list.push_back(num);
    cin.ignore(1,'|'); //we could use "cin.ignore(1)", 
                       //"cin.ignore(1231,"|");"
                       //or the line above. 
  }
```

__2)__ One solution:
```C++
  ifstream infile("novel.txt");

  string cur_str;           //current string
  vector<string> word_list; //vector of string type to hold all the words

  if(infile.is_open())
  {
    //While we can still grab data AND we have less than 500 words in the list
    while(infile >> cur_str && word_list.size() < 500)
    {
      word_list.push_back(cur_str);
    }

    infile.close(); //close file we're working with

    int num_char = 0; //set up character count variable

    for(int i = 0; i < word_list.size(); ++i)
    {
      //num_char equals num_char plus the ith element in word_list's length
      num_char+=word_list[i].length();
    }

    cout << "Total number of characters in the " << word_list.size() << " words"
         << " grabbed from novel.txt: " << num_char << endl;
  }
  else
  {
    cout << "File could not be opened. Make sure that the filename and extension match the   following: "
         << "\"novel.txt\"\n";
  }
```

__NOTE__: I've included the full program of the above so you can try it out yourself, or you can simply do the following:
1. Type out the above in a visual studio project
2. Create a file named "novel.txt" with a bunch of words for the program to read from
3. Compile the program (and fiddle around with the code to see different outputs).

The file is named "syntax_prob2_ws2_wk6.cpp" and is located under the "Programs" folder of this page. 

__NOTE 2__: I mentioned not to use "getline" because it would become troublesome to skip both spaces and newline (`\n`) 
characters. To understand what I'm talking about, try replacing `infile >> cur_str` with `getline(infile, cur_str, ' ')`
(to skip spaces). You'll get an unexpected amount of words because `\n` will be counted as a string.

##### Functions Section
__1)__ One possible solution:
```C++
  void print_str(string user_str, int times)
  {
    for(int i = 0; i < times; ++i)
    {
      cout << user_str << endl;
    ]
  }
```

__2)__ One possible solution:
```C++
  bool did_print(const int num_list[], int SIZE) //static arrays are called by-reference (use const to prevent changes)
  {
    ofstream outfile("num_output.txt");
    
    if(outfile.is_open())
    {
      for(int k = 0; k < SIZE; ++k)
      {
        outfile << num_list[i] << endl;
      }
      
      outfile.close(); //easy to forget!
    }
    else
    {
      cout << "Error when attempting to open \"num_output.txt\"\n";
      
      //Unsuccessful print (return false)
      return false;
    }
    
    //Never reached "else" statement therefore print was successful
    return true;
  }
```

__3)__ The solution is located in the "Programs" folder load up the file "funct_prob3_ws2_wk6.cpp".

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>