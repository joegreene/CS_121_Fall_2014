# Various Tips for Programming

## Contents
- [Intro](#intro)
- [Topics](#topics)
  - [General Tips](#general-tips)
  - [g++](#g)
    - [Console Setup](#console-setup)
  - [Visual Studio Tips](#visual-studio-tips)
    - [Line Numbers](#line-numbers)
    - [Change Indentation and Tab Sizes](#change-indentation-and-tab-sizes)
    - [Change the Theme and Look](#change-the-theme-and-look)
  - [XCode](#xcode)
  - [Using OS-Specific Code](#using-os-specific-code)

### Intro
This page hosts various tips I wanted to let you guys know for the class. They aren't in order, and 
I couldn't think of where else to put these. More information will be added to this page during the semester.

If you have the chance to at home, stick with Visual Studio. This way you can stick with the class and not worry so much about 
importing your code to Visual Studio when working in the lab or turning in work to titanium.

If any one has any ideas to add onto this page, let me know please. It'd be really handy to have someone give me information 
on other IDEs and compilers such as XCode, Code::Blocks, and g++ as I don't have much experience with them.

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
- Despite what people say: Less lines of code doesn't necessarily mean better code. You can have everything on a single line in C++, or even have 
a 50 line program turn into 5 lines, but if your code is unclear (or uncommented on confusing parts) then that's not very good code. Balance lines and readability.
- A continuation of the previous point: Write your code so that you can look at it a year or more later and be able to understand it. You make code 
to help yourself and others understand your logic.
- There are many different ways to write a program and solutions to solving issues. It's more of a matter of finding the most efficient version.
- CS 121 is a difficult course, and is meant to be because this class serves as your programming foundation. If you do not do well in this class, end up 
skimming on parts, or disregard some topics, 131 will be a nightmare.

The above is not in any order other than when they popped up in my mind.

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

##### Line Numbers
The very first thing I do when I'm working with code in some text editor is I find out how to enable line numbers. In this case, it's 
Visual Studio's text editor.

To do so in Visual Studio (or the express versions; should work for all versions) do the following: 
- When open in a project, at the top click Tools -> Open the list (make the arrow point down) for Text Editor -> Do the same for 
All Languages -> General -> Check the box for Line Numbers -> Click OK.

You should have line numbers now. If you ever plan to work with more than C++ in Visual Studio you can set line numbers to pop up specifically only for 
C/C++ by clicking "C/C++" instead of "All Languages". I don't really see the reason why you wouldn't do it for all languages, but it's there as an option.

##### Change Indentation and Tab Sizes
First thing's first: When working with code you should be working with spaces, not tabs. You'll want to change it so that, when pressing tab, 
the editor in Visual Studio inserts spaces instead of a tab when you indent (i.e. press tab).

To do this it's pretty much the same as setting up line numbers:
- When open in a project, at the top click Tools -> Open the list (make the arrow point down) for Text Editor -> Do the same for 
All Languages -> Tabs, and from here look at the "recommendation on tab/indent sizes" page listed below. Afterwards, click OK and it should be saved.

__NOTE__: Make sure to click the "Insert spaces" option!

Here's a page describing the steps in case the above instructions were unclear: http://msdn.microsoft.com/en-us/library/ms165330%28v=vs.90%29.aspx

Here's a page with recommendations on tab/indent sizes: http://blogs.msdn.com/b/vseditor/archive/2009/03/19/how-do-you-use-tab-size-and-indent-size.aspx

Personally, I work work tab and indent size 2, and block indentation as I'm most comfortable with these settings. Play around with it all you want, but 
keep in mind that your tab and indent size should be equal (doesn't make sense otherwise). Two to four works best for everyone. Like the line numbers, 
you can specify how indents and tab sizes work for other languages in Visual Studio by clicking the individual languages instead of "All Languages".

##### Change the Theme and Look
Check out this link if you're using VS 2012 or 2013: http://msdn.microsoft.com/en-us/library/hh923906.aspx

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
    cin.get();  //alternatively, "cin.ignore(1000, '\n');" can be used too
  }
```

It's certainly not as nice as typing a single line, but it's still an alternative and works for more than just a Windows operating system. From what I hear, it's quicker too.

More info on `cin.ignore(1000, '\n')` [here](http://www.cplusplus.com/reference/istream/istream/ignore/) and [here](http://www.cplusplus.com/forum/beginner/9148/).

More info on this [here](http://www.cplusplus.com/forum/windows/55426/).

If you have any worries about other pieces of code that may seem OS-specific, google search is always there to help.

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>
