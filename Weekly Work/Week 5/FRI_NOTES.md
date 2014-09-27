# Week 5 Notes - Friday

## Sections
- [Intro](#intro)
  - [Notes](#notes)
    - [Maximum and Minimum of an Array](#maximum-and-minimum-of-an-array)
    - [Boolean Flags](#boolean-flags)
    - [Structure of Psuedo-Code](#structure-of-psuedo--code)
    - [Array Size Versus Number of Items in Array](#array-size-versus-number-of-items-in-array)
    - [Define an Array Size by Constant Integer](#define-an-array-size-by-constant-integer)
  
### Intro
Below are the notes from the Friday (9/26) SI session.

#### Notes
Half of the session was spent working on questions SI participants had, and the other 
half was spent working on the psuedo-code worksheet supplied above.

A few topics discussed during the session (no particular order):
- Getting the maximum and minimum of an array of integers
- Boolean flags
- Structure of psuedo-code
- Define array size by constant integer
- Array size versus number of items in an array

I was lazy with the order so feel free to jump around to different sections.

##### Maximum and Minimum of an Array
The following is also in the power point notes on Titanium (Chapter 8, slide 28). It was mentioned 
in the email by Professor Anderson today in the morning.

If you would like to find the maximum and minimum of an integer array (or any array 
with numerical values in it really), do the following:
```
  1. Set integers called max and min equal to the first position of the array
  2. From the second element to the end of the integer array
    2a. If the current number is less than min, set min equal to the current element
    2b. If "                   " greater than max, set max equal to the current element
```

The reason we set `max` and `min` both equal to the first position in the array is because this will guarantee that 
we will always get the minimum and maximum in our list (e.g. every value can be equal to the first, etc.). 

Although another way to set up `max` and `min` is to have them equal to, respectively, a really low and really high value (e.g. 
-99999 and 99999), this does not work all the time. What if our list has values that exceed (positively or negatively) these arbitrary 
boundaries? If so, we will have a [logic error](http://en.wikipedia.org/wiki/Logic_error) in our code and therefore we will not have 
[robust](http://programmers.stackexchange.com/questions/104048/what-defines-robust-code) code (which is what we always aim for when programming).

The above psuedo-code can be easily translated to C++:
```C++
  const int LIST_SIZE;     //for array declaration
  int num_list[LIST_SIZE]; //array we're working with
  int num_count;           //variable to determine real number of elements
  
  //initialization for array here, incrementing num_count each time an element is added into the array and 
  //making sure it doesn't exceed LIST_SIZE (or we'd have more items than num_list can hold)
  
  int max, min;            //step 1.
  max = min = num_list[0]; //step 1.
  
  for(int i = 1; i < num_count; ++i) //step 2.
  {
    if(num_list[i] < min) //step 2a.
    {
      min = num_list[i];
    }
    if(num_list[i] > max) //step 2b.
    {
      max = num_list[i];
    }
  }
```

__NOTE__: Notice we did not use an else statement in here. That's because `max` and `min` are independent 
variables (i.e. you can't assume that, if the current element is not a minimum, the current element is a maximum).

__NOTE 2__: If `num_count` doesn't make sense, it's explained more thoroughly under "Array Size Versus Number of Items in Array".

##### Boolean Flags
Boolean flags serve to let your program know when to terminate or go a certain route. In this class, they'll be 
mostly used when you need to find a value or determine validity (e.g. if user or file input was valid).

Although you can check the reference notes page in this repository about working with user input validation 
in References -> General IO or click [here](https://github.com/joegreene/CS_121_Fall_2014/tree/master/References/General%20IO#fail) 
(specifically referring to the variable `valid_input`), what we worked on today was finding a value in an array.

Although what we typed in the SI was slightly different, the below pretty much does the same thing. Only thing I added was the tweak 
to the conditional part:

First, the psuedo-code:
```
  1. Create a boolean called found_match and set it to false
  2. For each element in the array AND while we have not found the item in the array
    2a. If we found a matching item in the array to what we want, set found_match to true to terminate out of the for loop
  3. If we found the item, print out that the item was found. Else, note that the item was not found.
```

We set `found_match` to false because, initially, we have not found the item we want in the list.

For a C++ example:
```C++
  //Assume num_list and num_count were initialized already.
  int num_we_need;          //implied in the psuedo-code but this is the num we're looking for
  bool found_match = false; //step 1 (be a pessimist and assume there will be no match)
  
  for(int i = 0; i < num_count && !found_match; ++i) //step 2
  {
    if(num_we_need == num_list[i]) //step 2a.
    {
      found_match = true; //this will terminate the loop
    }
  }
  
  if(found_match) //step 3
  {
    cout << "Found a match!";
  }
  else //step 3
  {
    cout << "Match not found.";
  }
```

__NOTE__: Remember that the middle part of a `for` loop is a conditional statement. We can add whatever we want to it (as long as it can return a true/false value). 

__TRIVIA__: `for` loops are a shorthand version of `while` loops.

__NOTE 2__: If you want to print which position you found the match in, keep track of the index (e.g. have an integer to track what `i` is when a match was found).

##### Structure of Psuedo-Code
With this, there's really only one rule you need to follow: Make sure your psuedo-code explains __clearly__ what you're doing in a __stepwise manner__.

As a personal thing I like to both number and add subscript (e.g. `2.` and `2a.`). Also, I like to indent when I want to specify that there are 
sub-steps (e.g. in the examples above). Helps me and, from what I've been told, helps others understand what I'm talking about.

##### Array Size Versus Number of Items in Array
__Q__: Why is the following code going to give erroneous results?
```C++
  const int LIST_SIZE = 4;
  string str_list[LIST_SIZE];
  
  str_list[0] = "First element.";
  str_list[1] = "Second element.";
  
  for(int i = 0; i < LIST_SIZE; ++i)
  {
    cout << str_list[i] << endl;
  }
```

If you don't notice it immediately: Try tracing the program by hand. How many items are in `str_list`? What will the output of the code segment be?

__A__: This is because we're trying to print every element (including uninitialized ones) in a __partially filled__ array.

Visually, before the code is ran, our array looks like the following:
```
num_list = [ "First element" ][ "Second element" ][ \0 ][ \0 ]
                    0                   1            2     3
```

The first and second element we initialized, and `\0` is the NULL character. You might remember it from the powerpoint notes about c-strings, and is meant 
to note the end of a c-string. C++ has it as the default value for empty positions in a string array. A similar effect happens with integer arrays (except they 
are set to equal 0 and __SHOULD NOT__ be relied on). From my experience, this is a Microsoft Visual Studio-specific thing (i.e. it might not happen in x-code, eclipse, or another IDE). 

__Moral of the story__: Don't rely on default initialization.

__NOTE__: The above is called a [logic error](http://en.wikipedia.org/wiki/Logic_error),that is, the code runs perfectly fine however is not what was intended by the programmer (or at least 
I hope that it was not intended).
        
What I bet you're think now is: How do we fix this? Simple: Use an integer counter to keep track of how many elements we __actually have__.

Above code fixed:
```C++
  const int LIST_SIZE = 4;
  string str_list[LIST_SIZE];
  int str_count = 0; //initially we have 0 elements in the array
  
  str_list[0] = "First element.";
  str_count++; //increment counter each time we add an element to the array
  str_list[1] = "Second element.";
  str_count++; //same as last
  
  for(int i = 0; i < str_count; ++i)
  {
    cout << str_list[i] << endl;
  }
```

Now the code will work as intended: It prints out every element __initialized__ in `str_list`.

__NOTE__: With the array initialization section, we could optionally do:
```C++
  str_list[str_count++] = "First element.";
  str_list[str_count++] = "Second element.";
```

This does the same exact thing, but (at least for me) it, used in large quantity, [obfuscates](http://www.merriam-webster.com/dictionary/obfuscate) your code.

##### Define an Array Size by Constant Integer
Some of you might be wondering: Why are we always using a constant integer to define our array's size?

Out of preference reasons: Saves us time when typing out code, and it makes the value's purpose much clearer.

The above is easily seen when comparing the following two code segments (assume they are full 2d-arrays):

Without a constant integer:
```C++
  int grid[4][3];
  
  for(int r = 0; r < 4; ++r)
  {
    for(int c = 0; c < 3; ++c)
    {
      cin >> grid[r][c];
    }
  }
  
  for(int r = 0; r < 4; ++r)
  {
    for (int c = 0; c < 3; ++c)
    {
      cout << grid[r][c] << " ";
    }
    cout << endl;
  }
```

With constant integer:
```C++
  const int ROW_SIZE = 4;
  const int COL_SIZE = 3;
  int grid[ROW_SIZE][COL_SIZE];
  
  for(int r = 0; r < ROW_SIZE; ++r)
  {
    for(int c = 0; c < COL_SIZE; ++c)
    {
      cin >> grid[r][c];
    }
  }
  
  for(int r = 0; r < ROW_SIZE; ++r)
  {
    for (int c = 0; c < COL_SIZE; ++c)
    {
      cout << grid[r][c] << " ";
    }
    cout << endl;
  }
```

Alright, the above might not be that hard to realize the above code's purpose, however it might be helpful to think of it like this: 
- Assume we have to change the row and column size of `grid`. Without constant integers, we will have to make 6 changes. 
- With constant integers we only need to make two edits. 

Generally speaking: The amount of edits increases with the number of instances of `ROW_SIZE` and `COL_SIZE` you choose to replace them with integer 
literals (e.g. `4` versus `ROW_SIZE`). If working with constant integers, you only need to make as many edits as the number of constant integers you have 
(in the above example, that would be two edits).

__TRIVIA__: Although it's true that we are using four bytes to store a constant integer, the trade-off is next to nothing. We live in a time where memory is abundant, 
so there's no need to worry about that. If we did need to worry about that, you'd be using `float` as opposed to `double`.

If you want to know why we syntactically have to use a constant integer to define an array's size (as opposed to an 
unsigned integer): The compiler requires a positive integer value that's both constant at compile time to work. Statically-made arrays 
(what we're working with right now) can only be made with a constant value, as defined by the C++ language. More information 
[here](http://stackoverflow.com/questions/18919647/declaring-an-array-using-const-integer).

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>