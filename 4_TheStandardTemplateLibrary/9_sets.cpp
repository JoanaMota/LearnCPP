#include <iostream>
#include <set>

class CTest
{
private:
    int m_id;
    std::string m_name;

public:
    // Default Constructor
    CTest() : m_id(0), m_name("")
    {
    }
    CTest(int f_id, std::string f_name) : m_id(f_id), m_name(f_name)
    {
    }
    void print(void) const
    {
        std::cout << m_id << ": " << m_name << std::endl;
    }

    // This is needed because the for loop compares the iterator
    // using the < sign but it does not know what to do
    bool operator<(const CTest &f_test) const
    {
        return (this->m_id < f_test.m_id);
    }
};

int main()
{
    std::set<int> numbers;

    numbers.insert(50);
    numbers.insert(40);
    numbers.insert(10);
    numbers.insert(10); // only stores a unique set ov values so this is not added
    numbers.insert(5);

    for (std::set<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    std::set<int>::iterator indexFind = numbers.find(100);
    if (indexFind != numbers.end())
    {
        std::cout << "Found: " << *indexFind << std::endl;
    }
    else
    {
        std::cout << "Not Found." << std::endl;
    }
    // OR
    if (numbers.count(40))
    {
        std::cout << "Number Found" << std::endl;
    }
    else
    {
        std::cout << "Not Found." << std::endl;
    }

    std::set<CTest> tests;
    tests.insert(CTest(10, "Joana"));
    tests.insert(CTest(3, "Joana"));
    tests.insert(CTest(20, "Miguel"));
    tests.insert(CTest(20, "Ricardo")); // This will not be inserted
    tests.insert(CTest(50, "Sara"));

    for (std::set<CTest>::iterator it = tests.begin(); it != tests.end(); it++)
    {
        // The iterator return an CTest object that is const
        // so we have to make sure that the method called with
        // the iterator is also const
        it->print();
    }
    return 0;
}
