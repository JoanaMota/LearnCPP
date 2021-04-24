#include <iostream>

class CTest
{

public:
    ///@brief Default Constructor
    CTest()
    {
        std::cout << "Default Constructor" << std::endl;
    }
    ///@brief Parameterized Constructor
    CTest(int f_i)
    {
        std::cout << "Parameterized Constructor" << std::endl;
    }
    ///@brief Copy Constructor
    CTest(const CTest &f_other)
    {
        std::cout << "Copy Constructor" << std::endl;
    }
    ///@brief Assignment operator overload
    const CTest &operator=(const CTest &f_other)
    {
        std::cout << "Executing Assignment" << std::endl;
        return *this;
    }
    ~CTest()
    {
        std::cout << "Destructor" << std::endl;
    }
    friend std::ostream &operator<<(std::ostream &f_out, const CTest &f_test);
};

std::ostream &operator<<(std::ostream &f_out, const CTest &f_test)
{
    f_out << "Hello from Test"; // we dont put endl to enable the user to add it afterwards
    return f_out;
}

CTest getTest()
{
    return CTest();
}

int main()
{
    CTest test1 = getTest();
    std::cout << test1 << std::endl;
    return 0;
}