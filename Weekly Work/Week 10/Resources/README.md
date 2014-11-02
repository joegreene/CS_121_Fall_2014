# Week 10 Solutions

## Sections
- [Intro](#intro)
- [Worksheet](#worksheet)
  - [Questions](#questions)
    - [Classes Practice](#classes-practice)
    - [Pointer Practice](#pointer-practice)
    
### Intro
This page hosts the solutions to the questions for this week's worksheet. 

The worksheet itself is located in its usual place (in the file listing above).

__NOTE 1__: I couldn't get the tables to show up properly in the document, so I've 
taken photos of how they should be laid out in images. Check out `question_four_wk10.jpg` 
[here](question_four_wk10.jpg), `question_five_wk10.jpg` [here](question_five_wk10.jpg), 
and `question_six_wk10` [here](question_six_wk10.jpg) for their respective tables.

__NOTE 2__: Since I can't display images directly into this page, I've taken screen shots of 
my work on problems #4 through #6 (in pointer practice).

Make sure to `Right Click -> View Image` to see each image in its full resolution. Also, to help 
understand the process, I numbered each step made in problems #4 through #6 in each image.

### Worksheet
Below is the worksheet solutions for this week.

#### Questions
Remember to refer to the images in the file listing for questions #4 through #6 in the pointers section.

##### Classes Practice
Object Analysis phase:
```
  A classroom has both students and a teacher (collection of data)
  -> Name for class object should be "Classroom"
  Students should be represented as objects (collection of data)
  -> Name for a nested object (in Classroom) is Students
  The teacher should be represented as an object too (collection of data)
  -> Name for another nested object (in Classroom) is Teacher
```

Possible methods and member variables for `Classroom`:
```
  Classroom methods:
  - Student count
  - Get class grade average
  - Get maximum person capacity (e.g. maximum number of seats)
  - Get room number (method to get the room number)
  - etc.
  
  Classroom member variables:
  - List of students (array or vector)
  - Teacher
  - Room number
  - Class capacity
  - etc.
```

Example blueprints (assume other parts exist):
```C++
  #include <vector>    //To use a vector for the student list in Classroom
  #include "Teacher.h" //so Classroom sees that "Teacher" exists
  #include "Student.h" //so Classroom sees that "Student" exists

  class Classroom
  {
    private:
      vector<Student> student_list;
      Teacher teacher;
      int room_num;
      int class_capacity;
    public:
      Classroom();
      ~Classroom();
      
      int getStudentCount();  //return student count; can use "student_list.size();"
      double getAvgGrade();   //return average class grade
      int getClassCapacity(); //return class capacity value
      int getRoomNumber();    //return room number
  };
```

__NOTE__: The classes `Student` and `Teacher` must have their own implementations as well. This is because 
`Classroom` won't have any idea that the two exist, that is, unless you include both `Student` and `Teacher` 
before making `Classroom`. They just have to be before `Classroom` (meaning they can be defined in the same file 
if you want).

##### Pointer Practice
1) Output:
```
  71156
```

Separated (adding " " to each `cout`):
```
  7 11 5 6
```

2) Example scenario of this:
```C++
  double list[] = {1.1,2.2,3.3,4.4};
  double * dblptr = list;
```

Where the four different ways would be (using index 3, a.k.a. position 4, in `list`):
```
  list[3]: Calling position by array name and subscript
  *(list + 3): Calling position by array name and arithmetic
  dblptr[3]: Calling position by pointer to array and subscript
  *(dblptr + 3): Calling position by pointer to array and arithmetic
```

3) Work:
```C++
  double john = 44, jacob = 33;
  double &jingle = john;
  john = 41;                                             //sets jingle and john to 41
  cout << john << ":" << jacob << ":" << jingle << endl; //41:33:41
  jacob = jingle;                                        //sets jacob to 41
  jingle = 12;                                           //sets jingle and john to 12
  cout << john << ":" << jacob << ":" << jingle << endl; //12:41:12
```

4) Check the image labelled `solution_four_wk10.jpg`, or click [here](solution_four_wk10.jpg).

5) Check the image labelled `solution_five_wk10.jpg`, or click [here](solution_five_wk10.jpg).

6) Check the image labelled `solution_six_wk10.jpg`, or click [here](solution_six_wk10.jpg).

7) Explanations:
```C++
  cout << (ptr == ptr2) << endl; //Comparing the addresses ptr and ptr2 point to

  cout << (*ptr == *ptr2) << endl; //Comparing the data ptr and ptr2 point to
                                   //(the dereferenced values at ptr and ptr2's addresses)
```

8) Converted program:
```C++
  void GetEmployeeInfo(string* name, double* salary); //pass by-pointer

	int main()
	{
  	  string employeeName;
  	  double pay;
  	  GetEmployeeInfo(&employeeName, &pay); //send the addresses of employeeName 
                                            //and pay through the function

  	  cout << "Employee name: " << employeeName << endl;
      cout << "Salary: " << pay << endl;

  	  ///...etc code
  	  return 0;
	}

	void GetEmployeeInfo(string* name, double* salary)
	{
  	  cin >> *name >> *salary; //send value (grabbed by cin) to dereferenced 
                               //pointers "name" and "value"
	}

```

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>