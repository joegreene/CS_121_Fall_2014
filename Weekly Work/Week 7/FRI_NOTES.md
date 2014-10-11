# Week 7 Notes - Friday

## Sections
- [Intro](#intro)
  - [Notes](#notes)
    - [Passing By Reference vs. Passing By Value](#passing-by-reference-vs-passing-by-value)
    - [Static Variables](#static-variables)
    - [Passing by const-reference](#passing-by-const--reference)
    
### Intro
Below are the notes from the Friday (10/10) SI session.

Topics discussed:
- Passing By Reference vs. Passing By Value
- Static Variables
- Passing by const-reference


#### Notes
Below are the notes, split into topics.

##### Passing By Reference vs. Passing By Value
General rule of thumb:
- Pass by value when you are passing a small variable (primitive data type) through a function as an argument
- Pass by reference if you need to send a large variable (e.g. a vector of some data type) or want to return more 
than one value from a function. If you're moving a large variable but don't want to change its value, call by const-reference.

If you'd like to see the difference between the two, the best thing you can to for yourself is try it out in Visual Studio. 
If you go back to the main page for Week 7, go to the top (where the file listing is) and click on 
"value_versus_reference_w7.cpp". Run the code in here through Visual Studio.

##### Static Variables
Although hardly ever used in practice (or at least I never need them), to set a variable as `static` means to have the variable not 
lose its value when you leave its scope. With all the previous jargon it might be confusing to understand, however check out the following 
example:

```C++
  void print_num_calls()
  {
    static int num_calls = 0;
    num_calls++;
    cout << "Current value of num_calls: " << num_calls << endl;
  }
  
  int main()
  {
    for(int i = 0; i < 4; ++i)
    {
      print_num_calls();
    }
    return 0;
  }
```

Output:
```
  Current value of num_calls: 1
  Current value of num_calls: 2
  Current value of num_calls: 3
  Current value of num_calls: 4
  ...
```

Run the program above in a visual studio project to compare my output with yours.

So the concept of `static` might be easy to understand, however the most funky part (at least for me) is:
```C++
  static int num_calls = 0;
``` 

You might be thinking "Doesn't `num_calls` get reset to 0 each time?" Short answer: __No__. Why? Because that's how 
C++ works with `static` variables. It might be hard to comprehend, however just remind yourself the following:
```
  The initialization statement of a static variable is only ever called once.
```

So yeah. There aren't many situations that static variables are necessary, but there still exist some. If you're stuck on that 
question (from the worksheet), check out my solution on the solutions page.

A problem similar to the program above is in the worksheet for this week.

##### Passing by const-reference
Like mentioned previously: Pass by const-reference when you're moving a big variable as a function argument but don't want to 
change the variable itself.

Let's say you have a million integers inside a vector. If you were to pass that vector by-value to a function, the function would 
first copy _every_ value first then run the function. That's a lot of data! More specifically:
```
  4 bytes per integer * 1 million integers to copy = 4 million bytes to copy
```

Okay, maybe that's not a lot nowadays (since 4 million bytes is roughly 4 megabytes and most computers nowadays have at least 4 gigabytes of 
RAM). The point is the operation (the by-value copying) will take awhile to do. It can get nasty when we start making bigger byte-size objects and 
having a lot of them in vectors. Although right now you can't see its effect at this point in time, it'll be very apparent in CS 131 when you start 
to work with large data structures.

Example syntax of calling by const-reference:
```C++
  void print_vect(const vector<string>& str_list); //calling vector by const-reference
  int ret_sum(const int list[], int SIZE);         //remember that arrays are automatically called by reference
```

Although you won't be dealing with that many values in a vector in CS 121 (that's more of a CS 131 project), in computer science you 
have to expect the worst. For that reason, and to have a [robust](http://www.linfo.org/robust.html) program, you'll want to call 
variables that aren't primitive (e.g. not `char`, `int`, `int`, etc.) by reference. Add `const` if you don't want the variable to change.

__NOTE__: You'll learn about it later, but the reason why arrays are automatically called by reference is because they are specialized pointers. 
For instance, know how you get a funky value if you print the identifier of a static array instead of each element? That's because you're printing 
out the address of the first position of the array (a concept tied to pointers).

I won't go over how arrays are special pointers until we do so in lecture, but if you want a head-start read it in your book or check out an online 
resource such as [here](http://www.cplusplus.com/doc/tutorial/pointers/).

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>