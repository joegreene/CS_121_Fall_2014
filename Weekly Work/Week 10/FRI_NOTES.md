# Week 10 Notes - Friday

## Sections
- [Intro](#intro)
  - [Notes](#notes)
    - [Variable Scoping](#variable-scoping)
    - [Including Files By < > versus " "](#including-files-by---versus--)
  
### Intro
Below are the notes from the Friday (10/31) SI session.

#### Notes
We continued working on last week's worksheet, topics from last week, and 
reviewed variable scoping.

Topics discussed during the session:
- Variable Scoping
- Including Files By < > versus " "

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

If your answer was (or do not understand why it is) not 8, you should review your notes on how scoping works.

In general, you want to avoid having same-name variables (limit it the best you can). This way your code becomes 
less ambiguous in the long run.

##### Including Files By < > versus " "
If you really want to you can say `#include "iostream"` or `#include <Date.h>` instead of the usual 
`#include <iostream>` and `#include "Date.h".

Although there are special rules (such as the post by Jack Klein [here](http://bytes.com/topic/c/answers/138207-include-file-vs-include-file)), 
you only need to work with the following rule of thumb:
- If the file is predefined (such as `iostream` and `string`), use angled brackets (`< >`)
- If the file is custom (like `Date.h` or `FCylinder.h`), use quotation marks (`" "`)

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>