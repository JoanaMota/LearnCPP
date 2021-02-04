#include <iostream>

class CTest
{
private:
    int m_id;
    std::string m_name;

public:
    ///@brief Default Constructor
    CTest() : m_id(0), m_name("")
    {
        std::cout << "Default Constructor" << std::endl;
    }
    ///@brief Parameterized Constructor
    CTest(int f_id, std::string f_name) : m_id(f_id), m_name(f_name)
    {
        std::cout << "Parameterized Constructor" << std::endl;
    }
    ///@brief Copy Constructor
    CTest(const CTest &f_other)
    {
        std::cout << "Copy Constructor" << std::endl;
        m_id = f_other.m_id;
        m_name = f_other.m_name;
    }
    ~CTest()
    {
        std::cout << "Destructor" << std::endl;
    }
    void print(void)
    {
        std::cout << m_id << " : " << m_name << std::endl;
    }
    ///@brief Assignment operator overload
    ///@param f_other Reference to the other object, it must be const
    /// to forbide the method from changing this input arg
    ///@return Reference to the object that is being called on
    const CTest &operator=(const CTest &f_other)
    {
        std::cout << "Executing Assignment" << std::endl;
        m_id = f_other.m_id;
        m_name = f_other.m_name;

        return *this;
    }
};

int main()
{
    CTest test1(10, "Mike");
    std::cout << "Printing test1  " << std::flush;
    test1.print();

    CTest test2(20, "Bob");
    test2 = test1; // Shallow copy, copying all the values from obj1 to obj2
    std::cout << "Printing test2  " << std::flush;
    test2.print();

    CTest test3;
    // test3 = test2 = test1;   // We can think of this as:
    // calling a method on test2 and passing test1 as argument
    // which returns a reference to test2
    // which is then used as an argument passed to the method
    // applied on test3

    test3.operator=(test2); // same as above
    std::cout << "Printing test3  " << std::flush;
    test3.print();

    std::cout << std::endl;

    CTest test4 = test1; // Copy initialization it calls the implicit copy constructor or if one exists
                         // It does not use the assignment operator
    std::cout << "Printing test4  " << std::flush;
    test4.print();

    return 0;
}