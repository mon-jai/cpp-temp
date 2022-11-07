Welcome to the course website of OOP 2022 fall. The source code we wrote in the class will be available here. You can check history tab on the top of this page to see the content of each week. Notably, the teaching materials and methods are credited to Prof. Yu Chin Cheng at CSIE, NTUT. For any inquires, please email shchen@ntut.edu.tw with title [物件導向程式設計]_姓名_學號_班級. Formal format is required in the email.

**Link to Homework: http://140.124.183.78/gitlab/109000000/oop2022f_hw**

### Week 9 11/7 & 11/11 - Midterm

### Week 8 11/04 - Vector containers & Review before Midterm

- Default constructor will 'not' be generated automatically
    - When there is another constructor with some passed parameters
    - When a fix-sized array of the defined object is decleared
    - When a variable-sized array is decleared
    - When template class is been used

- Vector
    - subcategory of Standard Template Library
    - sequence containers representing arrays that can change in size.
    - [Link1](https://shengyu7697.github.io/std-vector/)、[Link2](https://cplusplus.com/reference/vector/vector/?kw=vector)

### Week 8 10/31 - NO CLASS (School Anniversary Celebration)

### Week 7 10/28 - The left right issue

- Left value v.s Right value
    - lvalue have memory space and can be reference to
    - rvalue do have memory space 
    - lvalue reference v.s rvalue reference
    - & v.s &&
    - Forcing casting temporal rvalue to lvalue through "const" before "&" in function paramaters
    - return lvalue reference to have the effect of both getter and setter

- Move semantics
    - std::move -> Returns an rvalue reference to arg [Link](https://cplusplus.com/reference/utility/move/?kw=move)
    - After move, original value should be left empty
    - Avoid copying from rvalue

### Week 7 10/24 - NO CLASS (Official Leave of Teacher)

### Week 6 10/21 - Google Text Fixture & Seperating definition from declaration

- Four questions to ask when writing a member function
  - what is the name?
  - what are the arguments?
  - what is the return type?
  - is it a constant?
- Tiring of douplicated codes when writing test cases?
  - [test fixture](https://github.com/google/googletest/blob/master/docs/primer.md#test-fixtures-using-the-same-data-configuration-for-multiple-tests-same-data-multiple-tests)
- **You shuold see error when calling a non-constant member function from a constant object**

### Week 6 10/17 - default / delete / Inline call to other constructor

- Please lookup the reserved word: default/delete in C++
- Inline function call can be very useful
- Constructor initializer list
  - To call base class constructor
  - To initialize local private variable
  - [Link](https://kwcheng0119.pixnet.net/blog/post/43384290)
  
### Week 5 10/14 - Addressof operator v.s. Reference

Suggesting reading : CH 10

- What is the difference of following operators?


      double *p, v; 
      p = &v; // & Addressof operator
      *p = 12; // * dereferencing operator
      
      int r; 
      int &xp = r; // reference


- The concept of reference
  - Avoid copy constructor when passing by reference
  - Must be initialized when declaring

- When you find a bug:
    - write a test that fails due to the bug
    - fix the bug
    - compile and run the test
    - repeat until tests pass

- Refactoring: we extracted the private function MathVector::initialize(double * a, int dim) which is used in two constructors and copy assignment. The act is called "refactoring" (Extract Function in this case) that meets three conditions:
    - not changing external behavior of the changed methods, the constructors and copy assignments
    - changing the internal structure: in this case, removed duplicated code in the member functions into a private member function (the initialize)
    - there unit tests that checked on the affected code. The tests must be passing before/after the change
    - reference: Extract Method

### Week 5 10/10 - NO CLASS (National Holiday)

### Week 4 10/07 - Copy Assignment

- copy assignment
  - right associative w = u = v; => w = (u = v);
  - return by reference
  - the this pointer
  - automatically generated if not defined shallow copy not deep copy

Example

    class MyClass obj1, obj2;
    class MyClass obj3(obj1);     //Calls Copy Constructor
    class MyClass obj4 = obj1;    //Calls Copy Constructor
    obj1 = obj2;                  //Calls Copy Assignment Operator

### Week 4 10/03 - Indepth on copy constructor 

Suggesting reading : Passed by reference (&)

- Copy constructor - may be called in the following cases: 
  1. When an object of the class is returned by value. 
  2. When an object of the class is passed (to a function) by value as an argument. 
  3. When an object is constructed based on another object of the same class. 
  4. When the compiler generates a temporary object.

### Week 3 9/30 - Handling exception

Suggesting reading : CH 7.1 & CH 8.1

**Problem III** Let _v_ be a n-dimensional vector and _a_ be a real number. Write a program to calculate its scalar multiplication _a_ _v_.

**Problem IV** Let _u_, _v_ be n-dimensional vectors. Write a program to calculate add u to v to obtain _u_ + _v_

**Problem V** Let _u_, _v_ be n-dimensional vectors and _a_, _b_ be real numbers. Write a program to calculate _a_ _u_ + _b_ _v_

- Handle exception
- Pointer
  - *a, a[], &a
- runtime model of program
  - data, text, stack, heap
- memory allocation/deallocation from heap
  - new operator: allocating space from heap
  - delete operator: de-allocating space from heap
  - memory leak: allocated space NOT de-allocated when it's done used

Quick notice : Next year, we will have huge reudction (down to 10 peoples) in accepting people on joining this course. Please pass this year!

### Week 3 9/26 - Dedining a member function for class

Suggesting reading : CH 6

**Problem II** Deriving the inner product of two vector.

      [1, 0] · [1, 1] = 1,
      [1, 1, 0] · [0, 1, 1] = 1, and
      [1, 0] · [1, 1, 0] => undefined.

**The plan** [Inner product, round 1](http://htsicpp.blogspot.com/2014/08/inner-product-round-1.html)

### Week 2 9/23 - Knowning class & constructor with the MathVector example

Reference
- Text book
- [cplusplus.com](https://www.cplusplus.com/)
- [googletest](https://github.com/google/googletest/blob/master/docs/primer.md)

We will solve a few problems together through the practices of "How To Solve It". 

**Problem solving**

- understanding the problem
- devising a plan
- carrying out the plan
- looking back

**Problem I** Let v a n-dimensional vector. Write a program to calculate its length | v |.

If you're not familiar with vector, read [here](https://en.wikipedia.org/wiki/Vector_space).

### Week 2 9/19 - Get Started with the HelloWolrd Examples to be Familiar with Unit Test

Suggesting reading : Slieds in MS teams & CH 2

Homework : Follow the slides to setup environment (09/23 24:00) & Sumbit code to gitlab (09/30 24:00)

### Week 1 - Introduction & Environment 

Setup Suggesting reading : following links & CH 1

In this semester, 3 things will be given to assist you in your future career.
- [How To Solve It](http://htsicpp.blogspot.com/2014/08/introducing-how-to-solve-it-cpp.html) (Proposed by George Pólya)
- C++ (version 11)
- Engineering practices (unit testing, version control, make, incremental development, test driven development, pair programming, and mob programming, [using Linux cmds](https://ubuntu.com/tutorials/command-line-for-beginners#1-overview))
