# Various Tips for Programming

## Contents
- [Intro](#intro)
- [Topics](#topics)
  - [General Tips](#general-tips)
  - [g++](#g)
    - [Console Setup](#console-setup)
  - [Visual Studio Tips](#visual-studio-tips)
    - [Change Indentation and Tab Sizes](#change-indentation-and-tab-sizes)
    - [Change the Theme and Look](#change-the-theme-and-look)
  - [XCode](#xcode)
  - [Using OS-Specific Code](#using-os-specific-code)

### Intro
This page hosts various tips I wanted to let you guys know for the class. They aren't in order, and 
I couldn't think of where else to put these. More information will be added to this page during the semester.

If you have the chance to at home, stick with Visual Studio. This way you 

If any one has any ideas to add onto this page, let me know please. It'd be really handy to have someone give me information 
on other IDEs and compilers such as XCode, Code::Blocks, and g++.

### Topics
Helpful information below.

#### General Tips
Things that you might want to remind yourself when programming, or at least keep in mind at some point:
- Don't feel discouraged if you do not understand a concept. You're learning an entire language (grammar, "culture", the whole bit) and that's 
an incredible feat to perform. 
- Learn how each concept works or else your disregard will bite you in the butt later on (as everything in this class builds off of previous topics).
- Errors are frequent and computers are stingy. 
- Computer science is about helping people interact with computers. Without software engineers and computer scientists, using computers would be 
more cumbersome than useful.
- There are many different ways to write a program and solutions to solving issues. 

#### g++
Various tips for when working with the g++ compiler. I don't have much experience with this compiler, nor will I be putting emphasis on it. That is because the school 
primarily works with Visual Studio, and therefore I've to put most of my efforts into it.

##### Console Setup
If you're on a Linux distro: Your console output is perfect already. Be happy, and use the `apt-get` command, like [here](http://askubuntu.com/questions/348654/how-to-install-g-compiler) to install g++ (and its build libraries).

If you're on Mac OS X: Check [this](http://stackoverflow.com/questions/2122425/how-do-i-install-g-on-macos-x) out.

If you're on a Windows-based computer: You might want to use a different console other than command prompt. Here are some recommendations:
- http://lifehacker.com/5834755/how-can-i-make-the-windows-command-prompt-better
- http://www.guidingtech.com/23974/command-prompt-alternatives

Afterwards, check out a guide like this: http://www.cprogramming.com/g++.html

#### Visual Studio Tips
Various tips for when working with Visual Studio. This is mainly geared for 2013, but some (or all) parts may apply to previous versions.

##### Change Indentation and Tab Sizes
First thing's first: When working with code you should be working with spaces, not tabs. You'll want to change it so that, when pressing tab, 
the editor in Visual Studio 

Here's a page describing the steps: http://msdn.microsoft.com/en-us/library/ms165330%28v=vs.90%29.aspx

Here's a page with recommendations on tab/indent sizes: http://blogs.msdn.com/b/vseditor/archive/2009/03/19/how-do-you-use-tab-size-and-indent-size.aspx

Personally, I work work tab and indent size 2, and block indentation as I'm most comfortable with these settings. Play around with it all you want, but 
keep in mind that your tab and indent size should be equal (doesn't make sense otherwise).

##### Change the Theme and Look
Check out this link: http://msdn.microsoft.com/en-us/library/hh923906.aspx

#### XCode
I've never used this myself, and I don't have much information to put here.

Here are some links that might help you if you plan on using XCode:
- https://developer.apple.com/library/ios/referencelibrary/GettingStarted/RoadMapiOS/FirstTutorial.html - Tutorial for XCode
- http://www.visualstudio.com/en-us/get-started/share-your-xcode-projects-vs.aspx - Using XCode and Visual Studio together
- http://channel9.msdn.com/Blogs/One-Dev-Minute/Comparing-Xcode-to-Visual-Studio - Comparison of XCode to Visual Studio

#### Using OS-Specific Code
Some statements, such as `system("pause")` which calls the command prompt to pause input (gives that fancy "Press any key to continue..." prompt), are 
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

It's certainly not as nice as typing a single line, but it's still an alternative and works for more than just a Windows operating system. From what I hear, it's quicker too.

More info on this [here](http://www.cplusplus.com/forum/windows/55426/).

If you have any worries about other pieces of code that may seem OS-specific, google search is always there to help.

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>
