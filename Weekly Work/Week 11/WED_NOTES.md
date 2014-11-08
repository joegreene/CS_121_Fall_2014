# Week 11 Notes - Wednesday

## Sections
- [Intro](#intro)
  - [Notes](#notes)
    - [Dereferencing Pointers](#dereferencing-pointers)
    - [Converting Referenced Parameters to Pointer Parameters](#converting-referenced-parameters-to-pointer-parameters)

### Intro
Below are the notes from the Wednesday (11/5) SI session.

#### Notes
We worked on last week's worksheet and understanding pointers more. Went over some terms, did some program examples 
on the board, and overall reviewed for the exam.

Topics discussed during the session:
- Dereferencing Pointers
- Converting Referenced Parameters to Pointer Parameters

##### Dereferencing Pointers
Recall that pointers are variables that hold an address. The value of a pointer is __equal to the address 
it is pointing at__.

To `dereference` a pointer means to get the value/data located at the address the pointer refers to.

Code excerpt example:
```C++
  double euler = 2.718;
  double* e_ptr = &euler;
  
  cout << "Euler: " << euler << endl
       << "Euler Address: " << &euler << endl
       << "E_ptr: " << e_ptr << endl
       << "E_ptr Dereference: " << *e_ptr << endl;
```

Assuming that euler's address is equal to 2000 (this is extremely unlikely), the output would be:
```
  Euler: 2.718
  Euler Address: 2000
  E_ptr: 2000
  E_ptr Dereference: 2.718
```

If you compile the above code in Visual Studio or XCode, you'll see similar results (the only difference being the 
address of `euler` and the value of `e_ptr` won't be 2000, but they will still be equal to each other). 

If you want to change the value of `euler` from this point on you can do it two different ways:

1) Directly change the value of `euler` by using the assignment operator `=`:
```C++
  euler = 3.14;
```

2) Edit the value of `euler` by dereferencing it from `e_ptr`:
```C++
  *e_ptr = 3.14;
```

__WARNING__: Note the distinction between the two lines of code below:
```C++
  cout << e_ptr << endl;
  cout << &e_ptr << endl;
```

__First line__: `e_ptr` is a pointer, so the value of `e_ptr` is an address that it is pointing at. 

__Second line__: `&e_ptr` is the address where `e_ptr` is located at. `e_ptr` has an address itself because it 
is a variable.

##### Converting Referenced Parameters to Pointer Parameters
In the following swap-function example:
```C++
  void swap(int& a, int& b);
  
  int main()
  {
    int num1 = 12, num2 = 44;
    
    cout << "Num 1: " << num1 << endl 
         << "Num 2: " << num2 << endl;
         
    swap(num1, num2);
    
    cout << "Num 1: " << num1 << endl 
         << "Num 2: " << num2 << endl;
         
    system("pause");
    
    return 0;
  }
  
  void swap(int& a, int& b)
  {
    int temp = a;
    a = b;
    b = temp;
  }
```

How can we change the code so we're passing __by pointer__ instead of __by reference__?

Firstly, change the function heading to pass by pointer
```C++
  void swap(int* a, int* b);
```

Next, edit the body of `swap` to reflect our function heading's edit
```C++
  void swap(int* a, int* b)
  {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
```

To change the values pointers "point" at we `dereference` them. This is denoted by using the `*` 
operator in the front of the pointer's variable name (identifier):
```C++
  int temp = *a; //just like before except we now set temp equal to the dereferenced value at a
  *a = *b;       //set the dereferenced value at a equal to the dereferenced value at b
  *b = temp;     //set the dereferenced value at b equal to temp
```

The above works the same as the by-reference example. Keep in mind that we are __NOT__ changing where 
`a` and `b` point to, we are "indirectly" changing the values located at the addresses `a` and `b` point to. 
It is an indirect change because we are not using `num1` and `num2` to swap `num1` and `num2`, but instead 
we are changing `*a` and `*b` to swap `num1` and `num2`.

Note that we do not need to make `temp` a pointer. This is because `temp` is just some temporary integer we're 
working with. No need to complicate things more than they currently are.

Lastly, edit `main` to reflect the changes we made:
```C++
  int main()
  {
    int num1 = 12, num2 = 44;
    
    cout << "Num 1: " << num1 << endl 
         << "Num 2: " << num2 << endl;
         
    swap(&num1, &num2);
    
    cout << "Num 1: " << num1 << endl 
         << "Num 2: " << num2 << endl;
         
    system("pause");
    
    return 0;
  }
```

All we really need to do is edit the arguments within the call to `swap`. Since the parameters of `swap` require 
pointers (and pointers hold addresses in them), we send the address of `num1` and `num2` as arguments now.

The resulting code:
```C++
  void swap(int* a, int* b);
  
  int main()
  {
    int num1 = 12, num2 = 44;
    
    cout << "Num 1: " << num1 << endl 
         << "Num 2: " << num2 << endl;
         
    swap(&num1, &num2);
    
    cout << "Num 1: " << num1 << endl 
         << "Num 2: " << num2 << endl;
         
    system("pause");
    
    return 0;
  }
  
  void swap(int* a, int* b)
  {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
```

-------------------------------------------------------------------------------

Copyright &copy; 2014 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>