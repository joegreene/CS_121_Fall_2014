# Week 4 Notes - Friday

## Sections
- [Intro](#intro)
  - [Notes](#notes)
  
### Intro
Below are the notes from the Friday (9/19) SI session.

(Copied and pasted from Week 4 main page)
Most of the session was spent discussing questions about the topics listed below:
- Text File Input/Output (namely, how to set up text file IO and how it relates to `cout`/`cin`)
- Post versus Pre Increment/Decrement
- Array Access (using streams to initialize/output elements in an array)

#### Notes
__Text File IO__: 
Although this was talked with the array access part, below is close to what we worked with:
```C++
  const int LENGTH = 4;
  string list[LENGTH];
  ifstream infile;
  infile.open("data.txt");
  
  if(infile.is_open())
  {
    for(int i = 0; i < LENGTH; ++i)
    {
      //Important part; works like "getline(cin,str)"
      getline(infile, list[i]);
    }
  }
  else
  {
    cout << "Error when reading from file.\n";
  }
```

Main part to focus on is the data grab part, or:
```C++
  getline(infile, list[i]);
```

This just combines both the ideas of iterating through an array using a for loop and getline. 
If you understand the following:
```C++
  for(int i = 0; i < LENGTH; ++i)
  {
    getline(cin, list[i]);
  }
```

Treat `cin` as a source you want to grab data from. `infile` acts just like that, except now you're 
grabbing from a file. Comparison of outputting is as follows:

Write each element of list to console:
```C++
  for(int i = 0; i < LENGTH; ++i)
  {
    cout << list[i] << endl;
  }
```

Write each element of list to output file:
```C++
  ofstream outfile;
  outfile.open("output_file.txt");
```

Other than changing the one part, just make sure to do the following steps:
1. Create the ifstream/ofstream
2. Open the file you want to write/read from
3. If the file was opened
  1. Do your read/write tasks
  2. Close the file
4. Else, print to console that an error occurred when trying to read/write to file.

Last notes:
- Make sure you only work with one file at a time (i.e. either read OR write, NOT both 
at the same time)
- Make sure you CLOSE files when you are done with them
- When compiling your code, make sure the .txt files you work with are in the same
location as your source files (.cpp files)
- You can name the identifiers for ofstream/ifstream whatever you want. Just keep in 
mind that the purpose of the identifier is to help you (and others) know what you're 
using the variable for. Example: `ofstream outfile` can be `ofstream infile` if you really 
want, but using `infile` for an `ofstream` object makes no sense.
- Check [here](../joegreene/CS_121_Fall_2014/tree/master/References/General IO#text-file-io) for 
minor help with text file IO as well. Also [here](../joegreene/Spring-2014-CS-Lab--SI-/blob/master/Week%2013/file_io_new.md) 
for my previous semester notes, which are more extensive than the other link.

__Post Versus Pre Increment/Decrement__:

Although rarely are incrementing and decrementing used in `cout` statements, they provide a 
nice way to show how they work.

Looking at the following code, what do you think the output is?
```C++
  int var = 3;
  
  cout << ++var << endl;
  
  cout << var++ << endl;
```

__HINT__: Remember that using `++var` and `var++` is just like saying `var+=1` or `var = var + 1`. The value 
of `var` will change after incrementing/decrementing.

Here's the correct output:
```C++
  4
  4
```

The first one might make sense, but the second one? What the heck is going on there?

The compiler reads the above code as the following:
```
  Create an integer variable named var and set it to 3
  
  First increment var and then output var, then make a new line (end of statement: output is 4 and value of var is 4)
  
  First print out var and then increment var, then make a new line (end of statement: output is 4 and value of var is 5)
```

__WARNING__: Don't try to combine statements such as:
```C++
  cout << var-- << --var << var++ << --var << endl;
```

The compiler will get really funky and print unexpected values per position. I don't remember entirely why this occurs, and 
my best reason is that the Visual Studio C++ compiler is weird on some stuff.


The compiler gets funky with this

__Array Access__:
Access a position in an array by using `[]`.

For example (initialization and printing out to console):
```C++
  const int LENGTH = 3;
  int list[LENGTH];
  
  //Set first position of array to 2
  list[0] = 2;
  
  //Set second position of array to 47
  list[1] = 47;
  
  //Set third position of array to -1
  list[2] = -1;
  
  //Print contents of array to console
  for(int i = 0; i < LENGTH; ++i)
  {
    cout << list[i] << endl;
  }
```

A way to initialize an array through console:
```C++
  for(int i = 0; i < LENGTH; ++i)
  {
    //Initialize each position
    cin >> list[i];
  }
```

Changing this for input/output files is the same technique, except replace cout/cin with some 
object that's type `ifstream`/`ofstream`:
```C++
  const int LENGTH = 4;
  char list[LENGTH];
  ifstream infile;
  infile.open("data.txt");
  
  if(infile.is_open())
  {
    for(int i = 0; i < LENGTH; ++i)
    {
      //Important part; works like "cin >> ..."
      infile >> list[i];
    }
  }
  else
  {
    cout << "Error when reading from file.\n";
  }
```

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>