#include <iostream>

template <class T, class K>
class CTest
{
private:
    T m_obj;

public:
    CTest(T f_obj)
    {
        m_obj = f_obj;
    }
    ~CTest(){};

    inline void print()
    {
        std::cout << m_obj << std::endl;
    }
};

int main()
{
    CTest<std::string, int> test1("Hello World");
    test1.print();
    return 0;
}