# General IO

## Contents
- [Intro](#intro)
- [Topics](#topics)
  - [Console IO](#console-io)
    - [Input: cin](#input-cin)
      - [Console Input Basics](#console-input-basics)
      - [fail](#fail)
    - [Output: cout](#output-cout)
      - [Console Output Basics](#console-output-basics)
      - [iomanip](#iomanip)
  - [File IO](#file-io)
    - [Binary File IO](#binary-file-io)
    - [Text File IO](#text-file-io)
  
### Intro
This page serves to refresh (and to some extent teach) how IO (input/output) works and can be used in C++.

These pages can help too if you prefer using another site:
- http://www.cplusplus.com/doc/tutorial/basic_io/

### Topics
Below is information on working with text documents and binary files for input/output in C++.

I won't go too in-depth with these topics, and will only include information that I believe requires refreshment or 
is new (and useful).

#### Console IO
You need to know how to use `cin` and `cout`. That's non-negotiable.

##### Input: cin
`cin`, or console input, helps read information given by the console input stream.

###### Console Input Basics
For what we're mostly concerned with, there are two ways to get input from the console: `cin >> ...` and `getline`

`cin >> ...`:
By means of the extraction operator, we can grab input all the way until a [whitespace character](http://www.cplusplus.com/reference/cwctype/iswspace/) is reached. 
This of course can be changed, but I won't go over that (search information on `cin` if you're interested on learning about `noskipws` and `skipws`).

`getline`:
Simply put: It grabs the entire line and puts it into the second argument.

Format of `getline` is as follows:
```C++
  getline(input_stream_variable, string);
```

The arguments can be changed. More information on that [here](http://www.cplusplus.com/reference/string/string/getline/).

Apart from that, not much else to mention. For more information, check [here](http://www.cplusplus.com/doc/tutorial/basic_io/) and look at "Standard input (cin)"
and "cin and strings". `stringstream` is useful, although it won't be used that much in this course (or CPSC 131 for that matter).

###### fail
One question a lot of people have is "How do I recover from erroneous input, such as inputting a string when there's supposed to be an integer?".

Best way to do that (if you're using the extraction operator) is by using `cin.fail()`. The (typical) order of operation is as follows:
1. Get user input
2. If cin.fail()
  a. Fix the input stream (i.e. call `cin.clear()`)
  b. Clear the buffer with `cin.ignore(std::numeric_limits<int>::max(), '\n')`)
  c. Alert the user that an error has occurred when trying to grab their input
3. Else, proceed as normal (or add other conditional checks here)

Note that with `ignore` you don't really need to have the `numeric_limits<int>::max()` part. A big number like `1000` works perfectly fine, 
assuming the user does not type more than 1000 characters in the input stream (`numeric_limits` just ensures that you skip all input on the line 
until you hit a new line, or `\n`).

One example of applying this method:
```C++
  bool valid_input = false; //assume false at start to remove unnecessary assignments in do-while loop
  char input = '\0';        //default initialization
  
  do
  {
    cout << "Enter in a letter: ";
    cin >> input;                              //Grab user input and throw it into the char 'input'
    
    if(cin.fail())                             //if there was an error, step 2
    {
      cin.clear();                             //clear stream, step 2a
      cin.ignore(1000, '\n');                  //ignore 1000 characters or until delimiter '\n' is reached, step 2b
      cout << "Invalid input.\n";              //provide error message, step 2c
    }
    else if (!isalpha(input))                  //if the input is not an alphabetical letter
    {
      cout << "Did not enter in a letter.\n";  //Error message
      cin.ignore(1000, '\n');                  //ignore rest of stream (if there is anything else before the new line)
    }
    else
    {
      valid_input = true;                      //set valid_input to true (to get out of loop)
    }
  }while(!valid_input);                        //while valid_input is false. Same as "valid_input != true"
```

Note that the above example does not check for cases such as "g 1231hjvk55dzg". It checks only the first string of characters until it hits a new space.

More information here: http://www.cplusplus.com/forum/beginner/2957/

##### Output: cout
`cout`, or console output, helps output information to the console via the console output stream.

###### Console Output Basics
There isn't much to talk about here. Just remember to use `cout << ...` to print stuff onto the console screen.

For more information, check [here](http://www.cplusplus.com/doc/tutorial/basic_io/) and look at "Standard output (cout)".

###### iomanip
Ever wonder how certain console programs get their outputs to look all neat? `iomanip` is one answer.

I'd rather not talk about `iomanip` here (or else this page will become bigger than it has to be), so check out the following links for 
more information:
- http://www.cprogramming.com/tutorial/iomanip.html - teaches how to use iomanip
- http://www.cplusplus.com/reference/iomanip/ - technical information (with examples)
- http://msdn.microsoft.com/en-us/library/ydd54a6t.aspx - technical information; assumes you have a general understanding beforehand

#### File IO
Although binary file IO typically isn't required for CS121, the professors expect you to know about it for the CPSC 301 test. It's good 
to know, although if you're really worried about remembering all the material then put more of an emphasis on text file IO.

These pages can help too if you prefer using another site:
- http://www.cplusplus.com/doc/tutorial/files/
- http://www.cprogramming.com/tutorial/lesson10.html
- http://www.learncpp.com/cpp-tutorial/136-basic-file-io/

##### Binary File IO
This isn't heavily focused on in CPSC 121 (or 131 for that matter), but still interesting to learn. Pay more attention to the text file IO section.

When working with binary files, TBD

##### Text File IO
When I say "text file", I'm talking about files such as `.txt` and source files like `.cpp`. They're files you can open in notepad without issues of seeing 
crazy text (for instance, try opening an image using a text editing program).

Working with text files is fairly easy. After including the required library or libraries, the steps are as follows:
1. Open the file
2. Check if it is open and if so...
  a. Do whatever you need
  b. Close the file
3. If the file was not successfully opened, produce an error warning

These steps can be easily translated to C++ (using a do-while loop to prove full usefulness):
```C++
  TBD
```

if you only plan on outputting (writing) to a file, use 

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>