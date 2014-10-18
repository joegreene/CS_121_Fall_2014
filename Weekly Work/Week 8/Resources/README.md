# Week 8 Solutions

## Sections
- [Intro](#intro)
- [Worksheet](#worksheet)
  - [Questions](#questions)

### Intro
This page hosts the solutions to the questions for this week's worksheet. I've added code for the fourth problem 
in the file listing above (named `struct_array_example.cpp` and `struct_vector_example.cpp` respectively).

### Worksheet
Below is the worksheet solutions for this week. As usual, click `CS 121 
Worksheet - Week 8 - Structs.docx` in the file listing above to download 
the worksheet from this week.

__WARNING__: I forgot to include (in the fourth question) that you can choose whether or not 
to get the information from a file or console input. I added this edit to the uploaded worksheet.

__NOTE__: On top of the above, I made some minor edits in the worksheet to make 
some questions more clear. These edits are also already included in the uploaded worksheet.

#### Questions
__1)__ Conversion of real-life objects to structures.
 
__Car__:
Possible characteristics:
```
  - Color of the car
  - Number of wheels
  - Maker name of the car
  - Year of the car
  - etc.
```

Syntax:
```C++
  struct Car
  {
    int num_wheels;
    string color; //can be an integer/enum type which corresponds to a color code, 
                  //e.g. enum{RED, BLUE, GREEN};
    string maker_name;
    int year;
  };
```

__Movie__:
Possible characteristics:
```
  - Title of movie
  - Rating of movie
  - Production cost of movie
  - Release date of the movie
  - etc.
```

Syntax:
```C++
  struct Movie
  {
    string title;
    double rating;
    double prod_cost;
    string rel_date; //this can be improved by using a nested struct, where "Date" is that struct
    //etc.
  };
```

__Custom Object__: (I couldn't think of anything more creative than a Circle)
Possible characteristics:
```
  - Radius
  - Area
  - Circumference
  - Diameter
  - etc.
```

Syntax:
```C++
  struct Circle
  {
    double radius;
    double area;           //you can set area = 3.141592 * radius * radius after (radius is initialized)
    double circumference;  //you can set circumference = 2 * 3.141592 * radius (after radius is initialized)
    double diameter;       //you can set diamater = 2*radius after radius is initialized
    //etc.
  };
```

__2)__ Declaration and Initialization (I chose `Car` for this):
```C++
  //Declare an instance of your chosen struct
  Car some_car;
  
  //Initialize your object
  some_car.num_wheels = 4;
  some_car.color = "SILVER";
  some_car.maker_name = "TOYOTA";
  some_car.year = 2003;
```

__3)__ Function to print out contents of previously-initialized object:

Function declaration:
```C++
  void print_car(const Car& c)
  {
    cout << "CAR DETAILS:" << endl;
    cout << "------------" << endl;
    cout << "Wheel Count: " << some_car.num_wheels << endl;
    cout << "Color: " << some_car.color << endl;
    cout << "Maker Name: " << some_car.maker_name << endl;
    cout << "Year: " << some_car.year << endl;
  }
```

Function call:
```C++
  print_car(some_car);
```

__4)__ Code Segment to Create/Initialize a Vector/Array of Another struct (I chose to do it from console, but using file I/O is similar):

__NOTE__: The below examples use `ignore` because of [this](http://stackoverflow.com/questions/6649852/getline-not-working-properly-what-could-be-the-reasons).

Array:
```C++
  const int LIST_SIZE = 5;
  Movie movie_list[LIST_SIZE]; //array of Movie

  //Initialization loop; Prompt and grab data from console
  for(int i = 0; i < LIST_SIZE; ++i)
  {
    cout << "Enter the movie title: ";
    getline(cin, movie_list[i].title);

    cout << "Enter the movie's rating: ";
    cin >> movie_list[i].rating;

    cout << "Enter the movie's production cost: ";
    cin >> movie_list[i].prod_cost;

    cout << "Enter the movie's release date: ";
    cin >> movie_list[i].rel_date;
    
    //If we plan to mix "getline" and "cin >> ...", we need the following:
    cin.ignore(1); //ignore '\n' since cin ignores whitespace but getline does not, 
                   //meaning '\n' still exists at the end after cin >> m.rel_date is called
  }
```

Vector (you can use a `for` loop for this, but the proper way, using a `do-while` loop, is shown below):
```C++
  //Items required for vector option
  vector<Movie> movie_list; //vector of Movie
  Movie m;                  //temporary variable for pushing back to vector
  bool grab_input = true;   //boolean to track if input should still grab input from console

  //Initialization loop; Prompt and grab data; run loop while asked to grab input
  do
  {
    cout << "Enter the movie title (type 'EXIT' to exit prompt): ";
    getline(cin, m.title);

    if(m.title == "EXIT")
    {
      grab_input = false;
    }
    else //continue loop
    {
      cout << "Enter the movie's rating: ";
      cin >> m.rating;

      cout << "Enter the movie's production cost: ";
      cin >> m.prod_cost;

      cout << "Enter the movie's release date: ";
      cin >> m.rel_date;
    
      //Afterwards, add a CURRENT COPY of m to movie_list
      movie_list.push_back(m);

      //If we plan to mix "getline" and "cin >> ...", we need the following:
      cin.ignore(1); //ignore '\n' since cin ignores whitespace but getline does not, 
                     //meaning '\n' still exists at the end after cin >> m.rel_date is called
    }
  }while(grab_input);
```

__5)__: Sequential Search Practice:
```C++
  bool found = false;   //boolean to mark whether or not we found the num
  int index;            //for saving the first index found of where num is in the vector
  
  vector<int> int_list; //implied that this is declared and initialized
  int num;              //implied code
  cin >> num;           //implied code
  
  //While we haven't reached the end of the list AND have not found num in int_list
  for(int i = 0; i < int_list.size() && !found; ++i)
  {
    //If a match was found, set found to true and initialize index to i
    if(num == int_list[i])
    {
      found = true;
      index = i;
    }
  }
  
  //If found, print the index of where the num is FIRST located (we don't care about the rest)
  if(found)
  {
    cout << "Found " << num << " at position " << index << " of the vector." << endl;
  }
  else
  {
    cout << "Did not find the value " << num << " inside of the vector." << endl;
  }
```

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>