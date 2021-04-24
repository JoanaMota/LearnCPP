#include <iostream>
#include <memory.h>

class CTest
{
private:
    static const int SIZE = 100;
    int *m_pBuffer;

public:
    ///@brief Default Constructor
    CTest()
    {
        std::cout << "Default Constructor" << std::endl;
        m_pBuffer = new int[SIZE]{}; // initialize all to zero
        // other way to initialize m_pBuffer:
        // memset(m_pBuffer, 0, sizeof(int) * SIZE);
    }
    ///@brief Parameterized Constructor
    CTest(int f_i)
    {
        std::cout << "Parameterized Constructor" << std::endl;
        m_pBuffer = new int[SIZE]{}; // initialize all to zero
        for (int i = 0; i < SIZE; i++)
        {
            m_pBuffer[i] = 7 * i;
        }
    }
    ///@brief Copy Constructor
    CTest(const CTest &f_other)
    {
        std::cout << "Copy Constructor" << std::endl;
        memcpy(m_pBuffer, f_other.m_pBuffer, SIZE * sizeof(int));
    }
    ///@brief Assignment operator overload
    const CTest &operator=(const CTest &f_other)
    {
        std::cout << "Executing Assignment" << std::endl;
        memcpy(m_pBuffer, f_other.m_pBuffer, SIZE * sizeof(int));
        return *this;
    }
    ~CTest()
    {
        std::cout << "Destructor" << std::endl;
        delete[] m_pBuffer;
    }
    friend std::ostream &operator<<(std::ostream &f_out, const CTest &f_test);
};

std::ostream &operator<<(std::ostream &f_out, const CTest &f_test)
{
    f_out << "Hello from Test"; // we dont put endl to enable the user to add it afterwards
    return f_out;
}

int test()
{
    return 2;
}
CTest testClass()
{
    return CTest();
}

void check(const CTest &value)
{
    std::cout << "LValue function!" << std::endl;
}
void check(CTest &&value)
{
    std::cout << "RValue function!" << std::endl;
}

int main()
{
    int value = 7;

    int *pValue1 = &value; // value is an LValue because you an take its address
    // int *pValue2 = &7; // DOES NOT WORK because 7 is an RValue

    int *pValue3 = &++value; // prefix increment operator
    std::cout << *pValue3 << std::endl;
    // int *pValue4 = &value++; // posfix increment operator.
    // DOES NOT WORK because he needs to use the value and then increment
    // it so it has to create a temporary copy of the value

    // int *s = (7 + value); // DOES NOT WORK

    CTest test1;

    CTest *pTest2 = &test1; // test1 is an LValue

    CTest &rTest1 = test1; //LValue Reference which is a simple reference

    // int *pTest2 = &test();        // DOES NOT WORK because a function returns an RValue
    // CTest *pTest3 = &testClass(); // DOES NOT WORK because a function returns an RValue
    const CTest &rTest2 = testClass();

    // This also works
    CTest test2(CTest(2));
    // So CTest(2) returns an RValue
    // Then when we initialize the test2 we use the copy constructor which accepts as input a const object
    // so he is able to bind an RValue (from CTest(2)) to an LValue reference

    // Reverence to an RValue
    CTest &&rTest3 = CTest();

    check(test1);       // LValue function!
    check(testClass()); // RValue function!
    check(CTest());     // RValue function!

    return 0;
}