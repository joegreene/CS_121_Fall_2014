# Week 16 Notes - Wednesday

## Sections
- [Intro](#intro)
  - [Notes](#notes)
    - [Recursion](#recursion)
    - [Templates](#templates)
    
### Intro
Below are the notes from the Wednesday (12/10) SI session.

#### Notes
We worked on this week's worksheet mainly, went over the idea of recursion in programming, 
and recapped a bit on templates.

Topics discussed during the session:
- Recursion
- Templates

As a pro-tip:

If you're ever lost with any of the recursion (or iteration), the best thing you can do for yourself is to 
__trace the program__. This helps immensely when trying to understand what's going on each step, and will 
significantly help you out in 131 and later programming.

##### Recursion
We talked primarily about how to spot a type of problem that can be recursively solved, and 
what recursion is.

Recursion is a way to break down a problem over and over until it becomes simple to solve. In 
our case, recursion involves a function calling itself until it reaches some sort of base case 
(which is that simple-to-solve part).

A recursive algorithm must meet these three things:

1. There must be a base case (or else your function goes on infinitely)
2. There must be some sort of move towards the base case
3. The function must call itself

Typically, if a pattern is noticeable (and can be written as an instance of itself but changed 
slightly), then you can make a recursive solution out of it. Also, all recursive solutions have 
iterative solutions, and vice-versa. If you don't remember, an iterative solution is a problem 
solved by using loops (e.g. by using a for-loop or while-loop).

A widely-used example of recursive programming is the factorial function. Generally, it's defined to be:
```
  n! = n * (n-1) * (n - 2) * ... * (n - (n - 1))
  
  Where 1! = 0! = 1
```

If we wanted to implement this as a recursive function, we'd have to notice the recursive call made and 
the base case it ends to. It's easiest if we use numbers first, then derive to a generalized solution.

Trying out the example `5!`, we have the following:
```
  5! = 5 * 4 * 3 * 2 * 1
```

We can also say the following about the above:
```
  5! = 5 * 4!
```

Breaking this down more, we can then have:
```
  4! = 4 * 3!
  3! = 3 * 2!
  2! = 2 * 1!
```

All the way down to `1! = 1`. Noting the pattern of `n! = n * (n-1)!`, we have our recursive call, `1! = 1` 
is our base case, and `0! = 1` as an extra case (if in case a user decides to compute that with our function).

Translating this to C++, we have the following:
```C++
  int fact(int n) {
    if(n == 0) { //special case
      return 1;
    }
    else if(n == 1) { //base case
      return 1;
    }
    else { //recursive call
      return n * fact(n-1);
    }
  }
```

We could mix the cases `n == 0` and `n == 1` together, however I typed it like so above just to make my point 
across.

If we were to call this function to find the fourth factorial, `4!`, a visual diagram would look something like this:
```
  fact(4)
    |
    --> 4 * fact(3)
              |
              --> 3 * fact(2)
                        |
                        --> 2 * fact(1)
                                  |
                                  --> 1
```

In order to evaluate the factorial recursively, the program must first figure out what the following function 
returns. A call of `fact(4)` would need `fact(3)`, `fact(3)` needs `fact(2)`, and lastly `fact(2)` would need 
`fact(1)`. After it gets the value it needs, it flows back up to the initial factorial call (that is, `fact(4)`).

As the example here is from the worksheet from this week, I've added some more information over there.

On top of the PowerPoint notes and this, [this page](http://web.eecs.utk.edu/~cs102/lectures/recursion.html) 
can help out a lot too.

__TRIVIA__: The iterative solution is generally better than the recursive solution of the factorial. Check out 
[this page](http://www.codeproject.com/Articles/21194/Iterative-vs-Recursive-Approaches) for a good explanation.

##### Templates
Templates are a way to have generalized data types in a class or function, so the class/function 
can work with more types of objects through them without typing special functions for each type.

For instance, let's say you wanted to create an addition function (for whatever reason) that added 
two values of the same type together. An integer example would be:
```C++
  int add(int a, int b) {
    return a + b;
  }
```

If we wanted to have an integer version, a double version, and a string version of this, then we'd 
need three different functions:
```C++
  int add(int a, int b);
  double add(double a, double b);
  string add(string a, string b);
```

If we need more, we'd have to type (linearly) many more. One way around this is by using a template:
```C++
  template<class Gen>
  Gen add(Gen a, Gen b) {
    return a + b;
  }
```

Which allows us to use any one type inside the function, removing the need to retype the function per type 
required.

The `template` part is self-explanatory and the part inside the angled-brackets (`class Gen`) is just a 
generic name. It could be `class T` for all we care, just making sure we plug in `T` instead of `Gen` in 
the function.

Keep in mind that, especially with the above function, the program assumes that all types you put into the function 
support whatever operations you use on the generic type. 

A great example of this is the `vector` class we've worked with. Notice how you can define 
a `vector` to use `string`, `double`, `int`, ... pretty much any type of object you want, like so:
```C++
  vector<string> string_list;
  vector<bool> bool_list;
  vector<char> char_list;
  //etc.
```

The reason it's possible is because the `vector` class uses templates. If you'd like more information 
on this beyond the Power Point, check [this](http://www.tutorialspoint.com/cplusplus/cpp_templates.htm) 
page out.

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>