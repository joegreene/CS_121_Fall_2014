# Week 4

## Contents
- [Intro](#intro)
- [Topics](#topics)
  - [Wednesday](#wednesday)
  - [Friday](#friday)
  
### Intro
This hosts the activities we worked on during the SI class on 9/17/14 and 9/19/14.

### Topics
The worksheet for this week covers nested for loops, text file input/output, and a little 
bit on two-dimensional arrays, counters (e.g. to increment through an array), and 

#### Wednesday
Passed out the worksheet, however we did not go over the worksheet too much in detail.

Majority of the session was going over psuedo-code practice, understanding switch 
cases more, understanding the concept of cascading/falling-through switch cases, and 
reading/outputting an array of lines from an input file. 

For psuedo-code practice, we tried translating the following C++ code to psuedo-code:
```C++
  //Section 1: For loops
  const int LENGTH;
  int list[LENGTH];
  
  for(int i = 0; i < LENGTH; ++i)
  {
    cout << list[i] << endl;
  }
  
  //Section 2: switch cases
  int x;
  cin >> x;
  
  switch(x)
  {
    case 0:
      cout << "X is zero\n";
      break;
    case 1:
    case 2:
      cout << "X is one or two\n";
      break;
    //...etc.
  }
  
```

Although with every professor and class the requirements on psuedo-code vary, normally 
you should be following the three rules below:
1. Make your psuedo-code actually describe what you are doing
2. Make your psuedo-code clear, concise, and direct on what you want to do
3. Make your psuedo-code cater to an audience more than just yourself

It takes practice, but neat psuedo-code helps in the long run. You can easily 
translate ideas from C++ to another language, explain to others that do not know 
C++ how your programs work, and may actually make you rethink of how your program should 
be laid out (for the better). Also, keep in mind that psuedo-code != comments in code.
Psuedo-code is meant to help describe the components of a program, whereas comments are 
merely meant to describe difficult parts in a program.

We came up with the following C++ to psuedo-code translation below:
```
  //Section 1: For loops
  Create a constant integer, LENGTH
  Create an integer array, list, of size LENGTH
  
  For each position in the array
    Print out each element in the array to console
    
  //Section 2: switch cases
  Create an integer, x
  Grab a value from console and place it into x
  
  Test the value of x with the following cases:
    If x is 0, print "X is zero" to console and break out of the test
    If x is 1 or 2, print "X is one or two" to console and break out of the test
    ...
```

The above isn't the "only way" to write the psuedo-code. It's just what we all agreed 
seemed clear enough to describe what we were programming.

For cascading/falling-through switch cases, we tested the following code:
```C++
  char grade = 'b';
  switch(grade)
  {
    case 'b':
    case 'A':
      cout << "Great grade!\n";
      break;
    case 'B':
      cout << "Pretty good grade.\n";
      break;
    //..etc code if you want
    default:
      cout << "Unknown grade\n";
  }
```
We didn't discuss what would happen, and left it as a self-practice practice. In other 
words: Try the above code out in Visual Studio, and see what happens.

For grabbing input from a file and outputting it to console: Test the following code out 
in Visual Studio and try to make sense of each line.
```C++
  #include <iostream>
  #include <fstream> //file-stream library (for ofstream/ifstream)
  #include <string>
  
  using namespace std;
  
  int main()
  {
    //True line count (we can have a partially-filled array)
    int lines_in_array = 0;
    
    //Cap on number of lines available to grab (arbitrary)
    const int MAX_LINES = 7;
    
    //Array of strings we wish to fill
    string input[MAX_LINES];
    
    //Create the object for reading a file
    ifstream infile;
    
    //(Attempt to) open "example.txt" using infile
    infile.open("example.txt");
    
    //If the file successfully opened
    if(infile.is_open())
    {
      //while we can still get data AND we haven't exceeded MAX_LINES
      while(infile.good() && lines_in_array < MAX_LINES) 
      {
        //Read line from infile and plug it into the current position of input
        getline(infile, input[lines_in_array]);
        
        //Increment true line count
        ++lines_in_array;
      }
      
      //Close the file (IMPORTANT; WE DON'T WANT A HANGING FILE)
      infile.close();
      
      //Print out each element of array input
      for(int i = 0; i < lines_in_array; ++i)
      {
        cout << input[i] << endl;
      }
    }
    else //give an error message stating the file could not be opened
    {
      cout << "Error when trying to open file!\n";
    }
    
    //Lazy way to pause a program on a Windows Operating System
    system("pause");
    
    return 0;
  }
```

To test the above code: 
1. Type the above out in a Visual Studio solution. 
2. Go to the directory wherever your source code is located (e.g. `"C:\Users\Joe\Documents\Visual Studio 2010\Projects\text_io\text_io\"`
is what I would have on my Windows 7 computer)
3. Create a new text document and name it `example.txt` (if you have extensions hidden, there's no need to include `.txt`)
4. Put random gibberish on each line (have at least three lines), save, and close the text document.
5. Go back to Visual Studio, compile your program, and see your results

Alternatively, trace the program by hand. Tracing the program by hand will help better understand 
the flow of the program (especially in the while loop portion).

Although the code was slightly different than what we talked about in the SI session, I wanted 
to include support for partially-filled arrays (i.e. if we did not have at least NUM_LINES amount 
of lines in our text file). Having this kind of support is especially important when dealing with 
file input. We do not always know how much data is within the files we read in (which implies that 
a `while` loop works better than a `for` loop in most cases).

#### Friday
TBA

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>