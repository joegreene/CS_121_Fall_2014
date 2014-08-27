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
You need to know how to use `cin` and `cout`. That's non-negotiable. These require the library `iostream` (input/output stream).

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
  1. Fix the input stream (i.e. call `cin.clear()`)
  2. Clear the buffer with `cin.ignore(std::numeric_limits<int>::max(), '\n')`)
  3. Alert the user that an error has occurred when trying to grab their input
3. Else, proceed as normal (or add other conditional checks here)

Note that with `ignore` you don't really need to have the `numeric_limits<int>::max()` part. A big number like `1000` works perfectly fine, 
assuming the user does not type more than 1000 characters in the input stream (`numeric_limits` just ensures that you skip all input on the line 
until you hit a new line, or `\n`).

One example of applying this method (using a do-while loop to prove full usefulness):
```C++
  bool valid_input = false; //assume false at start to remove unnecessary assignments in do-while loop
  char input = '\0';        //default initialization
  
  do
  {
    cout << "Enter in a letter: ";
    cin >> input;                              //Grab user input and throw it into the char 'input'
    
    if(cin.fail())                             //if there was an error, step 2
    {
      cin.clear();                             //clear stream, step 2i
      cin.ignore(1000, '\n');                  //ignore 1000 characters or until delimiter '\n' is reached, step 2ii
      cout << "Invalid input.\n";              //provide error message, step 2iii
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

I'll include this section later (TBD).

##### Text File IO
When I say "text file", I'm talking about files such as `.txt` and source files like `.cpp`. They're files you can open in notepad without issues of seeing 
crazy text (for instance, try opening an image using a text editing program).

Working with text files is fairly easy. After including the required library or libraries, the steps are as follows:

1. Open the file
2. If file was opened successfully
  1. Do whatever you need
  2. Close the file (possible program hangs or corruption of file if step is skipped)
3. Else (the file was not successfully opened), produce an error message

These steps can be easily translated to C++ in the program below:
```C++
  #include <iostream> //by now you should know what this is
  #include <fstream>  //file stream library
  #include <string>   //library to use strings
  
  using namespace std;
  
  string read_file(string fn);                //custom function that reads files given a file name string
  void write_to_file(string fn, string msg);  //"                  " writes to a file given a file name and message
  
  int main()
  {
    string file_name = "test.txt";            //set up file name for reading from initial file
    string message = read_file(file_name);    //call the read_file function
    
    if(message != "NULL")                     //if read_file didn't produce an error
    {
      string new_file_name = "new_test.txt";  //set up file name for outputting message
      write_to_file(new_file_name, message);  //call the write_to_file function
    }
    
    return 0;
  }

  string read_file(string fn)
  {
    ifstream input_file;            //input file object to be used
    input_file.open(fn.c_str());    //open (argument is a c-string, not string (distinction will be made later)), step 1
    
    string message = "";            //message to write to
    
    if(input_file.is_open())        //if the input file was opened successfully, step 2
    {
      getline(input_file, message); //grab first line of input file, step 2i
      input_file.close();           //close file, step 2ii
    }
    else
    {
      cout << "ERROR: File could not be opened to extract data.\n"; //error message, step 3
      message = "NULL";             //set message to NULL to skip writing to file later on
    }
    
    return message; //return new message to be outputted
  }
  
  void write_to_file(string fn, string msg)
  {
    ofstream output_file;          //output file object to be used
    output_file.open(fn.c_str());  //open (argument is a c-string, not string (distinction will be made later)), step 1
    
    if(output_file.is_open())      //if the output file was successfully opened (or made), step 2
    {
      output_file << msg;          //write string to output file, step 2i
      output_file.close();         //close file, step 2ii
    }
    else
    {
      cout << "ERROR: Issue when writing to file.\n"; //error message, step 3
    }
  }
```

The above is a program that reads the first line of a text file (named "test.txt") and outputs it to another file (named "new_test.txt"), 
all within the executable's directory. On default, if "new_test.txt" does not exist then `ofstream` creates it (otherwise, it overwrites the existing file).

If you don't understand all of the above, that's okay. The most important parts to focus on are the bodies of the two functions `read_file` and `write_to_file`. Forming them into functions 
just makes typing the examples a lot easier for myself. 

Note that, more often than not, it is not required to check if the file is open when outputting to a file. It's a good habit to have, although the only times 
opening a file fails when outputting to a file is when there isn't enough disk space or the destination to write to is unreachable.

If you only plan on outputting (writing) to a file, use the library `ofstream`, and `ifstream` if planning on reading info from a file.

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>