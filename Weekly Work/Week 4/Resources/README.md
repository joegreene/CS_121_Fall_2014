# Week 4 Solutions

## Sections
- [Intro](#intro)
- [Questions](#questions)
  - [Nested For Loops](#nested-for-loops)
  - [File IO](#file-io)

### Intro
As usual, the worksheet is the .docx file located near the top of this page. If you need it in another format (i.e. you do not 
have Microsoft Word or a suitable viewer for the file), send me an email or ask someone for a printout.

The worksheet might seem beefy, however that's because majority of it is explaining concepts. Although you might have done 
it in CS 120 or a similar course: Please take a look and try out the first section of the worksheet. The main focus of it 
is to practice tracing programs, which is essential if you are ever going to get anything done in this class. Plus, you 
might be surprised on how much you've actually retained from working with nested for loops.

__NOTE__: If you absolutely can't put the time into working with the shape-printing section, do the very last part of it. It's 
the most crucial part of the worksheet (you'll be using it a lot when working with two-dimensional arrays). Afterwards, review the 
File IO section.

### Questions
I didn't really label questions throughout the sheet, however there were sections required to plug in information.
There are many possible answers for most of the sections, however later on I will include what I believe are easy-to-read 
solutions.

#### Nested For Loops
The best thing you can do for yourself is see what happens when you try to compile this code. Try 
testing this stuff out in Visual Studio to really understand it. Fool around with the conditions, 
the variables used, and the loops to get an idea of what's going on.

__NOTE__: There are many ways you can write solutions to the following problems. I've just listed my own solutions, as 
a reference.

__PART__:
```
  What would happen if we instead tried changing COL/ROW to another value?
```

__SOLUTION__:
```
  Changing COL will affect the number of columns printed out. The width would increase/decrease.
  
  Changing ROW will affect the number of rows printed out. The length would increase/decrease.
  
  It looks sloppy, but below is a reference to what I meant by width/length:
  
   WIDTH
  ******** L
  ******** E
  ******** N
  ******** G
  ******** T
  ******** H
```

__PART__:
```
  Edit the above code so the corner is in a) the top left and b) The top right. 
```

__SOLUTION__:
```C++
  //Part a
  for(r = BASE; r > 0; --r)
  {
    for (c = 0; c < r; ++c)
    {
      cout << "*";
    }
    cout << endl;
  }
  
  //Part b
  for(r = 0; r < BASE; ++r)
  {
    //Print spaces equal to the row
    for(c = 0; c < r; ++c)
    {
      cout << " ";
    }
    
    //Print the stars to fill the rest
    for(c = r; c < BASE; ++c)
    {
      cout << "*";
    }
    
    cout << endl;
  }
```

Here's how I solved the second one (once again, there are many ways but this is what I did):

1. Aligned the output into a grid
| - | 0 | 1 | 2 |
| :---: | :---: | :---: | :---: |
| 0 | "*" | "*" | "*" |
| 1 | " " | "*" | "*" |
| 2 | " " | " " | "*" |

2. Noted the following patterns:
```
  Row 0 has no spaces
  Row 1 has one space
  Row 2 has two spaces
  
  The rest of the line (after spaces are put in) is filled with stars.
  
  From here, we can say:
    For each row
      Print out row amount of spaces
      Print out stars for the rest of the line (from r to BASE)
```

3. Collected thoughts, wrote the psuedo-code, and afterwards translated it to C++:
```
  Starting at r equals 0 to BASE, do the following:
    Starting from integer i = 0 to r
      Print a space per iteration
    Starting from c = r to BASE
      Print a star per iteration
```

__PART__:
```
  Try to solve the other one, which should only require two loops (an outer loop and an inner loop):
```

__SOLUTION__:
```C++
  for(r = 0; r < side; ++r)
  {
    for(c = 0; c < (r + side); ++c)
    {
      if((r+c) >= (side - 1))
      {
        cout << "*";
      }
      else
      {
        cout << " ";
      }
    }
    cout << endl;
  }
```

Solving the above problem was like the top-right triangle: Treat the output as a grid.
| - | 0 | 1 | 2 | 3 | 4 |
| :---: | :---: | :---: | :---: | :---: | :---: |
| 0 | " " | " " | "*" | " " | " " |
| 1 | " " | "*" | "*" | "*" | " " |
| 2 | "*" | "*" | "*" | "*" | "*" |

Made the following observations:
```
  Row one (0) has two spaces on the left side (ignore the right side)
  Row two (1) has one space on the left (ignore the right side)
  
  Spaces are printed at [0][0], [0][1], [1][0] (ignore the right side spaces)
  At each of those places, when adding the row and column:
    r0 + c0 = 0, r0 + c1 = 1, and r1 + c0 = 1
  
  Stars are printed at [0][2], [1][1], [1][2], [1][3], [2][0], [2][1], [2][2], [2][3], and [2][4]
  At each of these places, when adding the row and column:
    r0 + c2 = 2, r1 + c1 = 2, r1 + c2 = 3, r1 + c3 = 4, r2 + c0 = 2, 
    r2 + c1 = 3, r2 + c2 = 4, r2 + c3 = 5, and all the bottom rows and columns added are two or greater.
  
  As we know that side is equal to 3, all our prints happen when r + c >= 2, and base - 1 = 2, then we have the following:
    If row and column are greater than or equal to base minus one, print a star. Else, print a space.
    (meaning if((r+c) >= (side - 1) and so on)
```

There are always other ways to go about this, however this one made the most sense to me. It took me 
quite a bit to come up with a solution too, so don't be discouraged if you're not understanding these 
quickly. If you came up with your own solution and it works, nice job.

__PART__ (The most important):
```
  Write a code segment to print out the contents of grid.
```

__SOLUTION__:
```C++
  //Using given code
  for(int r = 0; r < ROW; ++r)
  {
    for(int c = 0; c < COL; ++c)
    {
      //Access each position, row by column, and print a space for cleanliness
      cout << grid[r][c] << " ";
    }
    
    //endl when done with row
    cout << endl;
  }
```

#### File IO
PART:
```
  Try to make sense of what the following code segments are doing. Write comments.
```

SOLUTION:
```C++
  if(infile.is_open()) //if the file is open
  {
    while(infile>>ch) //While it's possible to grab data from infile and plug it into variable ch
    {
      //do whatever
    }
  }
  if(infile.is_open()) //Same as above
  {
    while(getline(infile, str))) //While it's possible to grab data from 
                                 //infile, put a line into string str
    {
      //do whatever
    }
  }

  if(infile.is_open()) //Same as above
  {
    while(infile.good()) //While we haven't reached the end of the file
    {
      getline(infile, str[i]); //Grab a line from infile and plug it into the 
                               //ith position of string array str
      i++; //increment i (to continue through array)
    }
  }

  if(infile.is_open()) //Same as above
  {
    while(infile.good()) //Same as above
    {
      infile>> list[i]; //Grab data from infile and plug it into the ith position 
                        //of the array called list
      ++i; //increment i (to continue through array)
    }
  }
```

__PART__:
```
  Write the code to read from a file and input the values into num_table, and then output it afterwards.
```

__SOLUTION__ (This one is before the worksheet revision):
```C++
  const int ROW = 5;
  const int COL = 5;
  int row_count = 0;
  int column_count = 0;
  int num_table[ROW][COL];
  
  ifstream input_file;
  
  input_file.open("input.txt");
  
  if(input_file.is_open())
  { 
    //Grab from input.txt
    for(row_count = 0; row_count < ROW; ++row_count)
    {
      for(column_count = 0; column_count < COL; ++column_count)
      {
        input_file >> num_table[row_count][column_count];
      }
    }
    
    //Close to file (IMPORTANT)
    input_file.close();
    
    //Output to text file (we can only output if we were given input)
    ofstream output_file;
    output_file.open("output.txt");
    
    if(output_file.is_open())
    {
      //Write to output.txt (literally the same minus the write part)
      for(row_count = 0; row_count < ROW; ++row_count)
      {
        for(column_count = 0; column_count < COL; ++column_count)
        {
          //Write to text file (just like cout)
          output_file << num_table[row_count][column_count];
        }
        
        //Skip line (to output correctly)
        output_file << endl;
      }
    }
    
    //Close the file (IMPORTANT)
    output_file.close();
  }
  else
  {
    cout << "Error when reading from input file!\n";
  }
```

__SOLUTION__: (after revision)
```C++
  const int ROW = 5;
  const int COL = 5;
  int row_count = 0;
  int column_count = 0;
  int num_table[ROW][COL];
  
  ifstream input_file;
  
  input_file.open("input.txt");
  
  if(input_file.is_open())
  { 
    //Grab from input.txt
    for(row_count = 0; row_count < ROW; ++row_count)
    {
      for(column_count = 0; column_count < COL; ++column_count)
      {
        input_file >> num_table[row_count][column_count];
      }
    }
    
    input_file.close();
    
    //Output to console (nearly identical to previous part)
    for(row_count = 0; row_count < ROW; ++row_count)
    {
      for(column_count = 0; column_count < COL; ++column_count)
      {
        //Write to file
        cout << num_table[row_count][column_count];
      }
      
      //Skip line (to print correctly)
      cout << endl;
    }
  }
  else
  {
    cout << "Error when reading from input file!\n";
  }
```

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>