#include <iostream>
#include <memory.h>
#include <vector>

class CTest
{
private:
    static const int SIZE = 100;
    int *m_pBuffer{nullptr};

public:
    ///@brief Default Constructor
    CTest()
    {
        std::cout << "Default Constructor" << std::endl;
        m_pBuffer = new int[SIZE]{}; // initialize all to zero
        // other way to initialize m_pBuffer:
        // memset(m_pBuffer, 0, sizeof(int) * SIZE);
    }
    ///@brief Copy Constructor
    CTest(const CTest &f_other)
    {
        std::cout << "Copy Constructor" << std::endl;
        m_pBuffer = new int[SIZE]{}; // initialize all to zero
        memcpy(m_pBuffer, f_other.m_pBuffer, SIZE * sizeof(int));
    }
    ///@brief Move Constructor
    CTest(CTest &&f_other)
    {
        std::cout << "Move Constructor" << std::endl;
        m_pBuffer = f_other.m_pBuffer;
        // We need to pass it to null pointer since it is going to be deleted on the Destructor
        f_other.m_pBuffer = nullptr;
    }
    ///@brief Assignment operator overload
    const CTest &operator=(const CTest &f_other)
    {
        std::cout << "Executing Assignment" << std::endl;
        memcpy(m_pBuffer, f_other.m_pBuffer, SIZE * sizeof(int));
        return *this;
    }
    ///@brief Move Assignment operator overload
    const CTest &operator=(CTest &&f_other)
    {
        std::cout << "Executing Move Assignment" << std::endl;
        delete[] m_pBuffer;
        m_pBuffer = f_other.m_pBuffer;
        f_other.m_pBuffer = nullptr;
        return *this;
    }
    ~CTest()
    {
        std::cout << "Destructor" << std::endl;
        if (m_pBuffer == nullptr)
            return;

        delete[] m_pBuffer;
    }
};

int main()
{
    std::vector<CTest> vec;
    std::cout << "--Push back" << std::endl;
    vec.push_back(CTest()); // Now it calles the Move Constructor instead of the Copy Constructor

    std::cout << "---" << std::endl;
    CTest test;
    test = CTest();
    return 0;
}