#include <iostream>
#include <assert.h>

template <class T>
class CCalculator
{
private:
    T m_num1;
    T m_num2;

public:
    CCalculator(T f_num1, T f_num2)
    {
        m_num1 = f_num1;
        m_num2 = f_num2;
    }
    ~CCalculator(){};

    inline void display()
    {
        std::cout << "Values are " << m_num1 << " and " << m_num2 << std::endl;
        std::cout << "Addition is " << add() << std::endl;
        std::cout << "Subtraction is " << sub() << std::endl;
        std::cout << "Product is " << prod() << std::endl;
        std::cout << "Division is " << div() << std::endl;
    }
    T add(void)
    {
        return m_num1 + m_num2;
    }
    T sub(void)
    {
        return m_num1 - m_num2;
    }
    T prod(void)
    {
        return m_num1 * m_num2;
    }
    T div(void)
    {
        assert(0 != m_num2); // Control for devision by zero
        return m_num1 / m_num2;
    }
};

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

    CCalculator<int> c1(4, 20);
    CCalculator<float> c2(4.5, 20.8);
    CCalculator<float> c3(4, 0);
    std::cout << "---Calculator int 1---" << std::endl;
    c1.display();
    std::cout << "---Calculator float 2---" << std::endl;
    c2.display();
    std::cout << "---Calculator float 3---" << std::endl;
    c3.display();

    return 0;
}