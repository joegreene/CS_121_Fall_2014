# Week 16 Solutions

## Sections
- [Intro](#intro)
- [Worksheet](#worksheet)
  - [Questions](#questions)
    - [Problems](#problems)
    
### Intro
This page hosts the solutions to the questions for this week's worksheet. 

The worksheet itself is located in its usual place (in the file listing above). 

As a pro-tip:

If you're ever lost with any of the recursion (or iteration), the best thing you can do for yourself is to 
__trace the program__. This helps immensely when trying to understand what's going on each step, and will 
significantly help you out in 131 and later programming.

__NOTE__: The "error check case" on the worksheet was just to note if you understood 
how the base case stuff worked. I renamed it to something else in the updated worksheet, 
and you don't need to implement the error-checking inside.

__NOTE 2__: "Z+" means "positive integers". The problems were saying that `n`, `x`, and 
whatever other variables can only be `0, 1, 2, 3,...`, etc.

__NOTE 3__: I wrote out the Fibonacci sequence incorrectly and have made the correction 
in the uploaded worksheet (accidentally said f0 = 1 and not 0, which messes up with the 
rest of the sequence).

### Worksheet
Below is the worksheet solutions for this week.

#### Questions
Grab the questions from the worksheet document.

##### Problems
1) In a way I wanted you to relate this back to the power point notes (e.g. the telephone factorial 
slides), although it doesn't matter. Really, you should have just given an example of recursion you've 
seen before.

2) Generally, no. Check out [this page](http://www.codeproject.com/Articles/21194/Iterative-vs-Recursive-Approaches) 
for more information (it has a nice way of explaining the reason).

The last two are located on [this page](http://www.programcreek.com/2012/10/iteration-vs-recursion-in-java/). 
The syntax is pretty much identical to C++, so don't worry that it mentions Java there.

3) Answers below:

i) Base case: Down to one (you can go up to n as well but down to one is easier)
   
   Recursive case: Add current position squared plus the next term squared.
   
   Error-Check: That the input is greater than 0 (and is an integer).

ii) Iterative Solution:
```C++
  int iter_sum(int n)
  {
    int sum = 0;
    
    //Remember to include 'n' and start at 1, due to how the summation is defined in the problem
    for(int x = 1; x <= n; ++i)
    {
      sum += (x*x);
    }
    
    return sum;
  }
```

iii) Recursive Solution:
```C++
  int recur_sum(int n)
  {
    if(n == 1)
    {
      return 1; //1^2 == 1
    }
    else
    {
      return (n*n) + recur_sum(n-1);
    }
  }
```

iv) Diagrams:

Iterative psuedo-code (which is pretty much the above solution) below: 
```
  Set an integer sum (to accumulate the summation)
  Set an integer x   (to increment position)
  
  For n amount of times
    Set sum equal to itself plus x times x
    Increment x
```

Recursive:
```
  recur_sum(4)
     |
     --> (4*4) + recur_sum(3)
                    |
                    --> (3*3) + recur_sum(2)
                                   |
                                   --> (2*2) + recur_sum(1)
                                                  |
                                                  --> 1
```

After each call is made (up to the end), the program trails back up to evaluate 
the previous function call. In other words: In order to know `recur_sum(4)`, it needs to know 
`recur_sum(3)`. To know `recur_sum(3)`, the program must know `recur_sum(2)`. When 
`recur_sum(1)` is reached, the function returns 1. The rest get evaluated backwards from 
then-on.

4) Answers below:

i) Base case: n == 0 OR n == 1 (where 1! and 0! are both 1)
   
   Recursive case: n times the next factorial
   
   Error-Check: n is greater than 0 (and is an integer)

ii) Iterative Solution:
```C++
  int iter_fact(int n)
  {
    //By setting this to 1 we can ignore the 0! and 1! cases later
    int fact = 1;
    
    //Unnecessary to do 1! or 0!, thus condition changed to "i > 1"
    for(int i = n; i > 1; ++i)
    {
      fact*=i;
    }
    
    return fact;
  }
```

iii) Recursive Solution:
```C++
  int recur_fact(int n)
  {
    if(n == 1 || n == 0)
    {
      return 1;
    }
    else
    {
      return n * recur_fact(n-1);
    }
  }
```

iv) Diagrams:

Iterative solution diagram found [here](http://www.avrams.ro/imgs/clip_image002_0004.jpg).

Recursive diagram found [here](http://flylib.com/books/2/254/1/html/2/images/15fig02.jpg). 

The main idea in the recursive solution is to understand that each function call doesn't get resolved 
until its following call is resolved (e.g. you can't solve `fact(3)` without getting to `fact(2)` first).

5) Answers below:

i) Base case: f1 == 1, f0 == 0

   Recursive case: Current term equals two previous terms
   
   Error-Check: n >= 0 (where n is an integer)

ii) Iterative Solution: 
```C++
  int iter_fib(int n)
  {
    int fn = 0,  //term we want
        f1 = 1,  //previous, n-1, term
        f2 = 0;  //n-2 term
    
    for(int i = 0; i < n; ++i)
    {
      fn = f1 + f2; //set fn to the sum if its two previous terms
      f2 = f1;      //set n-2 term to n-1 term
      f1 = fn;      //set n-1 term to n term
    }
    
    return fn;
  }
```

iii) Recursive Solution:
```C++
  int recur_fib(int n)
  {
    if(n == 0)
    {
      return 0;
    }
    else if(n == 1)
    {
      return 1;
    }
    else
    {
      return fib(n-1) + fib(n-2);
    }
  }
```

iv) Diagrams:

Iterative psuedo-code (which is pretty much the above solution) below:
```
  Set an integer fn equal to 0 (as nth term)
  Set an integer f1 equal to 1 (represents 1st term)
  Set an integer f2 equal to 0 (represents 0th term)
  
  For n amount of times
    Set fn equal to two previous terms
    Set n-2 term equal to n-1 term
    Set n-1 term equal to the nth term
```

Recursive one (except it's for F5) found 
[here](http://www.computersciencesalaryrange.com/wp-content/uploads/2014/02/recursive-fibonacci.png). 
If you want it for other Fibonacci values, just split it up like the tree diagram does (same idea).

Note that, by the number of function calls, the recursive solution is much slower for bigger n-values 
than the iterative one (and more prone to stack overflow errors). There's a way to fix this, which is 
called [memoisation](http://www.cse.unsw.edu.au/~billw/dictionaries/prolog/memoisation.html), if you're 
interested.

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>