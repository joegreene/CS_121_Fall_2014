# Week 3

## Contents
- [Intro](#intro)
- [Topics](#topics)
  - [Wednesday](#wednesday)
  - [Friday](#friday)
  
### Intro
This hosts the activities we worked on during the SI class on 9/10/14 and 9/12/14.

### Topics
This week the second session (Wednesday from 4-5PM at the ULC) was introduced, so the topic format is slightly different. The worksheet and solutions 
to the Week 3 worksheet are located in the "Resources" folder, using the same format as the previous weeks.

#### Wednesday
Passed out worksheet 3 and worked a bit on it. Also answered a general question about skipping characters in the input stream using `cin.ignore`, 
and grabbing characters using `cin.get`.

#### Friday
Before reading the below: I made a mistake during the session while talking about `numeric_limits`. It should be `numeric_limits<streamsize>::max()`, not 
`numeric_limits<int>::max()` inside of `cin.ignore`. `streamsize` is more specific to the actual size of the input stream.

Went a little bit over each worksheet (there weren't many questions asked) and mostly went over how to design a proper 
error-checking do-while loop. It was explained in detail. Below is the gist of it:

An example of properly grabbing an integer from the input stream:
```C++
  int input;
  bool valid = false; //assume false on start to avoid adding "valid = false" in "if(cin.fail())"
  
  do
  {
    cout << "Enter a number: ";
    cin >> input;
    
    if(cin.fail()) //if there was an error when grabbing input from the input stream
    {
      cout << "Invalid input!\n"; //let the user know an error occurred
      cin.clear();                //clear any error flags that exist, e.g. cin.fail() being true at the moment
      cin.ignore(1000, '\n');     //skip 1000 characters in input stream or until a newline is seen (e.g. when user pressed ENTER)
    }
    else
    {
      valid = true; //user input was a number, therefore was valid
    }
  }while(!valid); //while the input is not valid, loop the above body
```

To better understand this code go and test it out in visual studio. It can be placed either under main or some function.

Major components of the above algorithm (not discussed in lecture yet) that may seem confusing:
- `cin.fail()`: Returns true if there was an issue when grabbing data from the input stream
- `cin.clear()`: Resets any error flags to their default values when called (in our case, we reset `cin.fail()` to `false`.
- `cin.ignore(1000,'\n')`: Ignores either 1000 characters in the input stream or until ENTER was pressed (before the 1000 characters)

__NOTE__: On default, `cin.fail()` is false. If `cin.fail()` is not false when we loop a second time (i.e. if invalid input was read 
beforehand), then all input after is "invalid". This happens when `cin.clear()` is not called after invalid input occurs.

A way to better understand the above note (each is a step): 
1. Have the line `cout << cin.fail() << endl;` after the if/else, one time including and another time removing `cin.clear()` from the code.
2. Try invalid input, then valid input afterwards (e.g. enter `abc` first then `12`).

(For #2) Including `cin.clear()`:
```C++
  if(cin.fail())
  {
    cout << "Invalid input!\n";
    cin.clear();
    cin.ignore(1000,'\n');
  }
  else
  {
    valid = true;
  }
  cout << cin.fail() << endl; //should be 0 in this case; which is good as that's cin.fail()'s default value
```

(For #2) Removing/commenting-out `cin.clear()`:
```C++
  if(cin.fail())
  {
    cout << "Invalid input!\n";
    //cin.clear();
    cin.ignore(1000,'\n');
  }
  else
  {
    valid = true;
  }
  cout << cin.fail() << endl; //should be 1 in this case, which is bad if we loop through a second time
```

Make sure that, in the above code, you type invalid input first (e.g. 'abc') then valid input afterwards (e.g. '12').

We use `1000` in `cin.ignore` because it is a large number. We do not expect users to type in that long of an invalid input, so the number is adequate. 

If you want to write this out "professionally", use `numeric_limits<streamsize>::max()`, which is under the `limits` library.

An example of the above:
```C++
  //other includes
  #include <limits>
  
  //...code...
  
  cin.ignore(std::numeric_limits<streamsize>::max(), '\n'); //skips either 2^31 - 1 characters or until the input stream hits a newline
  
  //...code...
```

More information about `numeric_limits` [here](http://www.cplusplus.com/reference/limits/numeric_limits/) and [here](http://stackoverflow.com/questions/10938363/using-cin-ignore-not-sure-how-to-make-it-work).

__TRIVIA__: Remember, `\n` in this case is called a __delimiter__.

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>