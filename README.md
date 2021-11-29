# My Journey Learning C++

:star: This is a collection of all my notes and thoughts that I have been assembling while learning and trying to increase my knowledge in C++.

### :mag: For more detailed information about C++ main topics checkout my full notes on the [Wiki](https://github.com/JoanaMota/LearnCPP/wiki) :wink:

:point_right: Now let's start with the basics:

**Class:** generally specifies the structure of a data type, which holds its own data members and member functions, that can be accessed and used by creating an instance of that class.

**Object:** is an instance of a class which can have states and behaviors. The working entity of a class. When a class is defined, no memory is allocated but when it is instantiated memory is allocated.

**Method:** can modify the class state.

**`this` pointer:** is a constant pointer that holds the memory address of the current object. They are not available in static member functions since static member functions can be called without any object.

### The 4 pillars of OOP:

- Abstraction: used for hiding the internal implementations and display only the required details to the user.
- Encapsulation: it's a mechanism that binds the data and operations together, thus hiding the details from the user. Encapsulation can be achieved with the help of access specifiers that are public, private and protected in C++. With the help of them, we can provide or prevent access directly to a user.
- Inheritance: it's the possibility of creating a new child class from existing classes, and thus inheriting the properties of the parent class. The parent class is then referred as the Base Class and the child the Derived Class. Normally used for code reusability.
- Polymorphism: the ability of different objects to behave differently for the same request, it enables a child class to have the same functionality as its parent class and at the same time have its own behaviours. However a parent class cannot have the functions of a child class. There are 2 types of polymorphism [static (method overloading) and dynamic (method overriding)](https://github.com/JoanaMota/LearnCPP#static-vs-dynamic-polymorphism).

### Access Specifiers:

- public: members and methods can be accessed outside of the class
- private: members and methods can only be accessed inside its class
- protected: members and methods can be accessed inside its class and also derived classes

### Types of Inheritance:

- Single: one base class and one derived class.
- Multiple: a derived class inherits from two or more classes.
- Multilevel: the derived class is the base class for another class.
- Hierarchical: multiple derived classes inherit the properties of the same base class.
- Hybrid: It's Virtual Inheritance. It is a combination of Multilevel and Hierarchical inheritance. While it’s ideal to avoid virtual inheritance altogether it can be helpful in some use cases like in [The Diamond Problem](https://github.com/JoanaMota/LearnCPP/wiki/Abstract-Classes-Pure-Virtual-Functions#the-diamond-problem)

### [Abstract Class](https://github.com/JoanaMota/LearnCPP/wiki/Abstract-Classes-Pure-Virtual-Functions) VS Interface

|               |                               Abstract Class                                |                      Interface                       |
| :-----------: | :-------------------------------------------------------------------------: | :--------------------------------------------------: |
| Instantiation |            Cannot be instantiated, only the derived classes can             | It is absolutely abstract and cannot be instantiated |
|    Methods    | Must have at least one pure virtual method and can have implemented methods |   Has all methods declared as pure virtual methods   |
|   Variables   |                       Can have variables declaration                        |             Has no variable declaration              |
|    Members    |                    Can be public, private and protected                     |                  Have to be public                   |
|     Speed     |                                    Fast                                     |                Is comparatively slow                 |

[**`virtual` method**](https://github.com/JoanaMota/LearnCPP/wiki/Virtual-Functions) is used with inheritance and is a method which can be redefined in the derived class.The usage of the virtual keyword tells the compiler to perform dynamic linkage or late binding on the method. Virtual functions are resolved at runtime.

**Pure `virtual` method** is a virtual method which does not need to be defined but only declared. It is declared by assigning 0 to a virtual method.

Keywords `override` and `final` allow to better express your intentions with what you want to do with virtual functions.

`override`: used to tag a method from a derived class that overrides a virtual method.

```cpp
class Base
{
public:
    virtual void f()
    {
        std::cout << "Base class default behaviour\n";
    }
};

class Derived : public Base
{
public:
    void f() override
    {
        std::cout << "Derived class overridden behaviour\n";
    }
};
```

`final`: used to prevent any derived class to override that base class member function.

```cpp
class Derived : public Base
{
public:
    void f() final
    {
        std::cout << "Derived class overridden behaviour\n";
    }
};
```
### Constructor:

Its the subroutine called to create an object which also prepares the object to be used. It has the same name as the class.

[Types of constructors](https://github.com/JoanaMota/LearnCPP/blob/main/Cpp11NewFeatures/19_constructors_and_memory.cpp):

- Default Constructor;
- Parameterized Constructor;
- Copy Constructor -> initializes an object using another object of the same class;
- Assignment operator overload.

### Destructor:

The subroutine called to destruct an object. It is called every time an object loses its scope.

### C VS C++

|                            C                            |                                                   C++                                                    |
| :-----------------------------------------------------: | :------------------------------------------------------------------------------------------------------: |
|             procedural programming language             |                         supports both procedural and Object Oriented programming                         |
|                                                         | supports features like function overloading, templates, inheritance, virtual functions, friend functions |
|                no methods in structures                 |                                      can have methods in structures                                      |
|                      no references                      |                                           supports references                                            |
|     `scanf()` and `printf()` used for input/output      |                     uses streams to perform input `cin` and output `cout` operations                     |
| exception handling is done in traditional if-else style |                              supports exception handling at language level                               |

You can call a C function inside a C++ program through the usage of `extern "C" {}`

```cpp
extern "C"{
void func(int i);
void print(int i);
}

void myfunc(int i)
{
   func(i);
   print(i);
}
```

### `class` VS `struct`:

Class and struct are basically the same, the only difference is that the visibility of the members by default in a structure is public and private in a class.

Since they are basically the same how can we choose to use one or the other?

A `struct` is more a bundle, it contains several related elements that need to be tied up together in a certain context. A `class` is more like a doer which has responsibilities.

Contrary to a `struct`, a `class` is made to offer an interface, that has some degree of separation from its implementation. A `class` is not just there to store data. In fact a user of a class is not supposed to know what data the class is storing, or if it contains any data at all for that matter. All he cares about is its responsibilities, expressed via its interface.

### Differences between references and pointers:

1. Once a reference is created, it cannot be later made to reference another object; it cannot be reseated. This is often done with pointers.
2. References cannot be NULL. Pointers are often made NULL to indicate that they are not pointing to any valid thing.
3. A reference must be initialized when declared. There is no such restriction with pointers.
4. References are safer and easier to use.

### VTABLE and VPTR:

**vtable** is a table of function pointers. Every class has a vTable

**vptr** is a pointer to vtable and is maintained per object. Every object has a vptr

For every constructor the compiler sets the vptr of the object being created which will point to the vtable of the class.

Code with the polymorphic functional call – At every location where a polymorphic call is made, the compiler inserts code in order to first look for vptr using the base class pointer or reference. The vTable of a derived class can be accessed once the vptr is successfully fetched. Address of derived class function show() is accessed and called using the vTable.

### [What is Late Binding or Dynamic Linkage](https://github.com/JoanaMota/LearnCPP/wiki/Virtual-Functions#what-is-late-binding-or-dynamic-linkage)

### `malloc()` VS `new`

- `new` is an operator, `malloc()` is a function.
- `new` returns exact data type, while `malloc()` returns void pointer.
- `new` calls constructors, while `malloc()` does not.

```cpp
int *n = new int(10); // initialization with new()
str = (char *) malloc(15); //malloc()
```

### `free()` VS `delete`:

`free()` is used on resources allocated by `malloc()`, or `calloc()` in C.

`delete` is used on resources allocated by new.

### Static VS Dynamic Polymorphism

**Static** polymorphism memory will be allocated at compile-time and is also known as early binding. It provides fast execution since it is analyzed early at compile time. Less flexible. Example: function overloading, operator overloading and templates.

```cpp
// Function Overloading
void add(int a, int b){ cout << "Int result = " << (a + b) << endl; }
void add(int a, int b, int c){ cout << "Triple int result = " << (a + b + c) << endl; }
void add(float a, float b){ cout << "Float result = " << (a + b) << endl; }
// Templated Functions
template <typename T>
void multiply(T a, T b){ cout << "Templated Function Result = " << (a * b) << endl; }

int main(void)
{
    add(val1, val2);
    add(val1, val2, val3);
    add(valf1, valf2);
    multiply(val1, val2);
    multiply(valf1, valf2);
    return 0;
}
```

Compiler searches for function with the correct signature and uses the one that fits best. :warning: Each time you leave something for compiler to deduce — make sure there is no room for ambiguity left.

**Dynamic** polymorphism memory will be allocated at run-time. The compiler determines the type of the object at runtime and then binds the function call. Is also known as Late Binding or Dynamic Linkage. It's slow because it is analyzed at runtime. More flexible. Example: virtual functions and pointers.

```cpp
class Base
{
public:
    virtual void show() { cout << "Base Class" << endl; }
};
class Derived : public Base
{
public:
    void show() { cout << "Derived Class" << endl; }
};

int main(void)
{
    Base *bp = new Derived;
    bp->show(); // Runtime Polymorphism in Action
    return 0;
}
```

### Types of Class Member Functions

- Simple
- Static: means that no matter how many objects of the class are created, there is only one copy of the static member. The function is independent of any particular object of the class. Can be called even if no objects of the class exist. Can only access static data members, thus they don't have access to the `this` pointer, thus nor its related data members.
- Const: functions can never modify the object or its related data members. The const modifier for a static member function is meaningless, because there is no object associated with the call.
- [Inline](https://github.com/JoanaMota/LearnCPP/wiki/Virtual-Functions#inline-functions)
- Friend: are made to give private access to non-class functions.
- Mutable: is mainly used to allow a particular data member of const object to be modified. `mutable` is particularly useful if most of the members should be constant but a few need to be updateable. You cannot use the mutable specifier with names declared as static or const, or reference.
- Volatile: informs the compiler that a variable may change without the compiler knowing it. Variables that are declared as volatile will not be cached by the compiler, and will thus always be read from memory.

```cpp
class A
{
  public:
    A() : x(4), y(5) { };
    mutable int x;
    int y;
};

int main()
{
  const A var2;
  var2.x = 345;
  // var2.y = 2345;
}
```

**Friend Class:** a class which can access private and protected members of other class in which it is declared as friend. Friendship is not mutual. Friendship is not inherited.

### `itr++` VS `++itr`

`itr++` operator is more expensive than the pre-increment `++itr` operator. The post-increment operator generates a copy of the element before proceeding with incrementing the element and returning the copy. Moreover, most compilers will automatically optimize `itr++` by converting it implicitly into `++itr`.

### [Shallow Copy and Deep Copy](https://www.geeksforgeeks.org/shallow-copy-and-deep-copy-in-c/)

### [The Diamond Problem](https://github.com/JoanaMota/LearnCPP/wiki/Abstract-Classes-Pure-Virtual-Functions#the-diamond-problem)

### [What is C++ Garbage Collection?](https://www.educba.com/c-plus-plus-garbage-collection/)

### How can you make sure that a function is called only with the created definition?

For example if you function to be called only with the definition `void foo(int, int)` but not with other types you can:

- Delete the other options though templates

```cpp
void foo(int a, int b) {
// whatever
}
template <typename T1, typename T2>
void foo(T1 a, T2 b) = delete;
```

- Or without the delete by simply

```cpp
template <class T, class U>
void foo(T arg1, U arg2);

template <>
void foo(int arg1, int arg2)
{
    //...
}
```

---

:mortar_board: To improve my C++ knowledge I took the Udemy Course - Learn Advanced C++ Programming and here are some of the exercises implementations.
