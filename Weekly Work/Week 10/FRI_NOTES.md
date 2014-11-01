# Week 10 Notes - Friday

## Sections
- [Intro](#intro)
  - [Notes](#notes)
    - [Variable Scoping](#variable-scoping)
  
### Intro
Below are the notes from the Friday (10/31) SI session.

#### Notes
We continued working on last week's worksheet, topics from last week, and 
reviewed variable scoping.

Topics discussed during the session:
- Variable Scoping

We also made a recap about last session's (10/29) notes on the scope operator. I 
chose not to include it in this file as it was almost the same talk as last 
time.

##### Variable Scoping
If you were to run the following program, what would its output be?
```C++
  #include <iostream>
  using namespace std;
  
  int i = 44;
  int main()
  {
    int i = 7;
    ++i;
    
    if(i != 0)
    {
      int i = 4;
      ++i;
    }
    
    cout << i << endl;
    
    return 0;
  }
```

If your answer was not 8, you should review your notes on how scoping works.

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>