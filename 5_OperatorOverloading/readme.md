# Operator Overloading
## Overloading the Assignment Operator `=`

``` cpp
const CTest &operator=(const CTest &f_other)
{
    m_id = f_other.m_id;
    m_name = f_other.m_name;
    return *this;
}
```

`f_other` : Reference to the other object, it must be const to prevent the method from changing the input arg.

`return` : Reference to the object that is being called on.

`test2 = test1` - Calls the assignment operator overload

`test3.operator=(test2)` - Calls the assignment operator overload

`CTest test4 = test1` - Calls the copy constructor

### Different types os Constructors:

``` cpp
///@brief Default Constructor
CTest() : m_id(0), m_name(""){}

///@brief Parameterized Constructor
CTest(int f_id, std::string f_name) : m_id(f_id), m_name(f_name){}

///@brief Copy Constructor
CTest(const CTest &f_other)
{
    m_id = f_other.m_id;
    m_name = f_other.m_name;
}
```

> Bare in mind that if one of the following is required make sure to implement the 2 others:
> - Assignment operator overloading
> - Copy Constructor
> - Destructor

**Expected Output**
```
Printing test1  10 : Mike
Parameterized Constructor
Executing Assignment
Printing test2  10 : Mike
Default Constructor
Executing Assignment
Printing test3  10 : Mike

Copy Constructor
Printing test4  10 : Mike
Destructor
Destructor
Destructor
Destructor
```
