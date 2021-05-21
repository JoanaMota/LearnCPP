#include <iostream>
#include <memory>

class CTest
{
private:
    int m_id;

public:
    CTest(int id) : m_id{id}
    {
        std::cout << "Constructing " << m_id << std::endl;
    }
    ~CTest()
    {
        std::cout << "Destructing " << m_id << std::endl;
    }
    void greet()
    {
        std::cout << "Hello " << m_id << std::endl;
    }
};

class CTemp
{
private:
    std::unique_ptr<CTest> pTest;

public:
    CTemp() : pTest(new CTest(55)) // pTest55 is constructed here
    {
        std::cout << "Constructing Temp" << std::endl;
    }
    ~CTemp()
    {
        std::cout << "Destructing Temp" << std::endl;
    } // pTest55 is destructed here
};

int main()
{
    CTest *t = new CTest(0);

    std::unique_ptr<int> test(new int);
    *test = 7; // Dereference test
    std::cout << *test << std::endl;

    std::unique_ptr<CTest> pTest1(new CTest(1));
    pTest1->greet();
    {
        std::unique_ptr<CTest> pTest2(new CTest(2));
        pTest2->greet();
    } // pTest2 is destructed here

    CTemp temp;

    delete t;
    std::cout << "Right before return" << std::endl;
    return 0;
} // pTest1, temp and pTest55 are destructed here