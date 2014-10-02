# Week 5 Solutions

## Sections
- [Intro](#intro)
- [Questions](#questions)

### Intro
This page hosts the solutions to the psuedo-code work (week 5 worksheet).

__NOTE__: I apologize for coming up with poor name choices for the file and string array 
in Program 2. They should be named something like "phrases.txt" and "phrase_list[]" 
respectively. Makes more sense since I'm asking for you guys to read phrases, not just words.

__NOTE 2__: Translated from my psuedo-code to C++, I've included source code files (.cpp) 
to the "Programs" folder (check above). I made the entirety of program 1 but only 
included the palindrome algorithm part for program 2 (I got lazy and think you guys 
have the hang of how the file scanning works now). If you would like me to make a full version 
from my program 2 psuedo-code, email me about it or let me know in class.

### Questions
Note that the below are not the only solutions. As always in computer science, there are 
many routes you may take to come up with a solution. The below are just the solutions I 
found, and might not even be the most efficient of solutions.

Another note: My psuedo-code might look weird to you, but it does the same exact thing: 
Explains the logic and process of the code in English. 

I apologize in advance if I have made any errors. If I did, or something seems confusing, please 
let me know.

__Program 1__:
```
  Libraries used:
  - fstream
  - iostream

  1. Declare the following variables:
    - input file stream infile; To open num_list.txt
    - constant integer MAX_EVENS; To set the size of evens_list (initialize this as 100)
    - integer array evens_list; To record all even numbers found in num_list.txt
    - integer evens_count; To count how many integers received from num_list.txt
                           (initialize this to 0, and it must not exceed MAX_EVENS)
    - integer num; To grab each integer found in num_list.txt
    - boolean all_even; To record whether or not all integers in 
                        num_list.txt are even (initialize this to true)
  2. Open the file using infile
  3. If file was opened successfully
    3a. While num can be set by the file's data AND evens_count is less than MAX_EVENS
      3ai. If num mod 2 is zero, add it to evens_list and increment evens_count. Else, set all_even to false.
    3b. Close the file
    3c. If evens_count is zero, print that there were no even numbers in the file. Else, print every element in evens_list.
      3ci. If all_even is true, print that all numbers grabbed from the text document were even.
  4. If the file could not be opened, print that "num_list.txt" could not be opened/read.
```

__Program 2__ (this one can get rather messy, solely due to the palindrome part):
```
  Libraries used:
  - fstream
  - iostream
  - string

  1. Declare the following variables:
    - input file stream infile; To open word_list.txt
    - constant integer MAX_WORDS; To set the size of word_list (initialize this to 50)
    - string array word_list; To record all the word in word_list.txt
    - integer str_count; To count how many phrases received from word_list.txt
                         (initialize this to 0, and it must not exceed 50)
  2. Open the file using infile
  3. If the file was opened successfully
    3a. While a line in word_list.txt can be put into word_list AND str_count is less than MAX_WORDS
      3ai. Increment str_count
    3b. Close the file
    3c. If str_count is not zero do the following. Else, print that no words were grabbed from the file (implied).
      3ci. Perform palindrome algorithm on each string in word_list (check below)
  4. If the file could not be opened, print that "word_list.txt" could not be opened/read
```

__Palindrome Algorithm__:
```
  1. Declare the following variables:
          - boolean is_palindrome; Flag for whether or not a phrase is a palindrome (initialize as true)
          - string temp; Temporary string for "scrubbing" all spaces from the current phrase
          - character left, right; To check the leftmost and rightmost positions in temp
  2. Set temp equal to the current element in word_list
  3. Erase all spaces from temp
  4. Set left equal to the first character in temp, set right equal to the last character in temp
  5. For half of the length of temp AND while temp can be considered a palindrome
    5a. If left does not equal right, set is_palindrome to false
    5b. Else, set left to the next character (forwards) and right to the character preceding it (backwards)
  6. If is_palindrome is true, print out that the current phrase in word_list is a palindrome. Else, print 
     out that the current phrase in word_list is not a palindrome
```

__NOTE__: Normally you would have the palindrome section all inside the main psuedo-code. I split it up to improve 
readability.

__TRIVIA__: If we were writing this out in a program, a good idea would be to set the palindrome algorithm section 
to be a function (e.g. bool is_palindrome(string str);). This way we have more compact code, improve readability, and 
have an easier time debugging out code (in case any errors occur).

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>