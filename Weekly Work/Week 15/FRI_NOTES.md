# Week 15 Notes - Friday

## Sections
- [Intro](#intro)
  - [Notes](#notes)
    - [Command Arguments](#command-arguments)
    - [C-string vs. C++ string](#cstring-vs-c++-string)
    
### Intro
Below are the notes from the Friday (12/5) SI session.

#### Notes
We worked on this week's worksheet and talked about this week's lectures.

Topics discussed during the session:
- Command Arguments
- C-string vs. C++ string

##### Command Arguments
If you guys haven't seen it yet, Professor Anderson posted an image about this stuff for the most recent 
project. If you haven't seen it yet, check it out to work with this in Visual Studio. It's the third file 
in its section.

If you would like to know how to do this outside of Visual Studio then continue reading this section. It's 
not required for the class, but it gives you some practice with command prompt. Note that for this I'll be 
assuming you're working on a Windows-based operating system. 

Check out the image `command_prompt_example.jpg` in this week's file directory for an example of how to use 
command arguments in command prompt. It's made in paint, and I'm no artist, so I apologize in advance for 
the Microsoft Paint explanation. I've also included the code for my program as well, named `ProjectExample.cpp`.

Tips about command prompt:
- `cd`: Change directory
- Use quotation marks `" ... "` to move to a directory with spaces inside of it. You do not need quotation marks if there are no spaces.
- `dir`: Shows contents of current directory you're looking at
- `cd..`: Move to previous folder
- Type the executable's name to run it (e.g. `ProjectExample.exe`) as long as you're in its directory

__TRIVIA__: When you use the `system` function in C++, you're really just referring to the windows command prompt.
`system("pause");` means the program is going to command prompt and using the `pause` command. Try typing `pause` 
in command prompt and you'll see what I mean (also shown in example).

##### C-string vs. C++ string
Main thing to note is that `c-string` refers to the old-style C-language version of a string, whereas 
`string` refers to the C++ standard version of a string. You use a character pointer/array (remember that 
arrays are pointers) for c-string, and the string library for the C++ standard string.

The libraries for c-string functions is `cstring`, whereas the C++ string has them inside of the `string` 
library. [Here](http://www.cplusplus.com/reference/string/string/) is a list of functions for `string`, and 
[here](http://www.cplusplus.com/reference/cstring/) is a list of functions for `cstring`.

There are a lot of notes on this in the PowerPoint already, so I won't go into detail too much about it 
here. The main reason we'd ever really need to use c-strings in C++ is for compatibility and using certain 
functions. Performance-wise, the C++ standard string isn't too much to worry about versus the c-string.

Referring to compatibility: If we ever want to make our programs work with older systems (e.g. ones that rely 
on C code or do not have strings implemented in them) then we're forced to use c-strings.

Referring to functions: Some functions take in c-strings only as their parameters. For instance, the 
`open` function in `fstream` has a function heading something similar to the following:
```C++
  open(char * filename);
```

This pretty much means you can't use a C++ string directly as an argument for the function. Luckily enough for 
us, you can use `c_str()` to get a c-string out of a C++ string. For instance:
```C++
  string filename = "hello.txt";
  ifstream infile;
  infile.open(filename.c_str());
```

lets you then use the string `filename` as desired initially.

It's generally a good idea to avoid using c-strings if you can when working in C++. C-strings are harder to deal 
with, require you to call `new` or `delete`, are not dynamically-sized (i.e. you cannot resize them unlike the 
C++ string), and print a c-string is a hassle (must use a for-loop). Since with c-strings you're dealing with 
a pointer/static array, there's generally much more to worry about.

[Here](http://www.cs.fsu.edu/~myers/cop3330/notes/strings.html) is a nice page about comparing the two if in case 
you want to check another resource that can help. Same goes for [this](http://www.cprogramming.com/tutorial/lesson9.html)
site.

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>