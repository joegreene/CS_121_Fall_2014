# Week 12 Notes - Wednesday

## Sections
- [Intro](#intro)
  - [Notes](#notes)
    - [Algorithm Analysis](#algorithm-analysis)
    
### Intro
Below are the notes from the Wednesday (11/12) SI session.

#### Notes
We worked on this week's worksheet and talked about Monday's lecture. Overall, it was reviewing the search and 
sort algorithms we discussed, and a bit on Big-O notation.

Although it's crucial to know during 131, Big-O notation isn't heavily focused on in 121. If you're concerned about 
what material you should focus on most, stick to understanding classes, pointers, and the general process of each 
sorting and searching algorithm we've discussed. There are only four in total, and if you understand then visually 
then their psuedo-code becomes quite simple:
- Bubble Sort
- Selection Sort
- Sequential/Linear Search
- Binary Search

Topics discussed during the session:
- Algorithm Analysis

##### Algorithm Analysis
Since a lot of this is best learned visually, we drew images on the board to 
understand what was going on each step.

Keep mind that we've talked about two categories of algorithms: __Sort__ and __Search__ algorithms (their names mean 
exactly what they are meant to do).

Here are summaries on how the sorting algorithms we talked about work:
- __Bubble Sort__: Swap values (current with next) until we get the order we require (i.e. when there are no swaps left)
- __Selection Sort__: There are two halves - Sorted and unsorted. Start with the first index, find the minimum/maximum 
value needed, swap it with the first position, move to the second position, find min/max, swap with second, rinse and repeat.

Summaries on how the searching algorithms we've talked about work:
- __Sequential/Linear Search__: Starting from the front, check each position sequentially until value is found (you guys used 
this one 
- __Binary Search__: The general idea is to cut the list in half until we find our value. If the middle value is not the 
value we need, check the left half of the data if our needed value is less than middle (else check right-half). Keep in mind 
that to use binary search the list __must be in order__.

If you're having issues understanding the process of each algorithm (and Big-O notation), the below links might be able to 
help you out:

Big-O Notation:
- Big-O Notation: http://rob-bell.net/2009/06/a-beginners-guide-to-big-o-notation/

Sorting Algorithm Work:
- Cplusplus on Bubble Sort: http://www.cplusplus.com/faq/sequences/sequencing/sort-algorithms/bubble-sort/
- Cplusplus on Selection Sort: http://www.cplusplus.com/faq/sequences/sequencing/sort-algorithms/selection-sort/
- Alternate Site on Bubble Sort: http://mathbits.com/MathBits/CompSci/Arrays/Bubble.htm
- Alternate Site on Selection Sort: http://cforbeginners.com/ssort.html

- Program to see how fast each sorting algorithm can run: http://panthema.net/2013/sound-of-sorting/

Binary Search (and linear search is shown in the video):
- Video on Binary Search: http://www.youtube.com/watch?v=JQhciTuD3E8

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>