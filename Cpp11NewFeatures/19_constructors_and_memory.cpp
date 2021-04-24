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