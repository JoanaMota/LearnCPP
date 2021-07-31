# Learn Advanced C++

My journey to increase my knowledge in C++.

Let's start with the basics:

**Class:** generally specifies the structure of a data type, which holds its own data members and member functions, that can be accessed and used by creating an instance of that class.

**Object:** is an instance of a class which can have states and behaviors. The working entity of a class. When a class is defined, no memory is allocated but when it is instantiated memory is allocated.

**Method:** can modify the class state.

**`this` pointer:** is a constant pointer that holds the memory address of the current object. They are not available in static member functions since static member functions can be called without any object.

**The 4 pillars of OOP:**

- Abstraction: used for hiding the internal implementations and display only the required details to the user.
- Encapsulation: it's a mechanism that binds the data and operations together, thus hiding the details from the user. Encapsulation can be achieved with the help of access specifiers that are public, private and protected in C++. With the help of them, we can provide or prevent access directly to a user.
- Inheritance: it's the possibility of creating a new child class from existing classes, and thus inheriting the properties of the parent class. The parent class is then referred as the Base Class and the child the Derived Class. Normally used for code reusability.
- Polymorphism: it enables a child class to have the same functionality as its parent class and at the same time have its onw methods and behaviours. However a parent class cannot have the functions of a child class.

**Access Specifiers:**

- public: members and methods can be accessed outside of the class
- private: members and methods can only be accessed inside its class
- protected: members and methods can be accessed inside its class and also derived classes

**Types of Inheritance:**

- Single: one base class and one derived class.
- Multiple: a derived class inherits from two or more classes.
- Multilevel: the derived class is the base class for another class.
- Hierarchical: multiple derived classes inherit the properties of the same base class.
- Hybrid: It's Virtual Inheritance. It is a combination of Multilevel and Hierarchical inheritance.

