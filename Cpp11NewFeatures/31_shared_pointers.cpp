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

int main()
{
    std::shared_ptr<CTest> pTest3(nullptr);

    std::shared_ptr<CTest> pTest1(new CTest(1));
    pTest1->greet();
    {
        std::shared_ptr<CTest> pTest2 = std::make_shared<CTest>(2);
        pTest2->greet();
        pTest3 = pTest2;
    } // pTest2 before was destructed here when it gets out of scope.

    std::cout << "Right before return" << std::endl;
    return 0;
} // pTest1 is destructed here and now also pTest2 because pTest3 is only destructed here