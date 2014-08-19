# Documentation (and Writing Style)

## Contents
- [Intro](#intro)
- [Topics](#topics)
  - [Self Tips](#self-tips)
  - [Using OS-Specific Code](#using-os-specific-code)

### Intro
TBD

One major rule to know: There are always different ways to write a program.

### Topics
TBD

#### Self Tips
TBD

#### Using OS-Specific Code
Some statements, such as `system("pause");` which calls the command prompt to pause input (gives that fancy "Press any key to continue..." prompt), are 
OS-specific. That means they only work on specific operating systems.

Using OS-specific code is typically bad to do, but at times unavoidable. It's best to have your code work everywhere (unless you plan on being selfish).

For instance, an alternative to `system("pause")` is making a function like the following:
```C++
  void sys_pause()
  {
    cout << "Press ENTER to continue...";
    cin.get();  //alternatively, cin.ignore can be used too
  }
```

It's certainly not as nice as typing a single line, but it's still an alternative and works for more than just a Windows operating system (from what I hear, it's quicker too).

More info on this [here](http://www.cplusplus.com/forum/windows/55426/).

If you have any worries about other pieces of code that may seem OS-specific, google search is always there to help.

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>