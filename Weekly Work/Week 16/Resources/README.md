# Week 16 Solutions

## Sections
- [Intro](#intro)
- [Worksheet](#worksheet)
  - [Questions](#questions)
    - [Problems](#problems)
    
### Intro
This page hosts the solutions to the questions for this week's worksheet. 

The worksheet itself is located in its usual place (in the file listing above).

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

2) Generally, no. Sometimes they're easier to read, but most of the time they're more trouble than they're 
worth. 

<REST TO BE DONE TODAY, 12/13/14>

The last two are located on [this page](http://www.programcreek.com/2012/10/iteration-vs-recursion-in-java/). 
The syntax is practically identical to C++, so don't worry that it mentions Java there.

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
iv) Diagrams: <TBD>


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

iv) Diagrams: <TBD>


5) Answers below:

i) Base case: f1 == f0 == 1
   Recursive case: Current term equals two previous terms
   Error-Check: n > 0 (where n is an integer)

ii) Iterative Solution: <TBD>

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

iv) Diagrams: <TBD>


-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>