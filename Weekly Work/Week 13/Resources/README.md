# Week 13 Solutions

## Sections
- [Intro](#intro)
- [Worksheet](#worksheet)
  - [Questions](#questions)
    - [Problems](#problems)
    
### Intro
This page hosts the solutions to the questions for this week's worksheet. 

The worksheet itself is located in its usual place (in the file listing above).

__NOTE__: Note that, if you use `using namespace std;` or `using std::cout;` or something similar 
of the sort, you do not require `std::` when overloading the insertion/extraction operators.

__NOTE 2__: Although I did not give it out last week, I'm planning on making some practice work with 
polymorphism, inheritance, and virtual on here. It'll take a bit for me to complete however.

### Worksheet
Below is the worksheet solutions for this week.

#### Questions
Grab the questions from the worksheet document.

##### Problems
1) Using a bit of boolean logic, you can represent `>`, `<=`, `>=`, and `!=` using the two given operators.

To get the answers for this problem, we look at the __complement__ of each operator we need to make.

For instance, `greater than` is the same as saying `not less than or equal to`, `less than or equal to` is the 
same as `not greater than`, and `greater than or equal to` is the same as `not less than`. The last one just, 
`not equals` just needs the `!` (NOT) operator on the `==` operator.

Therefore, some possible answers (syntax might be written differently) for what was requested are the following:
```C++
  //> (I decided to use this one first so it may be reused later)
  bool Dog::operator>(const Dog& lhs, const Dog& rhs)
  {
    //because they were defined already, we can use the object directly
    //with each operator
    
    //`>` complement is `< || ==`
    return !((lhs == rhs) || (lhs < rhs));
  }
  
  //<=
  bool Dog::operator<=(const Dog& lhs, const Dog& rhs)
  {
    //`<=` complement is `>`
    return !(lhs > rhs);
  }
  
  //>=
  bool Dog::operator>=(const Dog& lhs, const Dog& rhs)
  {
    //`>=` complement is `<`
    return !(lhs < rhs);
  }
  
  //!=
  bool Dog::operator!=(const Dog& lhs, const Dog& rhs)
  {
    //pretty self-explanatory, but `!=` complement is `==`
    return !(lhs == rhs);
  }
```

2) One possible answer:
```C++
  //more efficient way than `using namespace std;`
  using std::istream;
  
  //Class
  class Pokemon
  {
    private:
      int health;
      int attack;
      int defense;
      int speed;
      //...etc....
    public:
      //...etc....
      friend istream& operator>>(istream& input, Pokemon& pkmn);
  };
  
  istream& operator>>(istream& input, Pokemon& pkmn)
  {
    //lazy example, assumes integers are separated by spaces
    input >> pkmn.health >> pkmn.attack
          >> pkmn.defense >> pkmn.speed;
    
    return input;
  }
```

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>