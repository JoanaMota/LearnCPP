#include <iostream>

class CTest
{
private:
    int m_id;
    std::string m_name;

public:
    ///@brief Default Constructor
    CTest() : m_id(0), m_name("") {}
    ///@brief Parameterized Constructor
    CTest(int f_id, std::string f_name) : m_id(f_id), m_name(f_name) {}
    ///@brief Copy Constructor
    CTest(const CTest &f_other)
    {
        m_id = f_other.m_id;
        m_name = f_other.m_name;
    }
    ~CTest() {}
    void print(void)
    {
        std::cout << m_id << " : " << m_name << std::endl;
    }

    ///@brief Left Bif Shift Operator Overloading
    ///@param f_out reference to the object from std::cout
    ///@param f_test reference to the input object
    ///@return a reference to an ostream object
    friend std::ostream &operator<<(std::ostream &f_out, const CTest &f_test);
};

std::ostream &operator<<(std::ostream &f_out, const CTest &f_test)
{
    f_out << f_test.m_id << " : " << f_test.m_name; // we dont put endl to enable the user to add it afterwards
    return f_out;
}

int main(int argc, char const *argv[])
{
    CTest test1(10, "Mike");
    CTest test2(20, "Bob");
    test1.print();

    std::cout << test1 << std::endl;
    std::cout << test2 << std::endl;

    return 0;
}
