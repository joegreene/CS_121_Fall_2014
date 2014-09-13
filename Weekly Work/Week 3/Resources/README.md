# Week 3 Solutions

## Sections
- [iomanip-question](#iomanip-question)
- [Miscellaneous Questions](#miscellaneous-questions)
  - [Question 1](#question-1)
  - [Question 2](#question-2)
  - [Question 3](#question-3)
  - [Question 4](#question-4)


### Iomanip Question
NOTE: I have included a testable piece of code for this solution (using the bonus version). It's under the "iomanip example" folder 
on this page (at top).

If we have `ITEM_CAP` amount of items, the code to print all contents of the array is as follows:
```C++
  //To make life easier, set the widths of each column as constant integers (values are just a rough guess)
  const int ITEM_NAME_WIDTH = 10; //this includes the item name length and the spaces between ITEMS and PRICES
  const int PRICE_WIDTH = 7;      //how long we think the prices will be at maximum
  
  //Print the header; NOTE: setfill is ' ' on default and make sure to make it left-justified (sets everything else as left)
  cout << left << setw(ITEM_NAME_WIDTH) << "ITEMS" << "PRICES" << endl; //the number is just a guess on 
  
  //NOTE: setw doesn't work unless you print a character. I chose '-' and subtracted a dash from setw to compensate
  cout << setfill('-') << setw(ITEM_NAME_WIDTH + PRICE_WIDTH - 1) << "-" << endl; //set the dashes length to cover both item names and prices
  
  //Reset setfill for printing each name and price, and setprecision (using fixed notation to round from the decimal place)
  cout << setfill(' ') << fixed << setprecision(2);
  
  //Loop through the list until you print the last item
  for(int i = 0; i < item_count; ++i)
  {
    //print the name (setw covers spaces inbetween), dollar sign, then price (and endl after)
    cout << setw(ITEM_NAME_WIDTH) << name_list[i] << "$" << price_list[i] << endl;
  }
```

The `ITEM_NAME_WIDTH` and `PRICE_WIDTH` variables weren't required (we could've plugged in numbers manually). I'm just showing you a better way 
of doing it. Using `ITEM_NAME_WIDTH` and `PRICE_WIDTH` make it so you don't have to edit more lines than necessary (if you ever need to change 
their sizes later on).

__BONUS__:
If we have `item_count` amount of items (and `ITEM_CAP` is the maximum size of our array), the loop 
may be tweaked as follows (rest of the code stays the same):
```C++
  for(int i = 0; i < item_count; ++i) //change the boundary in which we loop in (ITEM_CAP -> item_count)
  {
    //exact same code
  }
```

Note that `item_count` may not exceed `ITEM_CAP` (or else we'd have an overflowing array, i.e., we'd have more 
elements in the array than the array can support).

The above is used a lot in this class (or I had to use it a lot at least), so be sure to be comfortable on 
the flow of the above code segments, especially the second code segment.

### Miscellaneous Questions
Below are the solutions to the miscellaneous question section.

#### Question 1
First one uses integer division, which prints out 2. Second one uses floating-point division and prints out 2.8.

This refers to type-casting and was similar to question 6 on last week's handout. Head over to week 2's folder and find out information 
about the solution there. Focus on the `static_cast` portion.

#### Question 2
There might be other reasons, but the typical two are:
1. It's easier to notice what is a constant variable versus what is a typical (dynamic and otherwise able to change) variable. 
2. It's the standard way of making constant variables, and going away from the standard makes your code harder for others to read

#### Question 3
Three reasons:
1. If you plan on looking at it later, you'll be able to understand what you typed
2. If others plan on helping you out or are reviewing it, they'll have a better chance of understanding what you typed
3. Typing out variables and specific statements (e.g. if/else or switch) will be easier to work with and trace logically

Good thing to do is think about how you would feel when looking at your code a year later. Would you be able to understand what you typed?

#### Question 4
__TIP__: When in doubt of when each arithmetic operation will occur (e.g. if `+` has higher precedence than `*`), use parentheses to make sure your equations work.

__NOTE__: We're assuming each variable used is a double. The `cmath` functions `pow` and `sqrt` wouldn't work otherwise (they take floating-point values, not integers).

Solutions:
```C++
  //First
  fx = m*x + b;
  
  //Second
  fx = (y - y0)/(x - x0);
  
  //Third; .5 is the same as 1.0/2 or 1/2.0 (NOT 1/2 BECAUSE 1/2 RETURNS 0)
  fx = x0 + v0 * t + .5 * ax * pow(t, 2.0);
  
  //Fourth
  fx = sqrt(pow(v0, 2.0) + 2 * ax * (x - x0));
```

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>