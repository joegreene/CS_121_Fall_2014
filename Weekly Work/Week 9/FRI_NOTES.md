# Week 9 Notes - Friday

## Sections
- [Intro](#intro)
  - [Notes](#notes)
    - [Defining and Implementing Classes in Two Files](#defining-and-implementing-classes-in-two-files)
  
### Intro
Below are the notes from the Friday (10/24) SI session.

#### Notes
We worked on the worksheet and general questions about implementing classes in two files.

Topics discussed during the session:
- Defining and Implementing Classes in Two Files

##### Defining and Implementing Classes in Two Files
To go over defining and implementing classes (in two separate files), we decided to take a look at the FCylinder example 
in the worksheet more in-depth.

For the below, I suggest looking at `FCylinder.h`, `FCylinder.cpp`, and `main.cpp` given on the solutions page to follow along 
easily.

`FCylinder.h` has the definition of the class `FCylinder`. In here, we only have the class definition. Like usual, 
we define all the member variables that we do not want accessed __outside__ of the class itself. This would mean 
that we cannot use the dot operator to call out everything under private. For instance:

```C++
  //In main.cpp under play_area()
  first_cyl.radius = 4;   //inaccessible member variable due to being private
  first_cyl.setRadius(4); //accessible class function
```

The first line (as mentioned in the comment) is invalid syntax because (outside of the class) we cannot access `radius` directly. 
The second line is valid, as the function itself is `public` and can be accessed

All `FCylinder.h` includes are:
- A globally-declared constant double (for PI, since the class requires `PI` for some of its methods), 
- __Private__ member variables
- __Public__ constructors and deconstructor (because we want to be able to create an object of the class outside of the class itself)
- __Public__ methods (such as the setter/getter methods and any methods we want our object able to access outside of the class itself)

__NOTE:__ All the member functions (constructors, the deconstructor, getters/setters, etc.) are __method prototypes__. Just like function 
prototypes, __method prototypes__ let the compiler know that __later__ on you will include the implementations for all your methods (namely, 
you are implementing the methods inside of `FCylinder.cpp`).

Next, `FCylinder.cpp` includes all of the method implementations. At the start, we type the line `#include "FCylinder.h"` because we will be 
referring to that to implement all the methods.

__NOTE__: Although stating `#include <FCylinder.h>` is syntactically correct, as a general rule of thumb 
user-defined header/library files are included using __quotation marks__ `"..."` and libraries defined already in the C++ language are included using 
__angled brackets__ `<...>`

The rest the same as a normal function except for one funky part that is included in each implemented function:
```C++
  //The default constructor
  FCylinder::FCylinder()
  {
    radius = height = 1;
  }
```

By using the __scope operator__ (`::`) what `FCylinder::` does is that it specifies what function we're defining. In the above case, we're defining 
the FCylinder class's default constructor (noted as `FCylinder()`). We use the scope operator accordingly for __every method__ we plan to implement 
from the FCylinder class.

The rest is pretty straightforward from there. The bodies of each method is defined in the FCylinder source file (`.cpp`), which is just like 
how we implement the bodies of the methods (except now we specify __where__ the methods come from).

Lastly, `main.cpp` shows how we can create objects of the class FCylinder and use them. Keep in mind that (when inside `main.cpp`) we don't know 
anything about the __implementation__ of the methods we call, nor do we care. We only care about the function doing its job. This relates to 
one of the key aspects of Object Oriented Programming (specifically implementation hiding). 

__TRIVIA__: As implementation hiding is shown when working in `main.cpp`, think about how (at the moment) we don't know how the vector functions 
`push_back(x)` and `pop_back()` work. You will learn how they work, eventually (either here in 121 or in 131), but for now we don't need to know 
all their details to actually use them.

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>