**[Abstract Class](https://github.com/JoanaMota/LearnCPP/wiki/Abstract-Classes-Pure-Virtual-Functions) VS Interface**

|               |                               Abstract Class                                |                      Interface                       |
| :-----------: | :-------------------------------------------------------------------------: | :--------------------------------------------------: |
| Instantiation |            Cannot be instantiated, only the derived classes can             | It is absolutely abstract and cannot be instantiated |
|    Methods    | Must have at least one pure virtual method and can have implemented methods |   Has all methods declared as pure virtual methods   |
|   Variables   |                       Can have variables declaration                        |             Has no variable declaration              |
|    Members    |                    Can be public, private and protected                     |                  Have to be public                   |
|     Speed     |                                    Fast                                     |                Is comparatively slow                 |

**Virtual method** is used with inheritance and is a method which can be redefined in the derived class.The usage of the virtual keyword tells the compiler to perform dynamic linkage or late binding on the method. Virtual functions are resolved at runtime.

**Pure virtual method** is a virtual method which does not need to be defined but only declared. It is declared by assigning 0 to a virtual method.

**Constructor:**
Its the subroutine called to create an object which also prepares the object to be used. It has the same name as the class.

[Types of constructors](https://github.com/JoanaMota/LearnCPP/blob/main/Cpp11NewFeatures/19_constructors_and_memory.cpp):

- Default Constructor;
- Parameterized Constructor;
- Copy Constructor -> initializes an object using another object of the same class;
- Assignment operator overload.

**Destructor:**
The subroutine called to destruct an object.

**C VS C++**

|                            C                            |                                                   C++                                                    |
| :-----------------------------------------------------: | :------------------------------------------------------------------------------------------------------: |
|             procedural programming language             |                         supports both procedural and Object Oriented programming                         |
|                                                         | supports features like function overloading, templates, inheritance, virtual functions, friend functions |
|                no methods in structures                 |                                      can have methods in structures                                      |
|                      no references                      |                                           supports references                                            |
|     `scanf()` and `printf()` used for input/output      |                     uses streams to perform input `cin` and output `cout` operations                     |
| exception handling is done in traditional if-else style |                              supports exception handling at language level                               |

**Difference between `class` and `struct`:**
Class and struct are basically the same, the only difference is that the visibility of the members by default in a structure is public and private in a class.

Since they are basically the same how can we choose to use one or the other?

A `strcut` is more a bundle, it contains several related elements that need to be tied up together in a certain context. A `class` is more like a doer which has responsibilities.

Contrary to a `strcut`, a `class` is made to offer an interface, that has some degree of separation from its implementation. A `class` is not just there to store data. In fact a user of a class is not supposed to know what data the class is storing, or if it contains any data at all for that matter. All he cares about is its responsibilities, expressed via its interface.

**Differences between references and pointers:**

1. Once a reference is created, it cannot be later made to reference another object; it cannot be reseated. This is often done with pointers.
2. References cannot be NULL. Pointers are often made NULL to indicate that they are not pointing to any valid thing.
3. A reference must be initialized when declared. There is no such restriction with pointers.
4. References are safer and easier to use.

**VTABLE and VPTR:**

**vtable** is a table of function pointers maintained per class.

**vpt**r is a pointer to vtable and is maintained per object.

For every constructor the compiler sets the vptr of the object being created which will point to the vtable of the class.

[What is Late Binding or Dynamic Linkage](https://github.com/JoanaMota/LearnCPP/wiki/Virtual-Functions#what-is-late-binding-or-dynamic-linkage)

[Inline Functions](https://github.com/JoanaMota/LearnCPP/wiki/Virtual-Functions#inline-functions)

**Friend Class:** a class which can access private and protected members of other class in which it is declared as friend. Friendship is not mutual. Friendship is not inherited

**`malloc()` VS `new`**

- `new` is an operator, `malloc()` is a function.
- `new` returns exact data type, while `malloc()` returns void pointer.
- `new` calls constructors, while `malloc()` does not.

```cpp
int *n = new int(10); // initialization with new()
str = (char *) malloc(15); //malloc()
```

**`delete` VS `free()`:**

`free()` is used on resources allocated by `malloc()`, or `calloc()` in C.

`delete` is used on resources allocated by new.

**Dynamic Polymorphism VS...**

---

To improve my C++ knowledge I took the Udemy Course - Learn Advanced C++ Programming and here are some of the exercises implementations.

> For more detailed information about the subjects checkout my notes on the [Wiki](https://github.com/JoanaMota/LearnCPP/wiki) :wink:

- The Standard Template Library (STL) Data Structures

  - [Vectors](https://github.com/JoanaMota/LearnCPP/wiki/Vectors)
    - Vectors and Memory
    - 2D Vectors
  - [Lists](https://github.com/JoanaMota/LearnCPP/wiki/Lists)
  - [Maps](https://github.com/JoanaMota/LearnCPP/wiki/Maps)
    - Custom objects as Map values
    - Custom objects as Map keys
    - Multimap
  - [Sets](https://github.com/JoanaMota/LearnCPP/wiki/Sets)
  - [Stacks and Queues](https://github.com/JoanaMota/LearnCPP/wiki/Stacks-Queues)
  - [Sorting Vectors, Deque and Friend](https://github.com/JoanaMota/LearnCPP/wiki/Sorting-Vectors-Deque-Friend)
  - [STL complex data types](https://github.com/JoanaMota/LearnCPP/wiki/Complex-Data-Types)

- Operating Overloading

  - [Overloading the assignment operator `=`](https://github.com/JoanaMota/LearnCPP/wiki/Assignment-Operator-Overloading)
  - [Overloading left bit shift `<<`](https://github.com/JoanaMota/LearnCPP/wiki/Left-Bit-Shift-Overloading)
  - [A complex number class](https://github.com/JoanaMota/LearnCPP/wiki/Complex-Number-Class)
  - [Overloading plus operator `+`](https://github.com/JoanaMota/LearnCPP/wiki/Plus-Operator-Overloading)
  - [Overloading equality test](https://github.com/JoanaMota/LearnCPP/wiki/Equality-Test-Overloading)
  - [Overloading the dereference operator `*`](https://github.com/JoanaMota/LearnCPP/wiki/Dereference-Operator-Overloading)

- Templates

  - [Templates Intro](https://github.com/JoanaMota/LearnCPP/wiki/Templates)
  - [Template Functions](https://github.com/JoanaMota/LearnCPP/wiki/Template-Functions)
  - [Template Classes](https://github.com/JoanaMota/LearnCPP/wiki/Template-Classes)
  - [Template Functions and Type Inference](https://github.com/JoanaMota/LearnCPP/wiki/Template-Functions-and-Type-Inference)
  - [Template Arguments](https://github.com/JoanaMota/LearnCPP/wiki/Template-Arguments)
  - [Template Specialization](https://github.com/JoanaMota/LearnCPP/wiki/Template-Specialization)
  - [Template Partial and Explicit Specialization](https://github.com/JoanaMota/LearnCPP/wiki/Template-Partial-And-Explicit-Specialization)

- Virtual Functions

  - [Virtual Functions Intro](https://github.com/JoanaMota/LearnCPP/wiki/Virtual-Functions)
  - [Virtual Destructor, Constructors and Copy Constructors](https://github.com/JoanaMota/LearnCPP/wiki/Virtual-Destructore-Constructores-Copy-Constructors)
  - [Run Time Type Information RTTI](https://github.com/JoanaMota/LearnCPP/wiki/Run-Time-Type-Information-RTTI)

- Passing Functions to Functions

  - [Function Pointers](https://github.com/JoanaMota/LearnCPP/wiki/Function-Pointers)
  - [Abstract Classes and Pure Virtual Functions](https://github.com/JoanaMota/LearnCPP/wiki/Abstract-Classes-Pure-Virtual-Functions)
  - [Functors](https://github.com/JoanaMota/LearnCPP/wiki/Functors)

- [Linked List](https://github.com/JoanaMota/LearnCPP/wiki/Linked-List-Intro)

  - Singly Linked List
    - [SLL Insertion and Deletion](https://github.com/JoanaMota/LearnCPP/wiki/Singly-Linked-List-Insertion-Deletion)
    - [SLL Length, Search, Count and Remove Duplicates](https://github.com/JoanaMota/LearnCPP/wiki/Singly-LL-Length-Search-Count)
    - [SLL Reverse and Segregate](https://github.com/JoanaMota/LearnCPP/wiki/Singly-LL-Reversing-Segregate)
  - Doubly Linked List
    - [DLL Insertion and Deletion](https://github.com/JoanaMota/LearnCPP/wiki/Doubly-Linked-List-Insertion-Deletion)
    - [DLL Length, Reverse and Remove Duplicates](https://github.com/JoanaMota/LearnCPP/wiki/DLL-Remove-Duplicates-Length-Reverse)
  - Circular Linked List
    - [CLL Insertion and Deletion](https://github.com/JoanaMota/LearnCPP/wiki/Circular-Linked-List-Insertion-Deletion)

- Other Topics
  - [Multiple Inheritance](https://github.com/JoanaMota/LearnCPP/wiki/Multiple-Inheritance)
  - [`auto` Keyword](https://github.com/JoanaMota/LearnCPP/wiki/Auto)
  - [Enhanced `for` Loop](https://github.com/JoanaMota/LearnCPP/wiki/Enhanced-For-Loop)
  - [Nested Template Classes](https://github.com/JoanaMota/LearnCPP/wiki/Nested-Template-Classes)
  - [Ring/Circular Buffer](https://github.com/JoanaMota/LearnCPP/wiki/Ring-Buffer)
  - [Iterable Classes](https://github.com/JoanaMota/LearnCPP/wiki/Iterable-Classes)
  - [Initialization C++98 vs C++11](https://github.com/JoanaMota/LearnCPP/wiki/Initialization#initialization)
  - [Initializer Lists](https://github.com/JoanaMota/LearnCPP/wiki/Initialization#initializer-lists)
  - [Object Initialization, Default and Delete](https://github.com/JoanaMota/LearnCPP/wiki/Initialization#object-initialization-default-and-delete)
  - [Delegating Constructors](https://github.com/JoanaMota/LearnCPP/wiki/Initialization#delegating-constructors)
  - [Lambda Expressions](https://github.com/JoanaMota/LearnCPP/wiki/Lambda-Expressions)
  - [The Standard Function Type](https://github.com/JoanaMota/LearnCPP/wiki/Standard-Function-Type)
  - [Return Value Optimization](https://github.com/JoanaMota/LearnCPP/wiki/Constructores)
  - [Constructors and Memory](https://github.com/JoanaMota/LearnCPP/wiki/Constructores#constructors-and-memory)
  - [RValues and LValues](https://github.com/JoanaMota/LearnCPP/wiki/RValue-LValue-References)
    - [LValue References](https://github.com/JoanaMota/LearnCPP/wiki/RValue-LValue-References#lvalue-references)
    - [RValue References](https://github.com/JoanaMota/LearnCPP/wiki/RValue-LValue-References#rvalue-references)
  - Casting
    - [Static Cast](https://github.com/JoanaMota/LearnCPP/wiki/Casting#static-cast)
    - [Dynamic Cast](https://github.com/JoanaMota/LearnCPP/wiki/Casting#dynamic-cast)
    - [Reinterpret Cast](https://github.com/JoanaMota/LearnCPP/wiki/Casting#reinterpret-cast)
  - [Perfect Forwarding](https://github.com/JoanaMota/LearnCPP/wiki/Perfect-Forwarding)
  - [Bind](https://github.com/JoanaMota/LearnCPP/wiki/Bind)
  - Pointers
    - [Normal Pointers](https://github.com/JoanaMota/LearnCPP/wiki/Pointers#pointers)
    - [Unique Pointers](https://github.com/JoanaMota/LearnCPP/wiki/Pointers#unique-pointers)
    - [Shared Pointers](https://github.com/JoanaMota/LearnCPP/wiki/Pointers#shared-pointers)
