# Week 12 Solutions

## Sections
- [Intro](#intro)
- [Worksheet](#worksheet)
  - [Questions](#questions)
    - [Algorithm Analysis Practice](#algorithm-analysis-practice)
    
### Intro
This page hosts the solutions to the questions for this week's worksheet. 

The worksheet itself is located in its usual place (in the file listing above).

__NOTE__: The solutions for questions 2, 3, 4, and 6 are in the file directory on 
this page. They are high-resolution, so if something seems blurry chances are zooming-in 
will fix that for you. If they are unclear, please let me know.

### Worksheet
Below is the worksheet solutions for this week.

#### Questions
Grab the questions from the worksheet document.

##### Algorithm Analysis Practice
1) Answers below (keep in mind that Big-O notation generalizes the step-count):
`main`:
```
  We treat function calls, assignments, declarations as basic steps.
  Therefore, treat main as an O(1) (constant time) function.
```

`init_num_list`:
```
  Although assignments are considered basic steps, the number of steps taken 
  is proportional to the length of the array passed through the function.
  
  Therefore, we treat init_num_list as an O(n) (linear time) function.
```

`print_list`:
```
  The for-loop runs proportionally to the size of the list.
  
  Therefore, we treat `print_list` as an O(n) (linear time) function.
```

`ascend_bubble_sort`:
```
  Working with the inside first:
  1. For each iteration of the inside loop, in the worst possible case we would 
  have to call the if-statement and its body: 3 basic steps per iteration
  2. The inside loop runs n-1 times (where n is the size of the list): n-1 steps 
  to run the inside (which generalizes to n steps)
  3. We now can say that the inner loop runs O(3n) which generalizes to O(n) (linear time)
  
  Outer loop:
  1. Worst case is to loop through the entire list, so we run the inner loop `n` amount of 
  times (meaning n * n)
  
  
  Therefore, we treat the function `ascend_bubble_sort` as an O(n^2) (squared time) function.
```

`swap`:
```
  A declaration and assignment are being made (nothing too complicated).
  Total count is 3 steps and is unaffected by inputs.
  
  Therefore, we treat `swap` as an O(1) (constant time) function.
```

2) Check the image labelled `solution_Q2_wk12.jpg` in the file directory near the top of this page.

3) Check the image labelled `solution_Q3_wk12.jpg` in the file directory near the top of this page.

4) Check the image labelled `solution_Q4_wk12.jpg` in the file directory near the top of this page.

5) Not possible to run binary search algorithm on current list (list must be in an 
order in which you can determine smaller/larger halves)

6) Check the image labelled `solution_Q6_wk12.jpg` in the file directory near the top of this page.

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>